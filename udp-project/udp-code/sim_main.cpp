#include "Vudp.h"            // Verilator-generated header for the udp module
#include "verilated_vcd_c.h" // Include Verilator's VCD tracing library
#include <iostream>
#include <memory>
#include <vector>
#include <verilated.h>

// Define a helper structure for a single packet
struct AxiStreamPacket {
  uint16_t data; // Data word (16 bits)
  bool last;     // Indicates the last word of the packet
};

// Testbench Class
class UdpTestbench {
public:
  // DUT instance
  std::unique_ptr<Vudp> dut;
  VerilatedVcdC *tfp = nullptr; // Trace file pointer

  // Simulation time
  vluint64_t main_time = 0;

  // Input and output arrays
  std::vector<AxiStreamPacket> input_array;
  std::vector<AxiStreamPacket> output_array;

  // Constructor
  UdpTestbench(size_t N) {
    Verilated::traceEverOn(true); // Enable tracing
    dut = std::make_unique<Vudp>();
    initialize_signals();

    // Generate input array
    generate_input_array(N);

    // Initialize the trace file
    tfp = new VerilatedVcdC;
    dut->trace(tfp, 99); // Trace all signals (max depth 99)
    tfp->open("waveform.vcd");
  }

  // Destructor
  ~UdpTestbench() {
    if (tfp) {
      tfp->close(); // Close the trace file
      delete tfp;
    }
    dut->final();
  }

  // Run the test
  void run() {
    reset();           // Perform reset
    send_array();      // Send the entire input array
    receive_array();   // Receive the entire output array
    validate_result(); // Validate the results
    reset();
    send_array();
    receive_array();
    validate_result();
  }

private:
  // Initialize DUT signals
  void initialize_signals() {
    dut->clk = 0;
    dut->r_valid = 0;
    dut->r_last = 0;
    dut->r_data = 0;
    dut->t_ready = 0;
    if (tfp)
      tfp->dump(main_time); // Dump initial state
  }

  // Perform reset
  void reset() {
    dut->clk = 0;
    dut->r_valid = 0;
    dut->r_last = 0;
    dut->r_data = 0;
    dut->t_ready = 0;
    output_array.clear();
    dut->reset = 1;
    for (int i = 0; i < 5; ++i) {
      step();
    }
  }

  // Generate input array
  void generate_input_array(size_t N) {
    input_array.clear();
    for (size_t i = 0; i < N; ++i) {
      input_array.push_back({static_cast<uint16_t>(0x1000 + i), i == N - 1});
    }
    std::cout << "Generated input array of length " << N << "." << std::endl;
  }

  // Send the entire input array
  void send_array() {
    std::cout << "Sending array..." << std::endl;

    for (const auto &packet : input_array) {
      // Assign packet data to DUT inputs
      start_step();
      dut->r_data = packet.data;
      dut->r_valid = 1;
      dut->r_last = packet.last;
      end_step();
      // Wait for DUT to assert r_ready
      do {
        step();
      } while (!dut->r_ready);

      // De-assert r_valid after sending
      start_step();
      dut->r_valid = 0;
      end_step();
    }
  }

  // Receive the entire output array
  void receive_array() {
    std::cout << "Receiving array..." << std::endl;

    while (output_array.size() < input_array.size()) {
      start_step();

      if (dut->t_valid && dut->t_ready) {
        // Capture the received packet data
        AxiStreamPacket received_packet;
        received_packet.data = dut->t_data;
        received_packet.last = dut->t_last;

        // Store the received packet in the output array
        output_array.push_back(received_packet);

        dut->t_ready = 0;

      } else if (dut->t_valid) {
        dut->t_ready = 1;
      }
      end_step();
    }
  }

  // Validate the results
  void validate_result() {
    std::cout << "Validating results..." << std::endl;

    if (input_array.size() != output_array.size()) {
      std::cout << "Test Failed: Array length mismatch!" << std::endl;
      return;
    }

    for (size_t i = 0; i < input_array.size(); ++i) {
      if (input_array[i].data != output_array[i].data ||
          input_array[i].last != output_array[i].last) {
        std::cout << "Test Failed: Mismatch at index " << i << "." << std::endl;
        std::cerr << "Sent:     Data=0x" << std::hex << input_array[i].data
                  << ", Last=" << input_array[i].last << std::endl;
        std::cerr << "Received: Data=0x" << std::hex << output_array[i].data
                  << ", Last=" << output_array[i].last << std::endl;
        return;
      }
    }

    std::cout << "Test Passed: All packets match!" << std::endl;
  }

  void step() {
    start_step();
    end_step();
  }

  // Simulate a single clock cycle
  void start_step() {
    // Print the current step number
    std::cout << "Clock step: " << main_time / 2 << std::endl;

    // Exit simulation if the clock cycles exceed 100
    if (main_time / 2 > 100) {
      std::cerr << "Error: Exceeded 100 clock cycles. Exiting simulation."
                << std::endl;
      if (tfp)
        tfp->close(); // Ensure trace file is closed
      std::exit(1);   // Exit with an error status
    }

    // Perform the clock low-to-high transition
    dut->clk = 0;
    evaluate();
    main_time++;
    if (tfp)
      tfp->dump(main_time); // Dump signal states after clk=0
  }
  void end_step() {
    dut->clk = 1;
    evaluate();
    main_time++;
    if (tfp)
      tfp->dump(main_time); // Dump signal states after clk=1
  }

  // Evaluate DUT
  void evaluate() { dut->eval(); }
};

// Main Function
int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv); // Initialize Verilator

  // Define the array size (N)
  size_t N = 4; // Example: Array of 4 elements

  // Instantiate and run the testbench
  UdpTestbench tb(N);
  tb.run();

  return 0;
}

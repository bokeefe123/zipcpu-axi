# Makefile for Verilator Counter Simulation

# Top-level Verilog module (without .v extension)
TOP_MODULE = udp

# Source files
VERILOG_SOURCES = $(TOP_MODULE).v
CPP_SOURCES = sim_main.cpp

# Verilator flags
VERILATOR_FLAGS = --cc --trace

# Build directory
BUILD_DIR = obj_dir

# Simulation executable
SIM_EXE = $(BUILD_DIR)/V$(TOP_MODULE)

.PHONY: all run clean

# Default target: build and run
all: $(SIM_EXE)
	@echo "Running simulation..."
	$(SIM_EXE)

# Rule to build the simulation executable
$(SIM_EXE): $(VERILOG_SOURCES) $(CPP_SOURCES)
	verilator $(VERILATOR_FLAGS) $(VERILOG_SOURCES) --exe $(CPP_SOURCES)
	make -j -C $(BUILD_DIR) -f V$(TOP_MODULE).mk V$(TOP_MODULE)

# Run the simulation
run: $(SIM_EXE)
	@echo "Running simulation..."
	$(SIM_EXE)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) waveform.vcd

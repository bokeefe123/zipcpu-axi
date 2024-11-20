# Makefile for Verilator Hello World Example

# Top-level Verilog module name (without .v extension)
TOP_MODULE = hello_world

# Source files
VERILOG_SOURCES = $(TOP_MODULE).v
CPP_SOURCES = sim_main.cpp

# Verilator flags
VERILATOR_FLAGS = --cc

# Build directory
BUILD_DIR = obj_dir

# Simulation executable name
SIM_EXE = $(BUILD_DIR)/V$(TOP_MODULE)

.PHONY: all run clean

# Default target: build and run the simulation
all: $(SIM_EXE)
	$(SIM_EXE)

# Rule to build the simulation executable
$(SIM_EXE): $(VERILOG_SOURCES) $(CPP_SOURCES)
	verilator $(VERILATOR_FLAGS) $(VERILOG_SOURCES) --exe $(CPP_SOURCES)
	make -j -C $(BUILD_DIR) -f V$(TOP_MODULE).mk V$(TOP_MODULE)

# Run the simulation (after building)
run: $(SIM_EXE)
	$(SIM_EXE)

# Clean up build files
clean:
	rm -rf $(BUILD_DIR)

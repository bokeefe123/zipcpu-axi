# ----------------------------------------
# Jasper Version Info
# tool      : Jasper 2023.12
# platform  : Linux 4.18.0-553.32.1.el8_10.x86_64
# version   : 2023.12p001 64 bits
# build date: 2024.01.23 16:09:24 UTC
# ----------------------------------------
# started   : 2024-12-18 15:56:35 PST
# hostname  : caddy11.stanford.edu.(none)
# pid       : 39987
# arguments : '-label' 'session_0' '-console' '//127.0.0.1:45207' '-style' 'windows' '-data' 'AAAA3nicVY6xCsJAEETfKfYp/YaAEoSARYo0dkpQwTZItBBCEkxEsDGf6p+ccwkpbpad2V1uuDFA8rXWMmD+EQXsOXBiJ864SGFJzIYtESkFV26UPDRFo8/8RiUx+HD7zL8ce09hMZmnJ84QstI/parmTc6LilbcqGqedNyVIlfC85DZ7a14rS7kcvgD8wMZTQ==' '-proj' '/home/users/bokeefe/verilog/zipcpu-axi/udp-project/udp-code/jgproject/sessionLogs/session_0' '-init' '-hidden' '/home/users/bokeefe/verilog/zipcpu-axi/udp-project/udp-code/jgproject/.tmp/.initCmds.tcl' 'test.tcl'
# Run JG with a TCl file: jg foo.tcl
# To get help about the tcl command syntax
# use the help command "help" at the JG console
# This will list an overview of all commands.
# To get details about individual command use
# help in combination with the command name and its options.
# For example "help assert"

# Clear previous run
clear -all

# Analyze RTL files
analyze -sv -f Flist.udp

# Elaborate
elaborate

# Initialization
# Clock specification
# clock pin is called "clk"
# duty cycle is 1:1 by default
clock clk

# Define reset condition
# reset pin is called rst_n, active low

reset rst

# Start the verification
prove -all

report -summary -results -file jg_summary.txt -force
visualize -violation -property <embedded>::udp.offset_out_bounded -new_window

#!/bin/bash

# Start OpenOCD in the background
nohup sudo openocd -f /usr/share/openocd/scripts/board/st_nucleo_f4.cfg > openocd.out 2> openocd.err < /dev/null &

# Wait for OpenOCD to be fully initialized
sleep 5

# Check if OpenOCD is running
jobs -p | grep -q `pgrep -f "openocd"`
if [ $? -eq 0 ]; then
    # Start GDB
    gdb -ex "target remote :3333" -ex "load build/Release/source/Etna.elf" -ex "verify" -ex "continue"
else
    echo "Error: OpenOCD is not running"
    exit 1
fi

# Kill OpenOCD
pkill -f "openocd"


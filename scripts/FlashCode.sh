#!/bin/bash

echo "target extended-remote /dev/ttyUSB0" > gdb.init
echo "monitor reset halt" >> gdb.init
echo "load path/to/firmware.elf" >> gdb.init
echo "monitor reset" >> gdb.init
echo "quit" >> gdb.init
gdb -x gdb.init


#openocd -f /usr/share/openocd/scripts/board/st_nucleo_f4.cfg -c "init;reset halt;flash write_image erase Etna.elf;reset run;shutdown"

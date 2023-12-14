#!/bin/bash
echo "----------------------------------------------------------------------------"


export forte_bin_dir="bin/esp32"
export forte_dir="org.eclipse.4diac.forte"

#call esp-idf
. $HOME/esp-idf-v5.1.1/export.sh

#rm old folder
cd "./$forte_dir"
rm -r "./$forte_bin_dir"

#call setup_esp32.sh
./setup_esp32.sh

#goto new Directory
cd "./$forte_bin_dir"

#make
make -j

cp ./src/libforte-static.a ../../../Application/components/4diac-forte-esp32-component/lib/esp32/src

#go back
cd ../../../Application
idf.py build

echo "----------------------------------------------------------------------------"
echo " DONE. to flash type:"
echo "cd Application"
echo "idf.py flash monitor" 
echo "----------------------------------------------------------------------------"


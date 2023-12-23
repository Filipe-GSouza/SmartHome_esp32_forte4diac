#!/bin/bash
echo "----------------------------------------------------------------------------"


export forte_bin_dir="bin/esp32s3"
export forte_dir="org.eclipse.4diac.forte"

#call esp-idf
. $HOME/esp/esp-idf/export.sh

#rm old folder
cd "./$forte_dir"
rm -r "./$forte_bin_dir"

#call setup_esp32s3.sh
./setup_esp32s3.sh

#goto new Directory
cd "./$forte_bin_dir"

#make
make -j

cp ./src/libforte-static.a ../../../Application/components/4diac-forte-esp32-component/lib/esp32s3/src

#go back
cd ../../../Application
idf.py build

echo "----------------------------------------------------------------------------"
echo " DONE. to flash type:"
echo "cd Application"
echo "idf.py flash monitor" 
echo "----------------------------------------------------------------------------"


# Install script for directory: /home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/src/modules

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "MINSIZEREL")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/home/filipe/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/PLC01A1/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/PLCnext/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/ads/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/arrowhead/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/conmeleon_c1/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/convert/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/datapanel/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/embrick/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/esp-addons/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/esp32/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/esp32io/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/i2c_dev/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/lms_ev3/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/mlpi/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/odroid/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/piface/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/raspberry_sps/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/reconfiguration/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/rt_events/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/signalprocessing/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/sysfs/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/umic/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/utils/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/wagokbus/cmake_install.cmake")

endif()


# Install script for directory: /home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/src/modules/IEC61131-3/Conversion

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
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/BOOL/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/BYTE/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/DINT/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/DWORD/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/INT/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/SINT/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/STRING/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/TIME/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/UDINT/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/UINT/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/USINT/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/WORD/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/BCD/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/WSTRING/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/REAL/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/LREAL/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/ULINT/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/LWORD/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/LINT/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/IEC61131-3/Conversion/DT/cmake_install.cmake")

endif()


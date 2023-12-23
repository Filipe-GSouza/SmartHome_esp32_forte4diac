# Install script for directory: /home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/src

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE STATIC_LIBRARY FILES "/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/libforte-static.a")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/arch/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/core/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/modules/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/com/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/external/ESPIO/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/external/TESTE/cmake_install.cmake")
  include("/home/filipe/Projetos/TCC_4DiacForte_ESP32S3/org.eclipse.4diac.forte/bin/esp32s3/src/stdfblib/cmake_install.cmake")

endif()


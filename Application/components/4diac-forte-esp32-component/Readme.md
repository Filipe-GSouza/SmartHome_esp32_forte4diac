## Overview
4diac Forte is an open source PLC runtime framework based on IEC 61499 standard. This how-to describes how to run it on esp32 or esp32s2 mcu.  For more details about 4diac forte please visit. https://www.eclipse.org/4diac/en_rte.php. 
### Requirements
- linux operating system - ubuntu/debian/arch
- Visual Studio code with espressiff plugin for esp32 chips support
- ESP-IDF - should be installed by vs code plugin 
- cmake and cmake-gui
- make
- git


**Also it is assumed that user has basic knowledge about C/C++ programming, esp32 platform and required toolchains.**


It is good to test all nessecery tools before proced this instruction.

## Prepare forte component for ESP32
###Forte static library

First clone latest 4diac forte repository:

`$ git clone https://git.eclipse.org/r/4diac/org.eclipse.4diac.forte.git`

It is important to have it in some accesible place so we can easly come back to it. For propose of this text, `/home/arek/Projekty/` has been used.  In next step in forte root folder create build directory and launch cmake gui tool. 

It can be done via terminal commad

`$ cmake-gui`

![](https://gitlab.com/amid123/4diac-forte-esp32-component/-/raw/main/docs/pics/cmake_sel_src_and_build.png)

In Cmake tool, select path to forte project, and to build folder that was proviously prepared. Click "Configure" button and new window will appear with configuration wizard. 

In new window, select Specify options for cross-compiling and click next
![](https://gitlab.com/amid123/4diac-forte-esp32-component/-/raw/main/docs/pics/cmake_wizard1.png
)

In next window you have to select gcc and g++ compilers for xtensa atchitecture. 
Set operating system to Generic, Processor to esp32 or esp32s2.

![](https://gitlab.com/amid123/4diac-forte-esp32-component/-/raw/main/docs/pics/cmake_cross_gcc_cfg.png)

After all click finish. In current state there is an error notification from cmake, because `FORTE_ARCHITECTURE` parameter hasn't been selected yet. 

![](https://gitlab.com/amid123/4diac-forte-esp32-component/-/raw/main/docs/pics/cmake_err.png)

For esp32 we have to select `FreeRTOSLwIP` from drop down list. Now when click configure, most errors should dissapear. There will be only few parameters marked with red. Now there is a time to fillup include dependencies for freertos.  Parameter `FORTE_FreeRTOSLwIP_INCLUDES` has to be set. It takes string with semicolon separated paths to include folders in esp-idf. There is quite a lot of paths that have to be added as include paths. Below there is a working configuration, please note that all of those paths are **absolue** so you need to modify all of them. In most cases it should be enought to repleace all occurrences of `/home/arek/Projekty/esp32-idf/esp-idf` with your ESP-IDF root directory path. For example with `/home/my_user/my_projects/my-idf_path`.

	/home/arek/Projekty/esp32-idf/esp-idf/components/freertos/include/esp_additions/freertos;/home/arek/Projekty/esp32-idf/esp-idf/components/freertos/include/freertos;/home/arek/Projekty/esp32-idf/esp-idf/examples/wifi/getting_started/station/build/config;/home/arek/Projekty/esp32-idf/esp-idf/components/esp_common/include;/home/arek/Projekty/esp32-idf/esp-idf/components/freertos/port/xtensa/include;/home/arek/Projekty/esp32-idf/esp-idf/components/xtensa/include;/home/arek/Projekty/esp32-idf/esp-idf/components/lwip/lwip/src;/home/arek/Projekty/esp32-idf/esp-idf/components/xtensa;/home/arek/Projekty/esp32-idf/esp-idf/components/xtensa/esp32/include;/home/arek/Projekty/esp32-idf/esp-idf/components/esp_rom/include;/home/arek/Projekty/esp32-idf/esp-idf/components/esp_rom/include/linux;/home/arek/Projekty/esp32-idf/esp-idf/components/esp_hw_support/include;/home/arek/Projekty/esp32-idf/esp-idf/components/hal/include;/home/arek/Projekty/esp32-idf/esp-idf/components/lwip/lwip/src/include;/home/arek/Projekty/esp32-idf/esp-idf/components/soc/esp32/include;/home/arek/Projekty/esp32-idf/esp-idf/components/lwip/port/esp32/include;/home/arek/Projekty/esp32-idf/esp-idf/components/hal/esp32/include;/home/arek/Projekty/esp32-idf/esp-idf/components/soc/include;/home/arek/Projekty/esp32-idf/esp-idf/components/esp_system/include;/home/arek/Projekty/esp32-idf/esp-idf/components/esp_timer/include;/home/arek/Projekty/esp32-idf/esp-idf/components/newlib/platform_include;/home/arek/Projekty/esp32-idf/esp-idf/components/heap/include;/home/arek/Projekty/esp32-idf/esp-idf/components/freertos/include;/home/arek/Projekty/esp32-idf/esp-idf/components/freertos/include/esp_additions

Once you have filed freertos includes you have add few additional compiler flags. To do this you need to activate `advanced` checkbox in upper right corner of cmake program. Once you have it, you will be able to see much more options that you can tweak.

Flags that you have to add:
`-mlongcalls -ffunction-sections -fdata-sections -fno-threadsafe-statics -fno-rtti -fno-exceptions -DconfigMINIMAL_STACK_SIZE_FORTE=15000`

All of them have to be added to all variants of `CMAKE_C_FLAGS` and `CMAKE_CXX_FLAGS`. There are: `DEBUG, MINISIZEREL RELEASE, REALWITHDEBINFO`

It should looks similar to picture below.

![](https://gitlab.com/amid123/4diac-forte-esp32-component/-/raw/main/docs/pics/cmake_flags.png)

Next option to set is the `FORTE_TicksPerSecond` option to 100 instead of 1000. It is also visible in advanced mode. We also need to tell cmake that we want to build static library instead of execurable. To do this you have to deselect  `FORTE_BUILD_EXECUTABLE` and select `FORTE_BUILD_STATIC_LIBRARY`.  For first tests, it is good to enable debug feature in forte so we can see more logs. That is very usefull during first run so we can see that everything works as it should. To do this, in `CMAKE_BUILD_TYPE` type: DEBUG and switch `FORTE_LOGLEVEL` to `LOGDEBUG`. Unfortunetly `FORTE_LOGLEVEL` options automaticly switch back to `NOLOG` everytime we trigger configuration, so it's  important to remember about it when we do some changes and we expect to have logs.

 **Just to highlight changes that we have done here:
**
- `FORTE_ARCHITECTURE` set to `FreeRTOSLwIP`
- `FORTE_FreeRTOSLwIP_INCLUDES` fillup all FreeRTOS include paths
- `CMAKE_C_FLAGS`, `CMAKE_CXX_FLAGS` and their variations with  `DEBUG, MINISIZEREL RELEASE, REALWITHDEBINFO` - add compilers flags. 
- `FORTE_TicksPerSecond` set to 100
- `FORTE_BUILD_EXECUTABLE` deselect
- `FORTE_BUILD_STATIC_LIBRARY` select
- `FORTE_LOGLEVEL` set to `LOGDEBUG` 

At this point we can do the configuration and generation with cmake. But still we need to do some small change to forte code. Becasue esp-idf has it's own implementation of connect() function which wraps lwip_connect we need to comment out connect function definition from forte source. Other way we will get compilation errors saying that we have redefinition of this function. 
The change has to be done in file `${FORTE_ROOT}/src/arch/freeRTOS/sockhand.h`
The function `connect(int s, const struct sockaddr *name, socklen_t namelen) `has to be commented.

so we change this

	inline int connect(int s, const struct sockaddr *name, socklen_t namelen) {
	  return lwip_connect(s, name, namelen);
	}

to this

	//inline int connect(int s, const struct sockaddr *name, socklen_t namelen) {
	//  return lwip_connect(s, name, namelen);
	//}

Once you have changed this file, save it, close and we can try first forte compilation for esp32 platform. 
Go to `${FORTE_ROOT}/build/src` and type `make -j` your make tool should start doing all the jobs and as a result, after some small amount of time, you should have builded forte static library like on the picture below: 

![](https://gitlab.com/amid123/4diac-forte-esp32-component/-/raw/main/docs/pics/build_ok.png)

Now you can find your static library in `${FORTE_ROOT}/build/src` with name `libforte-static.a`. We will use this library to prepare our ESP component so it can be used directly in the esp project. 

The component is in **this** repository, you have to clone it into your `esp-idf/components` folder so it can be used in esp32 project.

Go to `esp-idf/components` folder and type:

`$ git clone https://gitlab.com/amid123/4diac-forte-esp32-component.git ` 

At this moment you can copy you static library to the forte component folder. There is also need to rename it to forte.a. It's good to make a symbolic link instead of hard copy of static library. To do this you can use ln command in your shell.  

`ln -s [soruce file] [destination file]`

for example: 
`ln -s /home/arek/Projekty/forte_lib/bin/freertos_stm/src/libforte-static.a /home/arek/Projekty/esp32-idf/esp-idf/components/forte/forte.a `

In this way you don't have to copy the library everytime you rebuild it. 


#Sample forte application

To test you forte buld, you need eighter prepare your sample aplication from scratch or use the one that has been already prepared. This how-to will not cover how to make new project from scratch, instead we will use here an already prepared example which can be cloned from git repository. 

Clone the git repository 

`$ git clone https://gitlab.com/arkadiusz.g/esp32-4diac-example-application.git`

Open your visual studio code, and load the 4diac example application project. If you have everything properly installed project should build without any issues. Once you build it, flash and turn on ESP-IDF Monitor device. 

Once it's done you should see your 4diac forte up and running. 

![](https://gitlab.com/amid123/4diac-forte-esp32-component/-/raw/main/docs/pics/vscode_running.png)

Now you can deploy your sample application. To build your sample application with forte please refer to forte documentation : [Step 1 - Use 4diac Locally (Blinking Tutorial)]( https://www.eclipse.org/4diac/en_help.php?helppage=html/4diacIDE/use4diacLocally.html")

If everything is done correctly you should succesfully deploy your application. Enjoy! 

![](https://gitlab.com/amid123/4diac-forte-esp32-component/-/raw/main/docs/pics/deploy.png)



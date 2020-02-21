cmake_minimum_required(VERSION 2.8.12)
project(Vowifi)

enable_language(C CXX)

add_definitions("-Wall -std=c++11 -fPIC")

# 判定当前的系统环境
message(STATUS "We are on a ${CMAKE_SYSTEM_NAME} system")
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
     add_definitions(-DTEST_LINUX)
endif()

#CMAKE_COMPILE_ENV 可选择x86_64 、armeabi-v7a-hard（arm32位） 、armeabi-v8a（arm 64位）
set(CMAKE_COMPILE_ENV "armeabi-v7a-hard")

#CMAKE_COMPILE_ABI 可选择x86_64 armeabi-v7a-hard armeabi-v8a
set(CMAKE_COMPILE_ABI "armeabi-v7a-hard")

#-----------------------------------------------------------------------------------
if(${CMAKE_SYSTEM_NAME} STREQUAL "x86_64")
SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_CXX_COMPILER g++)
else()
SET(CMAKE_C_COMPILER /media/psf/Home/Downloads/git/tool3/mk-build/platforms/custom/gcc-linaro-6.4.1-2017.11-x86_64_arm-linux-gnueabihf/prebuilt/linux-x86_64/bin/arm-linux-gnueabihf-gcc)
SET(CMAKE_CXX_COMPILER /media/psf/Home/Downloads/git/tool3/mk-build/platforms/custom/gcc-linaro-6.4.1-2017.11-x86_64_arm-linux-gnueabihf/prebuilt/linux-x86_64/bin/arm-linux-gnueabihf-g++)
SET(CMAKE_FIND_ROOT_PATH /media/psf/Home/Downloads/git/tool3/mk-build/platforms/custom/gcc-linaro-6.4.1-2017.11-x86_64_arm-linux-gnueabihf/prebuilt/linux-x86_64/arm-linux-gnueabihf/libc)
endif()
#-----------------------------------------------------------------------------------

# 未设置默认值, cmake .. -DCMAKE_INSTALL_PREFIX=./XXXXXX
set(CMAKE_INSTALL_PREFIX "install2")

# SDK 管理平台支持https协议，可以将开关打开。
#set(CMAKE_INSAtlLL_HTTPS, "https")

# SDK 管理平台支持zip压缩
set(CMAKE_INSTALL_ZIP "Zip")

add_definitions(-DRAPIDJSON_HAS_STDSTRING )

#---SDK 管理平台添加证书和校验方式控制宏，
if(${CMAKE_INSAtlLL_HTTPS} STREQUAL "https")
add_definitions(-DTMTC_SSL_TRANSPORT )
endif()

#---设备本身可以用命令进行压缩，即安装zip或者其他的压缩库 可以不加载第三方库(minizip)
#即注释掉 TMTC_ZIP_COMPRESS 控制宏
if(${CMAKE_INSTALL_ZIP} STREQUAL "Zip")
add_definitions(-DTMTC_ZIP_COMPRESS )
endif()

link_directories(third/juphoon/lib/${CMAKE_COMPILE_ABI} third/libcurl/lib/${CMAKE_COMPILE_ABI} third/nghttp2/lib/${CMAKE_COMPILE_ABI} third/openssl/lib/${CMAKE_COMPILE_ABI})

include_directories(
        inc
        third
        third/juphoon/include/mme
        third/juphoon/include/zos
        third/juphoon/include/service/rcs
        third/libcurl/inc
        third/rapidjson/inc
        third/minizip/inc)

add_executable(testDemo
        src/commFunc.cpp
        src/httpmsg.cpp
        src/jpAudioMng.cpp
        src/jpNetSDK.cpp
        src/jpsdk.cpp
        src/ping.cpp
        src/main.cpp)

target_link_libraries(testDemo pthread mtccommon_voice curl nghttp2 crypto ssl z)
#-----------------------------------------------------------------------------------
install(TARGETS testDemo RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}")
install(DIRECTORY third/juphoon/lib/${CMAKE_COMPILE_ABI} DESTINATION "${CMAKE_INSTALL_PREFIX}")
install(DIRECTORY third/libcurl/lib/${CMAKE_COMPILE_ABI} DESTINATION "${CMAKE_INSTALL_PREFIX}")

#SDK 管理平台支持https协议，
if(${CMAKE_INSAtlLL_HTTPS} STREQUAL "https")
install(DIRECTORY third/nghttp2/lib/${CMAKE_COMPILE_ABI} DESTINATION "${CMAKE_INSTALL_PREFIX}")
install(DIRECTORY third/openssl/lib/${CMAKE_COMPILE_ABI} DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()

if(${CMAKE_INSTALL_ZIP} STREQUAL "Zip")
install(DIRECTORY third/minizip/lib/${CMAKE_COMPILE_ABI} DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()

install(FILES script/run.sh DESTINATION "${CMAKE_INSTALL_PREFIX}")
install(FILES res/license.sign DESTINATION "${CMAKE_INSTALL_PREFIX}")
install(FILES res/test_eng_female.pcm DESTINATION "${CMAKE_INSTALL_PREFIX}")


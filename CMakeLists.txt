cmake_minimum_required(VERSION 2.8.12)
project(Vowifi)

add_definitions("-Wall -std=c++11 -fPIC")

SET(CMAKE_C_COMPILER /media/psf/Home/Downloads/git/tool3/mk-build/platforms/custom/gcc-linaro-6.4.1-2017.11-x86_64_arm-linux-gnueabihf/prebuilt/linux-x86_64/bin/arm-linux-gnueabihf-gcc)
SET(CMAKE_CXX_COMPILER /media/psf/Home/Downloads/git/tool3/mk-build/platforms/custom/gcc-linaro-6.4.1-2017.11-x86_64_arm-linux-gnueabihf/prebuilt/linux-x86_64/bin/arm-linux-gnueabihf-g++)
SET(CMAKE_FIND_ROOT_PATH /media/psf/Home/Downloads/git/tool3/mk-build/platforms/custom/gcc-linaro-6.4.1-2017.11-x86_64_arm-linux-gnueabihf/prebuilt/linux-x86_64/arm-linux-gnueabihf/libc)

set(CMAKE_INSTALL_PREFIX "bin")

add_definitions(-DRAPIDJSON_HAS_STDSTRING )
link_directories(third/juphoon/lib/armeabi-v7a-hard third/libcurl/lib/armeabi-v7a-hard third/nghttp2/lib/armeabi-v7a-hard third/openssl/lib/armeabi-v7a-hard)

include_directories(
        inc
        third
        third/juphoon/include/mme
        third/juphoon/include/zos
        third/juphoon/include/service/rcs
        third/libcurl/inc
        third/rapidjson/inc)

add_executable(testDemo
        src/commFunc.cpp
        src/httpmsg.cpp
        src/jpAudioMng.cpp
        src/jpNetSDK.cpp
        src/jpsdk.cpp
        src/ping.cpp
        src/main.cpp)

target_link_libraries(testDemo pthread mtccommon_voice curl nghttp2 crypto ssl z)

install(TARGETS testDemo RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}")
install(DIRECTORY third/juphoon/lib/armeabi-v7a-hard DESTINATION "${CMAKE_INSTALL_PREFIX}")
install(DIRECTORY third/libcurl/lib/armeabi-v7a-hard DESTINATION "${CMAKE_INSTALL_PREFIX}")
install(DIRECTORY third/nghttp2/lib/armeabi-v7a-hard DESTINATION "${CMAKE_INSTALL_PREFIX}")
install(DIRECTORY third/openssl/lib/armeabi-v7a-hard DESTINATION "${CMAKE_INSTALL_PREFIX}")
install(FILES script/run.sh DESTINATION "${CMAKE_INSTALL_PREFIX}")
install(FILES res/license.sign DESTINATION "${CMAKE_INSTALL_PREFIX}")
install(FILES res/test_eng_female.pcm DESTINATION "${CMAKE_INSTALL_PREFIX}")


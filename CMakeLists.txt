cmake_minimum_required(VERSION 3.16)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

set(PICO_SDK_FETCH_FROM_GIT ON)
include(${CMAKE_SOURCE_DIR}/cmake/pico_sdk_import.cmake)

project(rtos_on_pico
  LANGUAGES CXX C ASM
  VERSION 0.0.1
)

pico_sdk_init()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")

find_package(freertos)

add_subdirectory(app)
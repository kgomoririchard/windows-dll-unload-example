cmake_minimum_required (VERSION 3.8)

project(power)

add_library(power SHARED "power.cpp" "power.h")
add_compile_definitions(BUILDING_POWER_DL)

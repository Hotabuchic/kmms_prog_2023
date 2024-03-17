cmake_minimum_required(VERSION 3.2...3.27.5)

project(kmms_prog_2023)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(SmartSort)
add_subdirectory(obuchaiika)
add_subdirectory(zachet)
add_subdirectory(prefix_sum)
#add_subdirectory(unit_test_SmartSort)
add_subdirectory(scl)

set(CMAKE_SUPPRESS_REGENERATION true)
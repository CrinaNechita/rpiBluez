add_executable(peripheral peripheral.c)
target_link_libraries(peripheral Binc)
target_link_libraries(peripheral ${WIRINGPi_LIBRARIES} pthread rt m)
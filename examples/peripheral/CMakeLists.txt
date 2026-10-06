add_executable(peripheral peripheral.c)
target_link_libraries(peripheral binc ${GLIB_LIBRARIES} ${BLUEZ_LIBRARIES} ${WIRINGPi_LIBRARIES})
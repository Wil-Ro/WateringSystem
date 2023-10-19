add_executable(PoC PoC.c)
target_link_libraries(PoC pico_stdlib hardware_adc)
pico_add_extra_outputs(PoC)

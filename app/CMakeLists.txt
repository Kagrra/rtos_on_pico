add_executable(blink
        main.cpp
)

target_link_libraries(blink pico_stdlib freertos)
target_include_directories(blink PUBLIC ../src)

pico_enable_stdio_usb(blink 1)
pico_enable_stdio_uart(blink 0)

pico_add_extra_outputs(blink)
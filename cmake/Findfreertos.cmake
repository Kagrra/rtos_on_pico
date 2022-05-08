include(FetchContent)

FetchContent_Declare(freertos
  GIT_REPOSITORY https://github.com/FreeRTOS/FreeRTOS-Kernel.git
  GIT_TAG V10.4.6
)

FetchContent_GetProperties(freertos)
if(NOT freertos)
  FetchContent_Populate(freertos)

  add_library(freertos INTERFACE)
  target_sources(freertos INTERFACE
    ${freertos_SOURCE_DIR}/event_groups.c
    ${freertos_SOURCE_DIR}/list.c
    ${freertos_SOURCE_DIR}/queue.c
    ${freertos_SOURCE_DIR}/stream_buffer.c
    ${freertos_SOURCE_DIR}/tasks.c
    ${freertos_SOURCE_DIR}/timers.c
    ${freertos_SOURCE_DIR}/portable/MemMang/heap_3.c
    ${freertos_SOURCE_DIR}/portable/GCC/ARM_CM0/port.c
  )

  target_include_directories(freertos INTERFACE
    ${freertos_SOURCE_DIR}/include
    ${freertos_SOURCE_DIR}/portable/GCC/ARM_CM0
  )

endif()
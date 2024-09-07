cmake_minimum_required(VERSION 3.5.0)
project(cquiz VERSION 0.1.0 LANGUAGES C)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc")
set(ROOT_RELATIVE_PATH "../..")

set(CONFIG_FILE "config.cmake")
if(EXISTS ${CMAKE_SOURCE_DIR}/${CONFIG_FILE})
    include(${CMAKE_SOURCE_DIR}/${CONFIG_FILE})
    message("'${CMAKE_SOURCE_DIR}/${CONFIG_FILE}' included.")
else()
    message("'${CMAKE_SOURCE_DIR}/${CONFIG_FILE}' not found.")
endif()

if(FUNCTION)
    aux_source_directory(${ROOT_RELATIVE_PATH}/src/${FUNCTION} SRC_LIST)
    message("Function '${FUNCTION}' included.")
else()
    aux_source_directory(src/pointer SRC_LIST)
    message("Default Function 'pointer' included.")
endif()

include(CTest)
enable_testing()

add_executable(cquiz ${SRC_LIST})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

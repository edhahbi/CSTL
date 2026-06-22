cmake_minimum_required(VERSION 3.16)

project(CSTL LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

add_library(cstl_core
    lib/logger.c
    src/allocator/arena.c
    src/iterators/randomAcessIter.c
    src/containers/vector.c
)

target_include_directories(cstl_core
    PUBLIC
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/src/allocator
        ${PROJECT_SOURCE_DIR}/src/containers
        ${PROJECT_SOURCE_DIR}/src/iterators
)

add_executable(cstl_test
    ${PROJECT_SOURCE_DIR}/test.c
)

target_link_libraries(cstl_test
    PRIVATE
        cstl_core
)


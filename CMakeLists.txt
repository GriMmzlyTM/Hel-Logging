cmake_minimum_required(VERSION 3.14)
project(Hel_Logging)

set(CMAKE_CXX_STANDARD 17)

# Version. Update accordingly MAJOR.MINOR.PATCH
set(LOGGER_VERSION 1.0.0)

set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

# -- SPDLOG INCLUDE - CAN EDIT --
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/submodules/spdlog/include)

include_directories(./)

# -- Generate static library --
# --
add_library(Hel_Logging STATIC
        # Wrapper and implementation
        HelLogger.h
        HelLogger.cpp
        # Logger implementation files -- CAN EDIT --
        logger.cpp logger.h)

target_include_directories(Hel_Logging PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
        $<INSTALL_INTERFACE:include>)

# -- Generate template for logging --
# --
get_filename_component(TEMPLATE_DIR ../Hel-Logging-Template ABSOLUTE)

# Create template directory
file(MAKE_DIRECTORY
        ${TEMPLATE_DIR}
        ${TEMPLATE_DIR}/test)

# Copy wrapper
add_custom_command(TARGET Hel_Logging
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/HelLogger.h
        ${TEMPLATE_DIR})

# Copy tests
add_custom_command(TARGET Hel_Logging
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${TEST_DIR}
        ${TEMPLATE_DIR}/test/)

# Copy cmake
add_custom_command(TARGET Hel_Logging
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
        ${TEMPLATE_DIR}/CMakeLists.txt)

# -- Create library directory --
# --
set (INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(MAKE_DIRECTORY
        ${INCLUDE_DIR}
        ${INCLUDE_DIR}/${LOGGER_VERSION}-${CMAKE_BUILD_TYPE}
        ${INCLUDE_DIR}/${LOGGER_VERSION}-${CMAKE_BUILD_TYPE}/HelLogger)

# Add wrapper header to include
add_custom_command(TARGET Hel_Logging
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/HelLogger.h
        ${INCLUDE_DIR}/${LOGGER_VERSION}-${CMAKE_BUILD_TYPE}/HelLogger/HelLogger.h)

# Add lib to include
add_custom_command(TARGET Hel_Logging
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-${CMAKE_BUILD_TYPE}/Hel_Logging.lib
        ${INCLUDE_DIR}/${LOGGER_VERSION}-${CMAKE_BUILD_TYPE}/HelLogger/HelLogger.lib)

# -- CMake instructions to test logging --
# --
set( APP_EXE HelLoggerTest )

add_executable(${APP_EXE}
        test/main.cpp )

target_link_libraries( ${APP_EXE}
        Hel_Logging )
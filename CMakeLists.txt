cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

project(gorilla-math)
set(LIBRARY_NAME ${CMAKE_STATIC_LIBRARY_PREFIX}${PROJECT_NAME})

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    add_compile_definitions(PLATFORM_WINDOWS)
    set(PLATFORM_WINDOWS ON)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    add_compile_definitions(PLATFORM_LINUX)
    set(PLATFORM_LINUX ON)
elseif(UNIX AND APPLE)
    add_compile_definitions(PLATFORM_MAC)
    set(PLATFORM_MAC ON)
endif ()

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vector2.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vector3.hpp
)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math.cpp
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

add_library(${LIBRARY_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(PC_FILENAME lib${PROJECT_NAME}.pc)
set(PC_LINK_FLAGS -l${PROJECT_NAME})
configure_file(${PC_FILENAME}.in ${PC_FILENAME} @ONLY)

#install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/
    DESTINATION include/${PROJECT_NAME}
    FILES_MATCHING
    PATTERN
    "*.hpp"
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PC_FILENAME} DESTINATION lib/pkgconfig)

enable_testing()
add_executable (unit-tests EXCLUDE_FROM_ALL tests/unit-tests.cpp)
target_include_directories(unit-tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(unit-tests ${LIBRARY_NAME} ${LIBRARIES_PLATFORM})
add_test(vector2            unit-tests vector2)
add_test(vector3            unit-tests vector3)

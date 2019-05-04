cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

set(LIBRARY_NAME gorilla-math)
project(${LIBRARY_NAME})

set(HEADERS
    # ${CMAKE_CURRENT_SOURCE_DIR}/include/math.hpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/include/matrix33.hpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/include/matrix44.hpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/include/quaternion.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/vector2.hpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/include/vector3.hpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/include/vector4.hpp
)

set(SOURCES
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/math.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/matrix33.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/matrix44.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/quaternion.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vector2.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/vector3.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/vector4.cpp
)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES} ${HEADERS})

add_library(lib${LIBRARY_NAME} ${SOURCES} ${HEADERS})
target_include_directories(lib${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(FILES ${HEADERS} DESTINATION include/quik-core)

enable_testing()
add_executable (unit-test EXCLUDE_FROM_ALL tests/unit-test.cpp)
target_include_directories(unit-test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(unit-test ${LIBRARY_NAME})
add_test(hash       unit-test vector)
# add_test(hash_map   unit-test matrix)
# add_test(signal     unit-test quaternion)

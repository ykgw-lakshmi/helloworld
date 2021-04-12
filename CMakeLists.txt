cmake_minimum_required(VERSION 3.0.0)
project(samplex VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(samplex ${CMAKE_SOURCE_DIR}/headers)

link_directories(samplex ${CMAKE_SOURCE_DIR}/lib)

add_executable(samplex sampleprogram1.c)

target_link_libraries(samplex parson.lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

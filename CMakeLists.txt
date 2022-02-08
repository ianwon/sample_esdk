cmake_minimum_required(VERSION 3.10)
project(hello-apis VERSION 1.0.0)

set(LIBRARY_NAME hello-apis)
set(CMAKE_CXX_STANDARD 17)

message( "LIBRARY_NAME : ${LIBRARY_NAME}" )

include(MobisLinux)
add_library(${LIBRARY_NAME} SHARED "")

target_include_directories(${LIBRARY_NAME}
    PUBLIC
        include
)

target_sources(${LIBRARY_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/srcs/HelloApi.cpp
)

FILE(GLOB PUB_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*)
set_target_properties(${LIBRARY_NAME} PROPERTIES 
    PUBLIC_HEADER ${PUB_HEADERS}
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

add_executable(${LIBRARY_NAME}-test ${CMAKE_CURRENT_SOURCE_DIR}/srcs/main.cpp)

install (TARGETS ${LIBRARY_NAME} ${LIBRARY_NAME}-test
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${LIBRARY_NAME}
)

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/pkgconfig/hello-apis.pc.cmakein"
    "${CMAKE_CURRENT_BINARY_DIR}/hello-apis.pc" @ONLY)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/hello-apis.pc"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)



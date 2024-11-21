cmake_minimum_required(VERSION 3.16)

project(boost_test_daupi_server LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#add_executable(boost_test_daupi_server main.cpp)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(boost_test_daupi_server main.cpp)
target_link_libraries(boost_test_daupi_server boost_unit_test_framework)

add_test(NAME Server COMMAND boost_test_daupi_server)

if (DEFINED ENV{BOOST_INCLUDE_DIR})
    set(BOOST_INCLUDE_DIR $ENV{BOOST_INCLUDE_DIR})
else ()
    set(BOOST_INCLUDE_DIR "C:/Users/patem/Documents/libs/boost_1_85_0") # set by Qt Creator wizard
endif ()
if (BOOST_INCLUDE_DIR STREQUAL "")
    message("BOOST_INCLUDE_DIR is not set, assuming Boost can be found automatically in your system")
elseif (EXISTS ${BOOST_INCLUDE_DIR})
    include_directories(${BOOST_INCLUDE_DIR})
endif ()

if(WIN32)
  target_link_libraries(boost_test_daupi_server wsock32 ws2_32)
endif()

include(GNUInstallDirs)
install(TARGETS boost_test_daupi_server
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

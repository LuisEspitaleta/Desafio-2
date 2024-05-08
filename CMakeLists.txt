cmake_minimum_required(VERSION 3.5)

project(DesafioII LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DesafioII main.cpp
    LineaMetro.cpp
    LineaMetro.h
    RedMetro.cpp
    EstacionMetro.h
    EstacionMetro.cpp
    RedMetro.h

)

include(GNUInstallDirs)
install(TARGETS DesafioII
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

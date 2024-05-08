cmake_minimum_required(VERSION 3.5)

project(Desafio-2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Desafio-2 main.cpp
    LineaMetro.cpp
    LineaMetro.h
    RedMetro.cpp
    EstacionMetro.h
    EstacionMetro.cpp
    RedMetro.h

)

include(GNUInstallDirs)
install(TARGETS Desafio-2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

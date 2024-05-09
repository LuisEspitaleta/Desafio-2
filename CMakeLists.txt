cmake_minimum_required(VERSION 3.5)

project(Desafio-2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Desafio-2 main.cpp
    Header/EstacionMetro.h
    Header/LineaMetro.h
    Header/RedMetro.h
    EstacionMetro.cpp
    LineaMetro.cpp
    RedMetro.cpp
    helpers.cpp
    Header/herplers.h
    Header/MenuFuntions.h
    MenuFuntions.cpp

)

include(GNUInstallDirs)
install(TARGETS Desafio-2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

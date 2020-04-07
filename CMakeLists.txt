cmake_minimum_required(VERSION 3.15)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp tinyxml2.cpp tinyxml2.h ../Model/IDataBase.h View/ViewConsole.cpp View/ViewConsole.h Model/Model.cpp Model/Model.h Controller/Controller.cpp Controller/Controller.h Model/IDataBase.h Model/DataBase.cpp Model/DataBase.h)
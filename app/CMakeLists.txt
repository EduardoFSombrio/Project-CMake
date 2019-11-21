cmake_minimum_required(VERSION "3.15.4")
project(Lista_Banco)

include_directories(Interface)
include_directories(Controller)
include_directories(Command)

set(SOURCE
	Applist.cpp
	AppList.h
)

add_library(source "${SOURCE}")





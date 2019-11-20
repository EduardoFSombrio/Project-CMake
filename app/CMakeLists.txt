cmake_minimum_required(VERSION "3.15.4")
project(Lista_Banco)

include_directories(Interface)
include_directories(Controller)

set(SOURCE
	Applist.cpp
	AppList.h
	CommandApp.h
	CommandEditWindow.cpp
	CommandEditWindow.h
	CommandVisualizationWindow.cpp
	CommandVisualizationWindow.h
)

add_library(source "${SOURCE}")





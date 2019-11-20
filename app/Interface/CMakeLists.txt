cmake_minimum_required(VERSION "3.15.4")
project(Lista_Banco)

set(INTERFACE
	MainView.cpp
	MainView.h
)

add_library(interface1 "${INTERFACE}")
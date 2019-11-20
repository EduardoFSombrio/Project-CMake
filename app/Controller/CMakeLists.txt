cmake_minimum_required(VERSION "3.15.4")
project(Lista_Banco)

set(CONTROLLER
	BankAccount.cpp
	BankAccount.h
	Client.cpp
	Client.h
	ListBankAccount.cpp
	ListBankAccount.h
	ListClient.cpp
	ListClient.h
	Controller.cpp
	Controller.h
)

add_library(controller1 "${CONTROLLER}")
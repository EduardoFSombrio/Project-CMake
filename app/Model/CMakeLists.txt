cmake_minimum_required(VERSION "3.15.4")
project(Lista_Banco)

set(MODEL
	BankAccount.cpp
	BankAccount.h
	Client.cpp
	Client.h
	ListBankAccount.cpp
	ListBankAccount.h
	ListClient.cpp
	ListClient.h
)

add_library(model1 "${MODEL}")
cmake_minimum_required(VERSION "3.15.4")
project(Lista_Banco)

add_subdirectory(app/Controller)
add_subdirectory(app/Interface)
add_subdirectory(app/Command)
add_subdirectory(app)

add_executable("${PROJECT_NAME}" Origem.cpp)

target_link_libraries("${PROJECT_NAME}" source controller1 interface1 command1)

target_include_directories(Lista_Banco PUBLIC
	app
	app/Controller
	app/Interface
	app/Command
)









     
 
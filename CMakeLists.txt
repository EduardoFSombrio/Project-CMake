cmake_minimum_required(VERSION "3.15.4")
project(Lista_Banco)

add_subdirectory(app/Controller)
add_subdirectory(app/Interface)
add_subdirectory(app)

add_executable(Lista_Banco Origem.cpp)

target_link_libraries("${PROJECT_NAME}" source controller1 interface1)

target_include_directories(Lista_Banco PUBLIC
	app
	app/Controller
	app/Interface
)









     
 
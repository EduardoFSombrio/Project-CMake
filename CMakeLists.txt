cmake_minimum_required(VERSION "3.15.4")
project(Lista_Banco)

add_subdirectory(app/Controller)
include_directories(app/Controller)

add_subdirectory(app/Interface)
include_directories(app/Interface)

add_subdirectory(app)
include_directories(app)


add_executable("${PROJECT_NAME}" Origem.cpp)

target_link_libraries("${PROJECT_NAME}" source controller1 interface1)









     
 
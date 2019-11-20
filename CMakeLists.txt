cmake_minimum_required(VERSION "3.15.4")
project(Lista_Banco)

add_subdirectory(app/Model)
include_directories(app/Model)

add_subdirectory(app/Interface)
include_directories(app/Interface)

add_subdirectory(app)
include_directories(app)


add_executable("${PROJECT_NAME}" Origem.cpp)

target_link_libraries("${PROJECT_NAME}" source model1 interface1)









     
 
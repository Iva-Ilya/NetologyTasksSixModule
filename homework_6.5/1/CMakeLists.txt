cmake_minimum_required(VERSION 3.20)
project(BDProject)
#set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} main.cpp BDcontrol.cpp)

include(FetchContent)

FetchContent_Declare(
  libpqxx
  GIT_REPOSITORY https://github.com/jtv/libpqxx.git 
  GIT_TAG        7.10.1  # или master, если тега нет
)
include_directories("C:/VsCodeProjects/Netologiya/Module_6/5/libpqxx_7.10.1/include")

#add_subdirectory(C:/VsCodeProject/Netologiya/Module_6/5/libpqxx_7.10.1 build-pqxx)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_link_libraries(${PROJECT_NAME} PRIVATE pqxx)
cmake_minimum_required (VERSION 3.15)

project(ECC VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

# set(NCK_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

aux_source_directory(./src NCG_SOURCE_DIR)


add_executable(EApp ${NCG_SOURCE_DIR})

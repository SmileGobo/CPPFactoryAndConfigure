cmake_minimum_required(VERSION 3.5)

project(CPPFactoryAndConfigure)

find_package(Poco COMPONENTS Foundation JSON Util REQUIRED)
add_subdirectory(app)

set(PROJECT factory-demo)
project(${PROJECT})


file(GLOB_RECURSE SOURCES ./*.cpp)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT} ${SOURCES})
target_include_directories(${PROJECT} PRIVATE ./include)
target_link_libraries(${PROJECT} PRIVATE Poco::JSON Poco::Util)

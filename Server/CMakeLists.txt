# 项目信息
project(Server)

# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

#设置C++11支持
add_definitions(-std=c++11)

#设置调试
set( CMAKE_BUILD_TYPE Debug )
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

#设置debug和release的编译参数
message(“The Debug Flag: ${CMAKE_CXX_FLAGS_DEBUG}”)
message(“The Release Flag: ${CMAKE_CXX_FLAGS_RELEASE}”)

# 添加子目录
add_subdirectory(src)

#add_subdirectory(../ProtocolLogic)

#添加链接库
if(WIN32)
LINK_LIBRARIES( wsock32 )
endif(WIN32)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. SRC_LIST)

# 指定生成目标
add_executable(${PROJECT_NAME} ${SRC_LIST})

# 添加链接库
target_link_libraries(${PROJECT_NAME} SysFunction)



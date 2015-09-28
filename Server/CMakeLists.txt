# 项目信息
project(Server)

# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

#设置C++11支持
add_definitions(-std=c++11)

# 添加 math 子目录
add_subdirectory(src)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. SRC_LIST)

# 指定生成目标
add_executable(${PROJECT_NAME} ${SRC_LIST})

# 添加链接库
target_link_libraries(${PROJECT_NAME} SysFunction)


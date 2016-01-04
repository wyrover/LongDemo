# 项目信息
project(Server)

# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

#设置C++11支持
add_definitions(-std=c++11)



#设置调试
set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(CXX_FLAGS
    -g
    # -DVALGRIND
    # -DMUDUO_STD_STRING
    -DCHECK_PTHREAD_RETURN_VALUE
    -D_FILE_OFFSET_BITS=64
    -Wall
    -Wextra
    -Werror
    -Wconversion
    -Wno-unused-parameter
    -Wold-style-cast
    -Woverloaded-virtual
    -Wpointer-arith
    -Wshadow
    -Wwrite-strings
    -march=native
    # -MMD
    #-std=c++11
    -rdynamic
 )

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# 添加子目录
add_subdirectory(src)

#add_subdirectory(../ProtocolLogic)

#添加链接库
if(WIN32)
    LINK_LIBRARIES(wsock32)
endif(WIN32)

#C++11 thread
LINK_LIBRARIES(pthread)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. SRC_LIST)

# 指定生成目标
add_executable(${PROJECT_NAME} ${SRC_LIST})

# 添加链接库
target_link_libraries(${PROJECT_NAME} SysFunction)





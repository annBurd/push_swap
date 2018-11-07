cmake_minimum_required(VERSION 3.12)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Ipthreads")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Ipthreads")
set(SOURCE_FILES
        inc/libft.h
        inc/push_swap.h

        src/checker.c
        src/command.c
        src/command_a.c
        src/command_b.c
        src/validation.c)
link_directories(libft)
add_executable(push_swap ${SOURCE_FILES})
target_link_libraries(push_swap -lft) # linkage
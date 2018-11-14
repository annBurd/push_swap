cmake_minimum_required(VERSION 3.12)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Ipthreads")
set(SOURCE_FILES
        inc/libft.h
        inc/push_swap.h

#        libft/ft_strequ.c

#        src/checker.c
        src/checking_values.c
        src/push_swap.c
        src/command.c
        src/command_a.c
        src/command_b.c
        src/validation.c
        src/try_rotate.c)
link_directories(libft)
add_executable(push_swap ${SOURCE_FILES})
target_link_libraries(push_swap -lft) # linkage
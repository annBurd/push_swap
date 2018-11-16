cmake_minimum_required(VERSION 3.12)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Ipthreads")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Ipthreads")
set(SOURCE_FILES
        inc/color.h
        inc/libft.h
        inc/push_swap.h

        libft/ft_strequ.c
        libft/ft_swap.c
        libft/ft_putnbr.c
        libft/ft_putchar.c
        libft/ft_is_ascending_order.c
        libft/ft_is_descending_order.c

#        src/checker.c
        src/push_swap.c

        src/do_a.c
        src/do_b.c
        src/do_both.c
        src/ps_check.c
        src/ps_init.c
        src/supporting_funcs.c
        src/try_rotate.c
        src/sort_6.c)
link_directories(libft)
add_executable(push_swap ${SOURCE_FILES})
target_link_libraries(push_swap -lft) # linkage
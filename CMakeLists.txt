cmake_minimum_required(VERSION 3.14)
project(test C)

set(CMAKE_C_STANDARD 99)

add_executable(test Sources/main.c Includes/ft_ls.h Sources/ft.c Sources/struct.c Sources/directory.c Sources/flags.c Sources/print.c Sources/flag_l.c)
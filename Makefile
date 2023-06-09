##
## EPITECH PROJECT, 2022
## sokoban
## File description:
## Makefile
##

CFLAGS =

SRC     =       source/main.c \
				source/tool/my_str_to_word_array.c \
				source/tool/my_str_to_word_array2.c \
				source/tool/mini_printf.c \
				source/tool/my_put_nbr.c \
				source/tool/my_putchar.c \
				source/tool/my_putstr.c \
				source/tool/my_strlen.c \
				source/tool/my_strcmp.c \
				source/tool/my_strcat.c \
				source/tool/my_array_len.c \
				source/tool/my_strdup.c \
				source/tool/clean_str.c \
				source/tool/my_char_isalphanum.c \
				source/tool/find_env.c \
				source/tool/my_charcmp.c \
				source/tool/get_num.c \
				source/tool/my_str_isnum.c \
				source/tool/free_array.c \
				source/tool/free_tree.c \
				source/tool/str_is_in_str.c \
				source/command/get_command.c \
				source/command/execute_command.c \
				source/command/parse_line_user.c \
				source/command/parse_line_user_error.c \
				source/command/execute_pipe.c \
				source/command/redir.c \
				source/command/dredir_in.c \
				source/command/redir_error.c \
				source/command/close_fd.c \
				source/command/intern_command/env.c \
				source/command/intern_command/intern_command.c \
				source/command/intern_command/exit.c \
				source/command/intern_command/my_setenv.c \
				source/command/intern_command/my_setenv_error.c \
				source/command/intern_command/my_unsetenv.c \
				source/command/intern_command/change_directory.c \
				source/command/intern_command/change_directory2.c \
				source/command/intern_command/change_directory_error.c \
				source/command/intern_command/tab_builtins.c \
				source/command/extern_command/extern_command.c \
				source/command/extern_command/find_file.c \

SRC_T	=		source/tool/my_str_to_word_array.c \
				source/tool/my_str_to_word_array2.c \
				source/tool/mini_printf.c \
				source/tool/my_put_nbr.c \
				source/tool/my_putchar.c \
				source/tool/my_putstr.c \
				source/tool/my_strlen.c \
				source/tool/my_strcmp.c \
				source/tool/my_strcat.c \
				source/tool/my_array_len.c \
				source/tool/my_strdup.c \
				source/tool/clean_str.c \
				source/tool/my_char_isalphanum.c \
				source/tool/find_env.c \
				source/tool/my_charcmp.c \
				source/tool/get_num.c \
				source/tool/my_str_isnum.c \
				source/tool/free_array.c \
				source/command/get_command.c \
				source/command/execute_command.c \
				source/command/intern_command/env.c \
				source/command/intern_command/intern_command.c \
				source/command/intern_command/exit.c \
				source/command/intern_command/my_setenv.c \
				source/command/intern_command/my_setenv_error.c \
				source/command/intern_command/my_unsetenv.c \
				source/command/intern_command/change_directory.c \
				source/command/intern_command/change_directory2.c \
				source/command/intern_command/change_directory_error.c \
				source/command/extern_command/extern_command.c \
				source/command/extern_command/find_file.c \

OBJ     =       $(SRC:.c=.o)

LIB = mysh

all:    $(LIB)

$(LIB):
	@gcc -o $(LIB) $(SRC) -I ./include $(CFLAGS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(LIB)

re: fclean
	@gcc -o $(LIB) $(SRC) -I ./include $(CFLAGS)

unit_tests: re
	gcc -o unit_tests $(SRC_T) tests/test_env.c -lcriterion -I ./include

run_tests: unit_tests
	./unit_tests

run_epitest: re
	sudo docker build -t epitest:lastest .
	sudo docker run -it epitest:lastest

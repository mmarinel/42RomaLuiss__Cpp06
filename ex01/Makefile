# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 17:34:54 by earendil          #+#    #+#              #
#    Updated: 2022/09/22 16:30:06 by mmarinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET		:= "\033[0m"
BLACK		:= "\033[30m"
RED			:= "\033[31m"
GREEN		:= "\033[32m"
YELLOW		:= "\033[33m"
BLUE		:= "\033[34m"
MAGENTA		:= "\033[35m"
CYAN		:= "\033[36m"
WHITE		:= "\033[37m"
BOLDBLACK	:= "\033[1m\033[30m"
BOLDRED		:= "\033[1m\033[31m"
BOLDGREEN	:= "\033[1m\033[32m"
BOLDYELLOW	:= "\033[1m\033[33m"
BOLDBLUE	:= "\033[1m\033[34m"
BOLDMAGENTA	:= "\033[1m\033[35m"
BOLDCYAN	:= "\033[1m\033[36m"
BOLDWHITE	:= "\033[1m\033[37m"

CC:= @clang++
CFLAGS:= -std=c++98 -Wall -Werror -Wextra

NAME := bureaucrat_01
OBJS_DIR:= bin
OBJS:= $(addprefix $(OBJS_DIR)/, $(shell find . -name "*.cpp" -print | sed 's/\.cpp/\.o/g' | sed 's/\.\///'))
INCLUDES:= $(shell find . -name "*.hpp" -print)

RMF:= @/bin/rm -rf
MKD:= @mkdir -p
MAKE_REC:= @make --no-print-directory

exercise: .BUILD

run: .RUN
	@echo $(CYAN) "\nTests running\n" $(RESET)
	@leaks --atExit -- ./$(NAME)

all:
	@$(MAKE_REC) -C ..

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "\033[0;35mProject done!\n\n\033[0;37m"

$(shell echo $(OBJS_DIR))/%.o: %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	@printf "removing program executable $(NAME)\n\033[0;37m"
	$(RMF) -f $(NAME)
	@printf "\033[0;35mExecutable removed!\n\n\033[0;37m"

clean:
	@printf "removing Object files $(OBJS)\n\033[0;37m"
	$(RMF) $(OBJS_DIR)
	$(RMF) *_shrubbery
	@printf "\033[0;35mObject files removed!\n\n\033[0;37m"

re: fclean all

.BUILD:
	$(MKD) $(OBJS_DIR)
	@printf "\e[1;33mMaking exercise $(NAME) \n\033[0;37m"
	@$(MAKE_REC) $(NAME)

.RUN:
	$(MAKE_REC) -i exercise
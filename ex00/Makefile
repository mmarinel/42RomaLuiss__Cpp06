# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 17:34:54 by earendil          #+#    #+#              #
#    Updated: 2022/10/06 13:27:11 by mmarinel         ###   ########.fr        #
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

NAME := conversions_00
OBJS_DIR:= bin
OBJS:= $(addprefix $(OBJS_DIR)/, $(shell find . -name "*.cpp" -print | sed 's/\.cpp/\.o/g' | sed 's/\.\///'))
INCLUDES:= $(shell find . -name "*.hpp" -print)

RMF:= @/bin/rm -rf
MKD:= @mkdir -p
MAKE_REC:= @make --no-print-directory

exercise: .BUILD

run: .RUN
	@echo $(CYAN) "\nTests running\n" $(RESET)
	@echo $(YELLOW)"NO string literal" $(RESET) && leaks --atExit -- ./$(NAME)
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: nan" $(RESET) && leaks --atExit -- ./$(NAME) nan
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: nanf" $(RESET) && leaks --atExit -- ./$(NAME) nanf
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: +inf" $(RESET) && leaks --atExit -- ./$(NAME) +inf
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: +inff" $(RESET) && leaks --atExit -- ./$(NAME) +inff
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: -inf" $(RESET) && leaks --atExit -- ./$(NAME) -inf
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: -inff" $(RESET) && leaks --atExit -- ./$(NAME) -inff
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: 0" $(RESET) && leaks --atExit -- ./$(NAME) 0
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: 42" $(RESET) && leaks --atExit -- ./$(NAME) 42
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: 42.743154862" $(RESET) && leaks --atExit -- ./$(NAME) 42.743154862
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: 42.743154862f" $(RESET) && leaks --atExit -- ./$(NAME) 42.743154862f
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: 42.73f" $(RESET) && leaks --atExit -- ./$(NAME) 42.73f
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: 42.73" $(RESET) && leaks --atExit -- ./$(NAME) 42.73
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: 340282000000000000000000000000000000000f (max float)" $(RESET) && leaks --atExit -- ./$(NAME) 340282000000000000000000000000000000000f
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: 340283000000000000000000000000000000000f (next of max float)" $(RESET) && leaks --atExit -- ./$(NAME) 340283000000000000000000000000000000000f
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: -340282000000000000000000000000000000000f (min float) " $(RESET) && leaks --atExit -- ./$(NAME) -340282000000000000000000000000000000000f
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: -340283000000000000000000000000000000000f (prev of min float) " $(RESET) && leaks --atExit -- ./$(NAME) -340283000000000000000000000000000000000f
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: 179769000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 (max of Double) " $(RESET) && leaks --atExit -- ./$(NAME) 179769000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: 179770000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 (next of max of Double)" $(RESET) && leaks --atExit -- ./$(NAME) 179770000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: -179769000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 (min of Double)" $(RESET) && leaks --atExit -- ./$(NAME) -179769000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: -17977000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 (prev of min of Double)" $(RESET) && leaks --atExit -- ./$(NAME) -179770000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: 2147483647 (max of int) " $(RESET) && leaks --atExit -- ./$(NAME) 2147483647
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: 2147483648 (next of max int) " $(RESET) && leaks --atExit -- ./$(NAME) 2147483648
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: -2147483648 (min of int) " $(RESET) && leaks --atExit -- ./$(NAME) -2147483648
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: -2147483649 (prev of min of int) " $(RESET) && leaks --atExit -- ./$(NAME) -2147483649
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: 127 (max char) " $(RESET) && leaks --atExit -- ./$(NAME) 127
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: 128 (next of max char) " $(RESET) && leaks --atExit -- ./$(NAME) 128
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: -128 (min char) " $(RESET) && leaks --atExit -- ./$(NAME) -128
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: -129 (prev of min char) " $(RESET) && leaks --atExit -- ./$(NAME) -129
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: 1 (non-displayable char) " $(RESET) && leaks --atExit -- ./$(NAME) 1
	@read -p "Press Enter to continue"; clear;
	@echo $(YELLOW)"string literal: abcdefg (not a type) " $(RESET) && leaks --atExit -- ./$(NAME) abcdefg

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
	@printf "\033[0;35mObject files removed!\n\n\033[0;37m"

re: fclean all

.BUILD:
	$(MKD) $(OBJS_DIR)
	@printf "\e[1;33mMaking exercise $(NAME) \n\033[0;37m"
	@$(MAKE_REC) $(NAME)

.RUN:
	$(MAKE_REC) -i exercise
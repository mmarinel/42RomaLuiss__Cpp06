# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 17:11:58 by earendil          #+#    #+#              #
#    Updated: 2022/09/12 12:08:58 by mmarinel         ###   ########.fr        #
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

all:
	@echo "Making all exercises\n"
	@for DIR in $$(find . -print | grep "Makefile" | sed 's/Makefile//g' | grep ex); do \
		make --no-print-directory -C $$DIR exercise; \
	done;
	@echo Exercises done!

ex%: FORCE
	@$(MAKE) -C $@ run

FORCE:#https://www.gnu.org/software/make/manual/make.html#Force-Targets

run:
	@make --no-print-directory -si .RUN

fclean:
	@echo "Destroying all exercises\n"
	@for DIR in $$(find . -print | grep "Makefile" | sed 's/Makefile//g' | grep ex); do \
		make --no-print-directory -C $$DIR fclean; \
	done;
	@echo Exercises destroyed!

re: fclean all

.RUN:
	@echo "Running all exercises\n"
	@for DIR in $$(find . -print | grep "Makefile" | sed 's/Makefile//g' | grep ex); do \
		clear; \
		make --no-print-directory -C $$DIR run; \
		echo "\n"; \
		echo $(BOLDWHITE); \
		read -p "Press Enter to continue"; \
		echo $(RESET); \
	done;
	@echo "\n"
	@echo $(BOLDGREEN) Run completed! $(RESET)

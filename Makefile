##
## EPITECH PROJECT, 2021
## hexer
## File description:
## Makefile
##

CC		=	g++

CXXFLAGS  	=  	-Wall -Wextra -Iinclude -g3
LDFLAGS		=	-lncurses

BINARY_NAME	=	hexer
TESTS_NAME	=	unit_tests

SRC		=	src/main.cpp		\
			src/Hexer.cpp		\
			src/Curses.cpp		\
			src/Window.cpp		\
			src/Typecaster.cpp	\

TESTS	=	\

OBJ		=	$(SRC:.cpp=.o)

all: hexer

hexer: $(OBJ)
	@$(CC) $(CXXFLAGS) -o $(BINARY_NAME) $(OBJ) $(LDFLAGS)

tests_run:
	@echo "No tests specified" && exit 0

clean:
	@rm -f *.gc*
	@rm -f $(OBJ)
	@rm -f tests/*.o

fclean:	clean
	@$(RM) $(BINARY_NAME) $(TESTS_NAME)

re: fclean all

.PHONY:	all hexer clean fclean re tests_run
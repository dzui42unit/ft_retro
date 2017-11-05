NAME	=	ft_retro

CLANG	=	clang++ -Wall -Wextra -Werror

OBJ		:=	$(patsubst %.cpp,%.o, $(wildcard *.cpp))

all: $(NAME)

$(NAME): $(OBJ)
	$(CLANG) $(OBJ) -o $(NAME) -lncurses

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
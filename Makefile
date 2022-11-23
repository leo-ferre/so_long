# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 21:49:21 by leoferre          #+#    #+#              #
#    Updated: 2022/10/25 21:39:13 by leoferre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		so_long

SRCS =		./srcs/main.c				\
			./srcs/map_check.c			\
			./srcs/utils/ext_check.c	\
			./srcs/utils/shape_check.c	\
			./srcs/utils/walls_check.c	\
			./srcs/utils/chars_check.c	\
			./srcs/utils/path_check.c	\
			./srcs/so_long.c			\
			./srcs/utils/render_game.c	\
			./srcs/utils/keys_game.c	\
			./srcs/utils/x_game.c		\
			./srcs/utils/move_game.c	\
			./srcs/warnings.c			\
			./srcs/utils/sides_game.c	


OBJ =			$(SRCS:.c=.o)
LIBFT_A = 		libft.a
LIBFT_COMPILE = cd libft && make
LIBFT_COPY = 	cp ./libft/libft.a $(LIBFT_A)
LIBFT_FCLEAN = 	cd libft && make fclean
HEADER = 		./includes/so_long.h
RM =			rm -rf
CC =			cc
FLAGS =			-Wall -Wextra -Werror
MLX_FLAGS = 	-lX11 -lXext -lmlx

all:	$(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) 

$(NAME):	$(OBJ) $(HEADER)
			$(LIBFT_COMPILE)
			$(LIBFT_COPY)
			$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS) $(LIBFT_A)

clean:
		$(RM) $(OBJ)
		$(RM) $(LIBFT_A)
		$(LIBFT_FCLEAN)

fclean:	clean 
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
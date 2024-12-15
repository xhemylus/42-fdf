# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abollen <abollen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 17:38:23 by abollen           #+#    #+#              #
#    Updated: 2022/01/22 12:07:28 by abollen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#***** VARIABLES *****#

NAME = fdf
HEADER = includes/fdf.h

FILES = main.c gnl.c gnl_u.c mesh.c draw.c utils.c input.c map.c utils1.c colors.c
OBJ = ${addprefix ${OBJ_DIR}/,${FILES:.c=.o}}

SRC_DIR = src
OBJ_DIR = obj

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

#***** RULES *****#

all : ${OBJ_DIR} ${NAME}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${HEADER}
	@$(CC) $(CFLAGS) -Imlx -Ilibft -c $< -o $@
	@echo "\033[95m[FDF]\033[92m[BUILD]\033[97m $@."

$(NAME): ${OBJ_DIR} $(OBJ)
	@make -sC mlx
	@make -C libft
	@$(CC) $(OBJ) -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\033[95m[FDF]\033[92m[BUILD] \033[0m${NAME}"

${OBJ_DIR}:
	@mkdir obj
	@echo "\033[95m[FDF]\033[92m[BUILD] \033[0m${OBJ_DIR} folder"
	
clean :
	@make -s -C mlx clean
	@echo "\033[95m[MLX]\033[93m[CLEAN]"
	@make -C libft clean
	@rm -rf ${OBJ_DIR}
	@echo "\033[95m[FDF]\033[93m[CLEAN] \033[0m${OBJ_DIR} folder"

fclean : clean
	@make -C libft extfclean
	@rm -rf ${NAME}
	@echo "\033[95m[FDF]\033[93m[CLEAN] \033[0m${NAME}"

re: fclean all

.PHONY : all clean fclean re
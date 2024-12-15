NAME = libft.a
HEADER = libft.h

FILES =  ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c\
        ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
        ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c


OBJ_DIR = obj
SRC_DIR = src

OBJ = ${addprefix ${OBJ_DIR}/,${FILES:.c=.o}}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

all: ${OBJ_DIR} ${NAME}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${HEADER}
	@${CC} ${CFLAGS} -c $< -o $@
	@echo "\033[95m[LIBFT]\033[92m[BUILD]\033[97m $@"

${NAME}: ${OBJ}
	@ar rcs ${NAME} ${OBJ}

${OBJ_DIR} :
	@mkdir ${OBJ_DIR}
	@echo "\033[95m[LIBFT]\033[92m[BUILD] \033[0m${OBJ_DIR} folder"

clean:
	@rm -rf ${OBJ_DIR}
	@echo "\033[95m[LIBFT]\033[93m[CLEAN] \033[0m${OBJ_DIR} folder"

fclean: clean
	@rm -rf ${NAME}
	@echo "\033[95m[LIBFT]\033[93m[CLEAN] \033[0m${NAME}"

extfclean :
	@rm -rf ${NAME}
	@echo "\033[95m[LIBFT]\033[93m[CLEAN] \033[0m${NAME}"

re: fclean all

.PHONY: all clean fclean extfclean re
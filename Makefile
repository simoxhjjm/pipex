# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 11:06:06 by melhajja          #+#    #+#              #
#    Updated: 2023/02/18 20:26:27 by melhajja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex
SRCS = 	pipex.c pipex_utils.c main.c
UTILS_SRC = utils/ft_bzero.c utils/ft_calloc.c utils/ft_memset.c utils/ft_split.c \
			utils/ft_strdup.c utils/ft_strjoin.c utils/ft_strlen.c utils/ft_strnstr.c \
			utils/ft_substr.c utils/ft_strchr.c


CFLAGS = -Wall -Wextra -Werror

OFILES = $(SRCS:.c=.o)
UTILS_OBJ = $(UTILS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OFILES) $(UTILS_OBJ)
	cc $(OFILES) $(UTILS_OBJ) -o $(NAME)
clean:
		rm -f $(OFILES) $(UTILS_OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re 
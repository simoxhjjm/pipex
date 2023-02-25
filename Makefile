# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 11:06:06 by melhajja          #+#    #+#              #
#    Updated: 2023/02/25 16:39:42 by melhajja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex
NAME_B = pipex_bonus
SRCS = 	pipex.c pipex_utils.c main.c
UTILS_SRC = utils/ft_bzero.c utils/ft_calloc.c utils/ft_memset.c utils/ft_split.c \
			utils/ft_strdup.c utils/ft_strjoin.c utils/ft_strlen.c utils/ft_strnstr.c \
			utils/ft_substr.c utils/ft_strchr.c

BNS_SRC = pipex_bonus_utils.c pipex_bonus.c pipex_multiple_pipes.c pipex_heredoc.c
GET_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
CFLAGS = -Wall -Wextra -Werror

OFILES = $(SRCS:.c=.o)
UTILS_OBJ = $(UTILS_SRC:.c=.o)
BNS_OBJ = $(BNS_SRC:.c=.o)
GET_OBJ = $(GET_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OFILES) $(UTILS_OBJ)
	cc $(OFILES) $(UTILS_OBJ) -o $(NAME)
bonus: $(NAME_B)

$(NAME_B): $(UTILS_OBJ) $(BNS_OBJ) $(GET_OBJ)
	cc $(UTILS_OBJ) $(BNS_OBJ) $(GET_OBJ) -o $(NAME_B)
		
clean:
		rm -f $(OFILES) $(UTILS_OBJ) $(BNS_OBJ) $(GET_OBJ)
fclean: clean
		rm -f $(NAME) $(NAME_B)
re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re
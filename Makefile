# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 15:37:52 by bbenaali          #+#    #+#              #
#    Updated: 2024/11/22 10:25:58 by bbenaali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_putstr.c ft_putnbr.c ft_putchar.c \
		 ft_hexodecimal.c ft_unsigned.c

OBJCS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all: ${NAME}

${NAME}: ${OBJCS}
	ar rc ${NAME} ${OBJCS}

%.o:%.c ft_printf.h
	${CC} ${FLAGS} -c $< -o $@

clean:
	${RM} ${OBJCS}

fclean: clean
	${RM} ${NAME}

re: fclean all
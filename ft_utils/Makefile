# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 21:33:03 by sgerace           #+#    #+#              #
#    Updated: 2022/05/31 19:46:11 by sgerace          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftutils.a

SRCS =	ft_printf_main.c \
		ft_printf_string_utils.c \
		ft_printf_num_utils.c \
		ft_atoi.c

OBJS		=	${SRCS:.c=.o}

CC			= gcc

RM			= rm -f

CFLAGS		= -g -Wall -Wextra -Werror

$(NAME):	${OBJS}
			ar -rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean ${NAME}
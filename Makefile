# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 18:39:18 by sgerace           #+#    #+#              #
#    Updated: 2022/06/23 20:09:54 by sgerace          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT	=	client

NAME_SERVER	=	server


SRC_CLIENT	=	client.c

SRC_SERVER	=	server.c


OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)


CC			=	gcc

RM			=	rm -f

CFLAGS		=	-g -Wall -Wextra -Werror

LIBFOLDER = ft_utils/libftutils.a

all:			$(NAME_CLIENT) $(NAME_SERVER)


$(NAME_CLIENT):	$(OBJ_CLIENT)
				@make all -C ft_utils/
				$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LIBFOLDER)
$(NAME_SERVER):	$(OBJ_SERVER)
				@make all -C ft_utils/
				$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) $(LIBFOLDER)


clean:
				$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
				@make clean -C ft_utils/
fclean:			clean
				$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER)
				$(MAKE) fclean -C ft_utils/
re:				fclean all

.PHONY:		all clean fclean re

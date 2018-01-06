# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdjeghba <sdjeghba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/07 01:01:32 by sdjeghba          #+#    #+#              #
#    Updated: 2018/01/04 04:37:06 by sdjeghba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_ls
INC			=	-I./includes
CC			=	gcc
RM			=	rm -rf
CFLAGS		=	-Wall -Werror -Wextra
LIB			=	./libft/libft.a
P_LIB		=	./libft/
P_SRC		=	./srcs/

SRCS		=	$(P_SRC)ft_ls.c						\
				$(P_SRC)main.c						\
				$(P_SRC)sort_list.c					\
				$(P_SRC)processing_chained_list.c	\
				$(P_SRC)check_and_get_flags.c		\
				$(P_SRC)display_errors.c			\
				$(P_SRC)tools.c						\
				$(P_SRC)tools_snd.c					\
				$(P_SRC)display_ls.c				\
				$(P_SRC)recursive.c

OBJS		=	$(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				make -C $(P_LIB)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INC) $(LIB)

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				make -C $(P_LIB) clean
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)
				make -C $(P_LIB) fclean

re:				fclean all

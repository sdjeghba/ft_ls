# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 11:32:22 by sdjeghba          #+#    #+#              #
#    Updated: 2017/12/30 06:08:02 by sdjeghba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = gcc -Wall -Wextra -Werror
INCLUDES = -I ../includes/
NAME = libft.a

SRCS =	ft_isprint.c		\
		ft_isalnum.c		\
		ft_isdigit.c		\
		ft_isalpha.c 		\
		ft_isascii.c		\
		ft_toupper.c 		\
		ft_tolower.c		\
		ft_atoi.c	 		\
		ft_memcmp.c			\
		ft_memchr.c  		\
		ft_lstmap.c			\
		ft_isupper.c  		\
		ft_strlen.c			\
		ft_strcpy.c			\
		ft_strncpy.c		\
		ft_strncat.c  		\
		ft_strcat.c			\
		ft_strlcat.c		\
		ft_strchr.c			\
		ft_strrchr.c  		\
		ft_strstr.c			\
		ft_strnstr.c		\
		ft_strcmp.c			\
		ft_strncmp.c  		\
		ft_strdup.c			\
		ft_putchar.c		\
		ft_putstr.c			\
		ft_putchar_fd.c 	\
		ft_putstr_fd.c		\
		ft_putendl.c		\
		ft_putendl_fd.c		\
		ft_putnbr.c  		\
		ft_putnbr_fd.c		\
		ft_memalloc.c		\
		ft_memdel.c			\
		ft_strnew.c			\
		ft_strdel.c			\
		ft_strclr.c			\
		ft_striter.c		\
		ft_striteri.c 		\
		ft_strmap.c			\
		ft_strmapi.c		\
		ft_strequ.c			\
		ft_strnequ.c  		\
		ft_strsub.c			\
		ft_strjoin.c		\
		ft_strtrim.c		\
		ft_memcpy.c			\
		ft_memccpy.c		\
		ft_memmove.c		\
		ft_memset.c			\
		ft_bzero.c	  		\
		ft_itoa.c			\
		ft_strsplit.c		\
		ft_lstnew.c			\
		ft_lstdel.c			\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstadd.c			\
		ft_swap.c 			\
		ft_strrev.c			\
		ft_power.c			\
		ft_islower.c		\
		ft_lstpushback.c	\
		ft_lstlen.c			\
		ft_lstsortbyname.c 	\
		ft_lstsortrev.c 	\
		ft_display_list.c 	\
		ft_place_between_str.c	\
		ft_display_tab.c	\
		ft_get_tab_height.c	\
		ft_copy_tab.c		\
		ft_free_tab.c		\
		ft_strrealloc.c		\
		ft_count_word.c		\
		ft_putdblstr.c		\
		ft_putendblstr.c	\
		get_next_line.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRCS)
	$(CFLAGS) -c $(INCLUDES) $(SRCS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

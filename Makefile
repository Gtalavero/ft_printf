# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtalaver <gtalaverodev@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 17:48:06 by gtalaver          #+#    #+#              #
#    Updated: 2020/07/06 17:59:05 by gtalaver         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c fillstruct.c conversions.c final_str.c ft_itoa_minus.c \

OBJS	:= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I.
RM		= rm -f

all:	${NAME}

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

%.o: libft/%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:${OBJS}
		make -C libft 
		ar rc ${NAME} libft/*.o ${OBJS}

debug:
		$(CC) $(CFLAGS) -g $(SRCS) main.c ft_printf.h libft/ft_*.c -I libft

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME} libft/*.o *.o

re:		fclean all
.PHONY: all clean fclean re
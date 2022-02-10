# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 13:59:50 by cemenjiv          #+#    #+#              #
#    Updated: 2022/02/10 10:35:20 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= 
				 
OBJS			= $(SRCS:.c=.o)

NORM 			= norminette

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

NAME			= push_swap

all:			$(NAME)

$(NAME):		$(OBJS)
				$(MAKE) bonus -C ./libft
				cp libft/libft.a $(NAME)
				ar rcs $(NAME) $(OBJS)
				ranlib $(NAME)
				
clean:		
				$(MAKE) clean -C ./libft
				$(RM) -f $(OBJS)
				
fclean:			clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME)
				
re:				fclean all
				




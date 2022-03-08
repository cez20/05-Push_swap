# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cezmenji <cezmenji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 13:59:50 by cemenjiv          #+#    #+#              #
#    Updated: 2022/03/07 17:01:45 by cezmenji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap  #nom de l'executable que l'on veut creer 

SRCS			= main.c utils.c  #Declaration de la variable SRCS (fichier sources) nom des fichiers .c a l'origine de mon programme 
				 
OBJS			= $(SRCS:.c=.o) #Declaration OBJS (objets). Tous les fichiers terminant par le suffixe .c vont devenir .o

CC				= gcc  #name of C compiler
CFLAGS			= -Wall -Wextra -Werror #nom des differents flags a utiliser 
RM				= rm -f  #shortcut Rm fait ce que fait normalement rm -f 

all:			$(NAME)  #commande "make all" fait ce que la variable NAME fait

$(NAME):		$(OBJS)  #Convertis tous les fichiers sources (.c) and fichier objet (.o)
				$(MAKE) bonus -C ./libft 
				$(CC) $(OBJS) -L ./libft -lft -o $(NAME)	
				
clean:		
				$(MAKE) clean -C ./libft
				$(RM) $(OBJS)
				
fclean:			clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME)
				
re:				fclean all
				




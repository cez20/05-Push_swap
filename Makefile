# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 13:59:50 by cemenjiv          #+#    #+#              #
#    Updated: 2022/04/12 22:18:04 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap  #nom de l'executable que l'on veut creer 

SRCS			= main.c stacks.c args_validation.c node_creation.c node_maintenance.c \
 				  utils.c selection.c operations_a.c operations_b.c quick_sort.c
				 
				  
OBJS			= $(SRCS:.c=.o) #Declaration OBJS (objets). Tous les fichiers terminant par le suffixe .c vont devenir .o

CC				= gcc  #name of C compiler
CFLAGS			= -Wall -Wextra -Werror -g #nom des differents flags a utiliser 
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
				




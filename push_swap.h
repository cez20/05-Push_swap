/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:04:51 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/09 15:44:36 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <limits.h>  // Necessaire afin de mettre INT_MIN INT_MAX 
#include <unistd.h>
#include <stdlib.h> // Pas necessaire pcq deja dans libft?
#include <stdio.h>  // Pas necessaire pcq deja dans libft?
#include <stdbool.h>  // Verifier ce qu'est le contenu de cette library

/* s_dlist =    Doubly linked list. Contient un int pour contenir le chiffre. Un pointeur vers element suivant. Un pointeur vers elements precedent et 
              un int indiquant la position actuelle.*/

typedef struct s_dlist
{
	int				content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
	int				pos;
}					t_dlist;

/*  struct qui contient un pointeur vers la structure ici-haut.
    Un pointeur indiquant le head de la doubly linked list et la tail (dernier element) de la linked list. */

typedef struct s_stack
{
	struct s_dlist	*head;  // Est-ce que je peux mettre t_dlist au lieu de s_dlist ?? A valider 
	struct s_dlist	*tail;
}					t_stack;

/*  struct s_stacks qui contient 2 pointeurs pointants vers les 2 stacks autorises. Ces deux stacks pointent vers la structure s_stack ici-haut */

typedef struct s_stacks
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}					t_stacks;

// *** MAIN.C ***
int 		main (int argc, char **argv);
void    	create_dlist (t_stack *stack_a, char **argv);
void    	check_duplicate(char **argv, int i);
int			ft_isint(char *str);
int			ft_strcmp(const char *s1, const char *s2);
long		ft_atol(const char *nptr);

// *** UTILS.C ***
int			assign_pos(int len, int i, t_dlist *lst);
void		clear_stacks(t_stacks *stacks);
void    	error(void);
t_stacks    *initialize_stacks(void);

// *** DLST.C ***
void	    dlst_add_back(t_dlist **head, t_dlist *new);
void	    dlst_add_front(t_dlist **head, t_dlist *new);
t_dlist	    *dlst_last(t_dlist *lst);
int	        dlst_len(t_dlist *lst);
t_dlist	    *dlst_new(int content);
void		dlst_clear(t_stack *stack);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:04:51 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/20 22:42:28 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>  // Necessaire afin de mettre INT_MIN INT_MAX 
# include <unistd.h>
# include <stdlib.h> // Pas necessaire pcq deja dans libft?
# include <stdio.h>  // Pas necessaire pcq deja dans libft?
# include <stdbool.h>  // Verifier ce qu'est le contenu de cette library

typedef struct s_dlist
{
	int				data;
	struct s_dlist	*next;
	struct s_dlist	*prev;
	int				pos;
}					t_dlist;

typedef struct s_stack
{
	struct s_dlist	*head;
	struct s_dlist	*tail;
}					t_stack;

typedef struct s_stacks
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}					t_stacks;

// *** MAIN.C ***
int			main(int argc, char **argv);
void		create_dlist(t_stack *stack_a, char **argv);
void		dlst_clear(t_stack *stack);
void   		print_dlist(t_dlist *head);

// *** STACKS.C ***
t_stacks	*initialize_stacks(void);
void		clear_stacks(t_stacks *stacks);

// *** ARGS_VALIDATION.C ***
void		check_duplicate(char **argv, int i);
long		ft_atol(const char *str);
void		check_if_int(char **str, int i);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strchr1(const char *s, int c);

// *** DLIST_CREATION.C ***
void		dlst_add_back(t_dlist **head, t_dlist *new);
void		dlst_add_front(t_dlist **head, t_dlist *new);
t_dlist		*dlst_last(t_dlist *lst);
int			dlst_len(t_dlist *lst);
t_dlist		*dlst_new(int content);

// *** UTILS.C   ***
int			assign_pos(int len, int i, t_dlist *lst);
void		error(void);

#endif
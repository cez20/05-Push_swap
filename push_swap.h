/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:04:51 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/23 15:56:05 by cemenjiv         ###   ########.fr       */
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
void		print_dlist(t_dlist *head);

// *** STACKS.C ***
t_stacks	*initialize_stacks(void);
void		clear_stacks(t_stacks *stacks);

// *** ARGS_VALIDATION.C ***
void		int_validation (char **argv);
void		check_duplicate(char **argv, int i);
long		ft_atol(const char *str);
void		check_if_int(char **str, int i);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strchr1(const char *s, int c);

// *** DLIST_CREATION.C ***
void		dlist_creation(t_stack *stack_a, char **argv);
void		free_args(char **args, int i, int j);
void		dlst_add_back(t_dlist **head, t_dlist *new);
void		dlst_add_front(t_dlist **head, t_dlist *new);
t_dlist		*dlst_last(t_dlist *lst);
int			dlst_len(t_dlist *lst);
t_dlist		*dlst_new(int content);

// *** UTILS.C   ***
void		positioning(int len, t_dlist *lst);
void		error(void);

// *** SELECTION.C ***
void	simple_sort(t_stacks *s);
//void	selectionsort(t_stacks *s, int len);
int		is_sorted(t_dlist *lst);
int		is_in_order(t_dlist *lst, int i);
int		smallest_num(t_stack *stack);
int		biggest_num(t_stack *stack);
void	direction(t_stack *stack, int len, int small);

// *** OPERATIONS.C ***
void	swap_a(t_stack *stack);
void	rotate_a(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	push(t_stack *src, t_stack *dest, char *str);
void	push1(t_stack *src, t_stack *dest);


#endif
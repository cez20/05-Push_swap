/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:04:51 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/11 17:31:02 by cemenjiv         ###   ########.fr       */
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

// *** STACKS.C ***
t_stacks	*initialize_stacks(void);
void		clear_stacks(t_stacks *stacks);

// *** ARGS_VALIDATION.C ***
void		int_validation(char **argv);
void		check_duplicate(char **argv, int i);
void		check_if_int(char **str, int i);
long		ft_atol(const char *str);
int			ft_strchr1(const char *s, int c);

// *** DLIST_CREATION.C ***
void		dlist_creation(t_stack *stack_a, char **argv);
t_dlist		*dlst_new(int content);
void		dlst_add_back(t_dlist **head, t_dlist *new);
t_dlist		*dlst_last(t_dlist *lst);
void		free_args(char **args, int i, int j);

// *** DLIST_MAINTENANCE.C ***
int			dlst_len(t_dlist *lst);
void		dlst_clear(t_stack *stack);

// *** OPERATIONS_A.C ***
void		swap_a(t_stack *stack);
void		rotate_a(t_stack *stack);
void		reverse_rotate_a(t_stack *stack);
void		push_a(t_stack *stack_b, t_stack *stack_a);

// *** OPERATIONS_B.C ***
void		swap_b(t_stack *stack);
void		rotate_b(t_stack *stack);
void		reverse_rotate_b(t_stack *stack);
void		push_b(t_stack *stack_a, t_stack *stack_b);

// *** SELECTION.C ***
void		selection_sort(t_stacks *s, int len);
void		simple_sort(t_stacks *s);
int			which_half(t_stack *stack, int small);
int			smallest_nb(t_stack *stack);
int			biggest_nb(t_stack *stack);

// *** QUICK_SORT.C ***
void		quick_sort(t_stacks *s, int len);
void		quick_sort1(t_stacks *s, int len);
void		selection_sort1(t_stacks *s, int len);
void		selection_sort2(t_stacks *s, int len);
void		push_back_to_a(t_stacks *s, int count);
int			find_median(t_stacks *s, int len);
void		bubble_sort(int *tab, int size);
void		push_chunk(t_stacks *s, int *top);
void		selection_sort1(t_stacks *s, int len);
int			*verify_small(t_stacks *s, int *small, int *len);

// *** UTILS.C   ***
void		positioning(int len, t_dlist *lst);
void		print_dlist(t_dlist *head);
int			is_sorted(t_dlist *lst);
void		error(void);

#endif
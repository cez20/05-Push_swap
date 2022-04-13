/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:04:51 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/12 22:34:25 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>  // Necessaire afin de mettre INT_MIN INT_MAX 
# include <unistd.h>
# include <stdlib.h> // Pas necessaire pcq deja dans libft?
# include <stdio.h>  // Pas necessaire pcq deja dans libft?

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
	int				index;
}					t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
}					t_stack;

typedef struct s_stacks
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}					t_stacks;

// *** MAIN.C ***
int			main(int argc, char **argv);

// *** STACKS.C ***
t_stacks	*create_stacks(void);
void		free_stacks(t_stacks *stacks);

// *** ARGS_VALIDATION.C ***
void		args_validation(char **argv);
void		check_duplicate(char **argv, int i);
void		check_if_int(char **str, int i);
long		ft_atol(const char *str);
int			ft_strchr1(const char *s, int c);

// *** NODE_CREATION.C ***
void		create_nodes(t_stack *stack_a, char **argv);
t_node		*node_new(int content);
void		node_add_back(t_node **head, t_node *new);
t_node		*node_last(t_node *lst);
void		free_args(char **args, int i, int j);

// *** NODE_MAINTENANCE.C ***
int			nodes_len(t_node *lst);
void		node_deletion(t_stack *stack);

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
void		indexing(int len, t_node *lst);
void		print_node(t_node *head);
int			is_sorted(t_node *lst);
void		error(void);

#endif
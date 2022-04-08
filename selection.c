/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:24:18 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/08 16:47:33 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *verify_small(t_stacks *s,int *small, int *len);

void	selection_sort(t_stacks *s, int len)
{
	int	small;
	int	nb_location;

	while (len > 3)
	{
		small = smallest_nb(s->stack_a);
		nb_location = which_half(s->stack_a, small);
		while (s->stack_a->head->pos != small)
		{
			if (nb_location <= (len / 2))
				rotate_a(s->stack_a);
			else if (nb_location >= (len / 2))
				reverse_rotate_a(s->stack_a);
			if (is_sorted(s->stack_a->head) == 1)
				return ;
		}
		push_b(s->stack_a, s->stack_b);
		len--;
	}
	simple_sort(s);
	while (s->stack_b->head != NULL)
		push_a(s->stack_b, s->stack_a);
}

void	selection_sort1(t_stacks *s, int len)
{
	int	small;
	int	nb_location;

	while (len > 0)
	{
		small = smallest_nb(s->stack_b);
		verify_small(s , &small, &len);
		nb_location = which_half(s->stack_b, small);
		while (s->stack_b->head->pos != small)
		{
			if (nb_location <= (len / 2))
				rotate_b(s->stack_b);
			else if (nb_location >= (len / 2))
				reverse_rotate_b(s->stack_b);
		}
		push_a(s->stack_b, s->stack_a);
		rotate_a(s->stack_a);
		len--;
	}
}

// int*	verify_small(t_stacks *s,int *small, int *len)
// {
	
// 	while (*small != (s->stack_a->tail->pos + 1))
// 	{
// 		if (*small == 1)
// 			break;
// 		push_b(s->stack_a, s->stack_b);
// 		(*len)++;
// 		*small = smallest_nb(s->stack_b);
// 	}
// 	return (small);
// }

int*	verify_small(t_stacks *s,int *small, int *len)
{
	
	while (*small != (s->stack_a->tail->pos + 1))
	{
		if (*small == 1)
			return (small);
		if (s->stack_a->head->pos == *small)
			rotate_a(s->stack_a);
		else	
			push_b(s->stack_a, s->stack_b);
		(*len)++;
		*small = smallest_nb(s->stack_b);
	}
	return (small);
}

int	which_half(t_stack *stack, int small)
{
	t_dlist	*temp;
	int		count;

	temp = stack->head;
	count = 1;
	while (temp->pos != small)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

void	simple_sort(t_stacks *s)
{
	int	big;
	int	small;

	small = smallest_nb(s->stack_a);
	big = biggest_nb(s->stack_a);
	if (s->stack_a->head->pos == big)
		rotate_a(s->stack_a);
	else if (s->stack_a->head->next->pos == big)
		reverse_rotate_a(s->stack_a);
	if (s->stack_a->head->next->pos == small && s->stack_a->tail->pos == big)
		swap_a(s->stack_a);
}

int	is_sorted(t_dlist *lst)
{
	if (lst->pos != 1)
		return (0);
	while (lst->next)
	{
		if (lst->data < lst->next->data)
			lst = lst->next;
		else
			return (0);
	}
	return (1);
}

int	is_reverse_sorted(t_dlist *lst) //tail
{
	if (lst->pos != 1)
		return (0);
	while (lst->prev)
	{
		if (lst->data < lst->prev->data)
			lst = lst->prev;
		else
			return (0);
	}
	return (1);
}

int	smallest_nb(t_stack *stack)
{
	t_dlist	*temp;
	int		small;

	temp = stack->head;
	small = stack->head->pos;
	while (temp)
	{
		if (small > temp->pos)
			small = temp->pos;
		temp = temp->next;
	}
	return (small);
}

int	biggest_nb(t_stack *stack)
{
	t_dlist	*temp;
	int		big;

	temp = stack->head;
	big = stack->head->pos;
	while (temp)
	{
		if (big < temp->pos)
			big = temp->pos;
		temp = temp->next;
	}
	return (big);
}

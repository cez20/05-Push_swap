/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:51:45 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/13 00:15:38 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stacks *s, int len)
{
	int	median;
	int	top_a;

	while (nodes_len(s->stack_b->head) < (len / 2))
	{
		if (s->stack_a->head->index <= (len / 2))
			push_b(s->stack_a, s->stack_b);
		else
			rotate_a(s->stack_a);
	}
	top_a = s->stack_a->head->index;
	push_back_to_a(s, nodes_len(s->stack_b->head));
	median = 0;
	while ((is_sorted(s->stack_a->head) != 1))
	{
		push_chunk(s, &top_a);
		while (s->stack_b->head)
		{
			len = nodes_len(s->stack_b->head);
			median = find_median(s, len);
			while (nodes_len(s->stack_b->head) > (len / 2))
			{
				if (nodes_len(s->stack_b->head) <= 20)
					break ;
				if (s->stack_b->head->index >= median)
					push_a(s->stack_b, s->stack_a);
				else
					rotate_b(s->stack_b);
			}
			selection_sort2(s, nodes_len(s->stack_b->head));
		}
	}
}

// void	push_back_to_a(t_stacks *s, int count) // Cette fonction est assez similaire a celle qui se trouve dans la 2eme boucle while.  
// {
// 	int	new_median;

// 	while (count > 20)
// 	{
// 		new_median = count / 2;
// 		while ((count > 20) && (count > new_median))
// 		{
// 			if (s->stack_b->head->index > new_median)
// 			{
// 				push_a(s->stack_b, s->stack_a);
// 				count--;
// 			}
// 			else
// 				rotate_b(s->stack_b);
// 		}
// 		selection_sort1(s, count);
// 	}
// 	selection_sort1(s, count);
// }

void	push_back_to_a(t_stacks *s, int len) // Cette fonction est assez similaire
{
	int median;
	
	while (s->stack_b->head)
	{
		len = nodes_len(s->stack_b->head);
		median = find_median(s, len);
		while (nodes_len(s->stack_b->head) > (len / 2))
		{
			if (nodes_len(s->stack_b->head) <= 20)
			{
				selection_sort2(s, nodes_len(s->stack_b->head));
				break ;
			}
			if (s->stack_b->head->index >= median)
				push_a(s->stack_b, s->stack_a);
			else
				rotate_b(s->stack_b);
		}
	}
	if (s->stack_a->head->index == 1 && is_sorted(s->stack_a->head) != 1)
		rotate_a(s->stack_a);
}


void	push_chunk(t_stacks *s, int *top)
{
	if (s->stack_a->head->index == *top)
		*top = 1;
	while (s->stack_a->head->index != *top)
	{
		if (s->stack_a->head->index == s->stack_a->tail->index + 1)
			rotate_a(s->stack_a);
		else
			push_b(s->stack_a, s->stack_b);
	}
	if (nodes_len(s->stack_b->head) <= 20)
		selection_sort2(s, nodes_len(s->stack_b->head));
}

int	find_median(t_stacks *s, int len)
{
	t_node	*temp;
	int		temp_stack[500];
	int		i;
	int		median;

	i = 0;
	temp = s->stack_b->head;
	while (temp)
	{
		temp_stack[i++] = temp->index;
		temp = temp->next;
	}
	temp_stack[i] = '\0';
	bubble_sort(temp_stack, len);
	median = temp_stack[len / 2];
	return (median);
}

void	bubble_sort(int *tab, int size)
{
	int	i;
	int	c;
	int	swap;

	i = 0;
	c = 0;
	while (c < size)
	{
		while (i < (size - 1))
		{
			if (tab[i] > tab[i + 1])
			{
				swap = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = swap;
			}
			i++;
		}
		i = 0;
		c++;
	}
}

void	selection_sort1(t_stacks *s, int len)
{
	int	small;
	int	nb_location;

	while (len > 0)
	{
		small = smallest_nb(s->stack_b);
		verify_small(s, &small, &len);
		nb_location = which_half(s->stack_b, small);
		while (s->stack_b->head->index != small)
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

void	selection_sort2(t_stacks *s, int len)
{
	int	big;
	int	nb_location;

	while (len > 0)
	{
		big = biggest_nb(s->stack_b);
		nb_location = which_half(s->stack_b, big);
		while (s->stack_b->head->index != big)
		{
			if (s->stack_b->head->index == s->stack_a->tail->index + 1)
			{
				push_a(s->stack_b, s->stack_a);
				rotate_a(s->stack_a);
				len--;	
			}
			else if (nb_location <= (len / 2))
				rotate_b(s->stack_b);
			else 
				reverse_rotate_b(s->stack_b);
		}
		push_a(s->stack_b, s->stack_a);
		len--;
	}
}

int	*verify_small(t_stacks *s, int *small, int *len)
{
	while (*small != (s->stack_a->tail->index + 1))
	{
		if (*small == 1)
			break ;
		push_b(s->stack_a, s->stack_b);
		(*len)++;
		*small = smallest_nb(s->stack_b);
	}
	return (small);
}

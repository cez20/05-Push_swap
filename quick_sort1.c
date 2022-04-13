/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:12:21 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/12 23:59:05 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stacks *s, int len)
{
	int	median;

	while (dlst_len(s->stack_b->head) < (len / 2))
	{
		if (s->stack_a->head->index <= (len / 2))
			push_b(s->stack_a, s->stack_b);
		else
			rotate_a(s->stack_a);
	}
	push_back_to_a(s, dlst_len(s->stack_b->head));

	median = 0;
	while ((is_sorted(s->stack_a->head) != 1) && (dlst_len(s->stack_b->head) == 0))
	{
		first_sort(s);
		while (s->stack_b->head)
		{
			len = dlst_len(s->stack_b->head);
			median = find_median(s, len);
			while ((dlst_len(s->stack_b->head) > (len / 2)))
			{
				if (dlst_len(s->stack_b->head) <= 20)
				{
					selection_sort1(s, dlst_len(s->stack_b->head));
					break ;
				}
				if (s->stack_b->head->index >= median)
					push_a(s->stack_b, s->stack_a);
				else
					rotate_b(s->stack_b);
			}
		}
	}
}

void	first_sort(t_stacks *s)
{
	while (s->stack_a->head->index != 1)
	{
		if (s->stack_a->head->index == s->stack_a->tail->index + 1)
			rotate_a(s->stack_a);
		else
			push_b(s->stack_a, s->stack_b);
	}
	if (dlst_len(s->stack_b->head) <= 20)
		selection_sort1(s, dlst_len(s->stack_b->head));
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

void	push_back_to_a(t_stacks *s, int count) // Cette partie est assez similaire a celle de la deuxieme boucle de quick_sort 
{
	int	new_median;

	while (count > 20)
	{
		new_median = count / 2;
		while ((count > 20) && (count > new_median))
		{
			if (s->stack_b->head->index > new_median)
			{
				push_a(s->stack_b, s->stack_a);
				count--;
			}
			else
				rotate_b(s->stack_b);
		}
	}
	selection_sort1(s, count);
}

void	selection_sort1(t_stacks *s, int len)
{
	int	small;
	int	nb_location;

	while (len > 0)
	{
		small = smallest_nb(s->stack_b);
		verify_small(s, &small, &len); // Cette ligne est differente 
		nb_location = which_half(s->stack_b, small);
		while (s->stack_b->head->index != small)
		{
			if (nb_location <= (len / 2))
				rotate_b(s->stack_b);
			else if (nb_location >= (len / 2))
				reverse_rotate_b(s->stack_b);
		}
		push_a(s->stack_b, s->stack_a);
		rotate_a(s->stack_a); //Cette ligne est differente 
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

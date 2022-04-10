/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:12:21 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/10 17:50:02 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort1(t_stacks *s, int len)
{
	int	median;
	int	count;

	median = (len / 2);
	count = 0;
	while (s->stack_a->head)
	{
		while (dlst_len(s->stack_b->head) < median)
		{
			if (dlst_len(s->stack_a->head) <= 25)
			{
				selection_sort2(s, dlst_len(s->stack_a->head));
	 			break ;
			}
			if (s->stack_a->head->pos <= median)
			{
				push_b(s->stack_a, s->stack_b);
				count++;
			}
			else
				rotate_a(s->stack_a);
		}
		median += 25;
	}
	count = 100;
	push_back_to_a(s, count);
	
	median = 50;
	while ((is_sorted(s->stack_a->head) != 1) && (dlst_len(s->stack_b->head) == 0))
	{
		while (s->stack_a->head->pos <= median)
		{
			push_b(s->stack_a, s->stack_b);
		}
		selection_sort1(s, dlst_len(s->stack_b->head));
		median += 25;
	}
	//while ((is_sorted(s->stack_a->head) != 1) && (dlst_len(s->stack_b->head) == 0))
		//irst_sort(s);
	//while (s->stack_a->head->pos <=)
	// while ((is_sorted(s->stack_a->head) != 1) && (dlst_len(s->stack_b->head) == 0))
	// {
	// 	first_sort(s);
	// 	while (s->stack_b->head)
	// 	{
	// 		len = dlst_len(s->stack_b->head);
	// 		median = find_median(s, len);
	// 		while ((dlst_len(s->stack_b->head) > (len / 2)))
	// 		{
	// 			if (dlst_len(s->stack_b->head) <= 20)
	// 			{
	// 				selection_sort1(s, dlst_len(s->stack_b->head));
	// 				break ;
	// 			}
	// 			if (s->stack_b->head->pos >= median)
	// 				push_a(s->stack_b, s->stack_a);
	// 			else
	// 				rotate_b(s->stack_b);
	// 		}
	// 	}
	// }
}

void	first_sort(t_stacks *s)
{
	while (s->stack_a->head->pos != 1)
	{
		if (s->stack_a->head->pos == s->stack_a->tail->pos + 1)
			rotate_a(s->stack_a);
		else
			push_b(s->stack_a, s->stack_b);
	}
	if (dlst_len(s->stack_b->head) <= 20)
		selection_sort1(s, dlst_len(s->stack_b->head));
}

int	find_median(t_stacks *s, int len)
{
	t_dlist	*temp;
	int		temp_stack[500];
	int		i;
	int		median;

	i = 0;
	temp = s->stack_b->head;
	while (temp)
	{
		temp_stack[i++] = temp->pos;
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

void	push_back_to_a(t_stacks *s, int count) // Cette fonction devra etre ameliorer pour sur
{
	int	new_median;

	while (count > 20)
	{
		new_median = count / 2;
		while ((count > 20) && (count > new_median))
		{
			if (s->stack_b->head->pos > new_median)
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
		verify_small(s, &small, &len);
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

void	selection_sort2(t_stacks *s, int len)
{
	int	small;
	int	nb_location;

	while (len > 0)
	{
		small = smallest_nb(s->stack_a);
		//verify_small(s, &small, &len);
		nb_location = which_half(s->stack_a, small);
		while (s->stack_a->head->pos != small)
		{
			if (nb_location <= (len / 2))
				rotate_a(s->stack_a);
			else if (nb_location >= (len / 2))
				reverse_rotate_a(s->stack_a);
		}
		push_b(s->stack_a, s->stack_b);
		//rotate_a(s->stack_a);
		len--;
	}
}

int	*verify_small(t_stacks *s, int *small, int *len)
{
	while (*small != (s->stack_a->tail->pos + 1))
	{
		if (*small == 1)
			break ;
		push_b(s->stack_a, s->stack_b);
		(*len)++;
		*small = smallest_nb(s->stack_b);
	}
	return (small);
}
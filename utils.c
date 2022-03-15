/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:45:01 by cezmenji          #+#    #+#             */
/*   Updated: 2022/03/15 09:51:27 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	assign_pos(int len, int i, t_dlist *lst)
{
	t_dlist	*temp;
	t_dlist	*small;
	t_dlist	*big;

	while (len >= i)
	{
		temp = lst;
		while (temp->pos != 0)
			temp = temp->next;
		small = temp;
		big = temp;
		while (temp)
		{
			if (small->content > temp->content && temp->pos == 0)
				small = temp;
			if (big->content < temp->content && temp->pos == 0)
				big = temp;
			temp = temp->next;
		}
		small->pos = i++;
		big->pos = len--;
	}
	return (++len);
}

void    error(void)
{
    ft_putstr_fd("Error\n", STDERR_FILENO);
    exit (EXIT_FAILURE);
}

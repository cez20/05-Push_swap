/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:45:01 by cezmenji          #+#    #+#             */
/*   Updated: 2022/04/10 12:32:29 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	positioning(int len, t_dlist *lst)
{
	t_dlist	*temp;
	t_dlist	*smallest;
	int		pos;

	pos = 1;
	while (pos <= len)
	{
		temp = lst;
		while (temp->pos != 0)
			temp = temp->next;
		smallest = temp;
		while (temp != NULL)
		{
			if (smallest->data > temp->data && temp->pos == 0)
				smallest = temp;
			temp = temp->next;
		}
		smallest->pos = pos;
		pos++;
	}
}

void	print_dlist(t_dlist *head)
{
	int	i;

	i = 1;
	while (head != NULL)
	{
		printf("%d is %d position from the top of linked list\n", head->data, i);
		head = head->next;
		i++;
	}
	printf("\n");
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

void	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit (EXIT_FAILURE);
}

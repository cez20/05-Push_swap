/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:36:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/15 10:21:37 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dlst_add_back(t_dlist **head, t_dlist *new)
{
	t_dlist	*temp;

	if (*head == NULL)
	{
		temp = *head;
		*head = new;
		free(temp);
	}
	else
	{
		temp = dlst_last(*head);
		temp->next = new;
		new->prev = temp;
	}
}

void	dlst_add_front(t_dlist **head, t_dlist *new)
{
	if (*head == NULL)
		*head = new;
	else
	{
		(*head)->prev = new;
		new->next = *head;
		*head = new;
	}
}

t_dlist	*dlst_last(t_dlist *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

int	dlst_len(t_dlist *lst)
{
	int	len;

	len = 0;
	if (lst)
	{
		len++;
		while (lst->next)
		{
			lst = lst->next;
			len++;
		}
	}
	return (len);
}

t_dlist	*dlst_new(int content)
{
	t_dlist	*list;

	list = malloc(sizeof(*list));
	if (!list)
	{
		ft_putstr_fd("Error: Dynamic allocation failed\n", 2);
		exit(EXIT_FAILURE);
	}
	list->content = content;
	list->next = NULL;
	list->prev = NULL;
	list->pos = 0;
	return (list);
}

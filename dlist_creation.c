/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:36:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/10 12:13:37 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dlist_creation(t_stack *stack_a, char **argv)
{
	t_dlist	*temp;
	char	**args;
	int		i;
	int		j;

	i = 1;
	j = 0;
	args = &argv[i];
	if (ft_strchr1(argv[i], ' ') == 0)
		args = ft_split(argv[i++], ' ');
	while (args[j])
	{
		temp = dlst_new(ft_atoi(args[j++]));
		dlst_add_back(&stack_a->head, temp);
	}
	stack_a->tail = dlst_last(stack_a->head);
	free_args(args, i, j);
}

t_dlist	*dlst_new(int data)
{
	t_dlist	*list;

	list = malloc(sizeof(*list));
	if (!list)
	{
		ft_putstr_fd("Malloc failed\n", 2);
		exit(EXIT_FAILURE);
	}
	list->data = data;
	list->next = NULL;
	list->prev = NULL;
	list->pos = 0;
	return (list);
}

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

t_dlist	*dlst_last(t_dlist *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	free_args(char **args, int i, int j)
{
	if (i == 2)
	{
		while (j > 0 && args[--j])
			free(args[j]);
		free(args);
	}
}

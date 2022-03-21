/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:36:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/20 20:03:06 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strchr1(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (0);
		i++;
	}
	if (s[i] == (char)c)
		return (0);
	return (1);
}

void	create_dlist(t_stack *stack_a, char **argv)
{
	t_dlist	*temp;
	char	**args;
	int		i;
	int 	j;

	i = 1;
	j = 0;
	args = &argv[i];
	if (ft_strchr1(argv[i], ' ') == 0)
		args = ft_split(argv[i], ' ');
	int_validation(args);
	while (args[j])
	{
		temp = dlst_new(ft_atoi(args[j++]));
		dlst_add_back(&stack_a->head, temp);
		stack_a->tail = dlst_last(stack_a->head);
	}
	while (j > 0 && args[--j]) // This part is only necessary if ft_split was used. how to distinguish args from malloc one or unmalloc
		free(args[j]);
	free(args);
}

void	int_validation(char **args)
{
	check_duplicate(args, 0);
	check_if_int(args, 0);
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



t_dlist	*dlst_new(int data)
{
	t_dlist	*list;

	list = malloc(sizeof(*list));
	if (!list)
	{
		ft_putstr_fd("Error: Dynamic allocation failed\n", 2);
		exit(EXIT_FAILURE);
	}
	list->data = data;  //change made here
	list->next = NULL;
	list->prev = NULL;
	list->pos = 0;
	return (list);
}

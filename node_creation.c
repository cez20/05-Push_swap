/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:36:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/12 22:04:22 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_nodes(t_stack *stack_a, char **argv)
{
	t_node	*temp;
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
		temp = node_new(ft_atoi(args[j++]));
		node_add_back(&stack_a->head, temp);
	}
	stack_a->tail = node_last(stack_a->head);
	free_args(args, i, j);
}

t_node	*node_new(int data)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	if (!node)
	{
		ft_putstr_fd("Malloc failed\n", 2);
		exit(EXIT_FAILURE);
	}
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	node->index = 0;
	return (node);
}

void	node_add_back(t_node **head, t_node *new)
{
	t_node	*temp;

	if (*head == NULL)
	{
		temp = *head;
		*head = new;
		free(temp);
	}
	else
	{
		temp = node_last(*head);
		temp->next = new;
		new->prev = temp;
	}
}

t_node	*node_last(t_node *node)
{
	if (node)
	{
		while (node->next)
			node = node->next;
	}
	return (node);
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

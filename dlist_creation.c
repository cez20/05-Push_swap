/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:36:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/14 17:19:38 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    create_dlist (t_stack *stack_a, char **argv)
{
    t_dlist *temp;  
    char    **args; 
    int     i;
    int     j;

    i = 1;
    j = 0;
    check_duplicate(argv, 1); 
    while (argv[i]) 
    {
        args = ft_split(argv[i++], ' '); 
        check_duplicate(args, 0); 
        while (args[j])
        {
			if (ft_isint(args[j]) == 0) 
                error();
            temp = dlst_new(ft_atol(args[j++])); 
            dlst_add_back(&stack_a->head, temp);
        }
        stack_a->tail = dlst_last(stack_a->head);
        while (j > 0 && args[--j])
            free(args[j]);
        free (args);
        j = 0;   
    }
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
	list->content = content; // Est egal au chiffre donne 
	list->next = NULL;
	list->prev = NULL;
	list->pos = 0; // Ce chiffre obtient la position 0 dans la linked list.  
	return (list); // Retourne un pointeur vers la liste complete. 
}

void	dlst_clear(t_stack *stack)
{	
	t_dlist	*temp;

	if (stack->head == NULL)
		return ;
	while (stack->head)
	{
		temp = stack->head->next;
		free(stack->head);
		stack->head = temp;
	}
}
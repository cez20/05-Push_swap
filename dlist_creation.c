/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:36:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/14 15:51:57 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    create_dlist (t_stack *stack_a, char **argv)
{
    t_dlist *temp;  //Creation de type d_list qui contient un int, *next, *prev, int position
    char    **args; // Double pointeur 
    int     i;
    int     y;
	//int 	j; //Example pour tester. 

    i = 1;
    y = 0;
    check_duplicate(argv, 1); //Validation des arguments lorsqu'ils ne sont pas en double quote Ex: push_swap 1 4 5
    while (argv[i]) // Tant qu'il y a des arguments. argv[i] equivaut au premier argument
    {
        args = ft_split(argv[i++], ' '); //Fait ft_split avec 1er argument seulement. Ex: push_swap "14 15 16". Args va devenir les 3 chiffres. Sinon, il va prendre chaque argument
		//j = 0;
		//while (args[j])
		//{
		//	printf("%s\n", args[j]);
		//	j++;
		//}
        check_duplicate(args, 0); //Validation des chiffres lorsque les chiffres sont entre "double quote"
		printf("Valider le duplicate\n");
        while (args[y])
        {
			if (ft_isint(args[y]) == 1) // Je pourrais remplacer par ft_atol == 0 en prenant mon ft_atol. 
                error();
			printf("Valider le INT_MIN, INT_MAX\n");
            temp = dlst_new(ft_atoi(args[y++])); // Cree un new node avec le chiffre donne 
			printf("Number:%d node was created\n", temp->content);
            dlst_add_back(&stack_a->head, temp);
        }
        stack_a->tail = dlst_last(stack_a->head);
        while (y > 0 && args[--y])
            free(args[y]);
        free (args);
        y = 0;   
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
		printf("%d\n", new->content);
	}
	else
	{
		temp = dlst_last(*head);
		temp->next = new;
		new->prev = temp;
		printf("%d or %d is added at back of %d\n", new->content, temp->next->content, new->prev->content);
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
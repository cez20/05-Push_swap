/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:36:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/10 13:38:45 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
    t_stacks    *stacks;  // Declare une pointeur sur t_stacks. t_stacks contient la stack_a et b
    int         len;   //Variable servant probablement a calculer le nombre de chiffres sur la stack

    stacks = initialize_stacks(); // nous avons alloue de la memoire a toutes les structures! 
    if (argc > 1) // Si le nombre d'arguments est plus grand que 1, car 1 est le nom du programme lui-meme
    {
        create_dlist(stacks->stack_a, argv);
        len = dlst_len(stacks->stack_a->head);
        assign_pos(len, 1, stacks->stack_a->head);
        clear_stacks(stacks);
    }
    return (0);
}

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

void    check_duplicate(char **argv, int i)
{
    int y;

    while (argv[i])
    {
        y = i + 1;
        while (argv[y])
        {
            if (ft_strcmp(argv[i], argv[y]) == 0)
                error();
            y++;
        }
        i++;
    }
}

int	ft_isint(char *str)
{
	int		i;
	long	temp;

	i = 0;
	temp = ft_atol(str); 
	if (temp < INT_MIN || temp > INT_MAX) //Verifie que le chiffre respecte bien le INT_MAX et INT_MIN
		return (1);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i++]) == 0) //Verifie que ce sont bien des chiffres et aucune lettre! 
			return (1);
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

long	ft_atol(const char *nptr)
{
	long long	num;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		nptr++;
	if (nptr[i] == '-')
		sign = sign * -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		nptr++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + nptr[i] - '0';
		nptr++;
	}
	return (num * sign);
}

/*long	ft_atol(const char *str)
{
	int	    i;
	int	    nb_neg;
	long    number;

	i = 0;
	nb_neg = 0;
	number = 0;
	//while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		//i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nb_neg += 1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{	
		number = number * 10 + str[i] - '0';
		i++;
	}
	if ((nb_neg % 2) == 1)
		number *= -1;
    if (number > INT_MAX || number < INT_MIN)
        error();
	return (number);
}*/
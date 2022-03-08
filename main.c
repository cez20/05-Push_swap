/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cezmenji <cezmenji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:55:41 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/07 18:00:16 by cezmenji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    error(void)
{
    ft_putstr_fd("Error\n", STDERR_FILENO);
    exit (EXIT_FAILURE);
}

int	ft_atol(const char *str)
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
}

void    check_if_int(int argc, char **argv)
{
    while (argc > 0)
    {
        if (ft_atol(argv[argc]) == 0) // Donc si la string passe donne 0 , c-a-d qu'il ne s'agit pas d'un chiffre.
            error();
        argc--;
    }
}

int main (int argc, char **argv)
{
    t_stack   *head;  //head est le premier element de la linked list. 

    head = NULL;
    if (argc > 1)
    {
        argc = (argc - 1);
        check_if_int (argc, argv);
        while (argc > 0)
        {
            push (&head, ft_atol(argv[argc]));
            argc--;   
        }
    }
    return (0);
}
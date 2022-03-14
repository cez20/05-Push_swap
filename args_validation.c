/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:06:50 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/14 15:41:31 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:06:50 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/10 11:52:09 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	int_validation(char **argv)
{
	char	**args;

	args = &argv[1];
	if (ft_strchr1(argv[1], ' ') == 0)
		args = ft_split(argv[1], ' ');
	check_duplicate(args, 0);
	check_if_int(args, 0);
}

void	check_duplicate(char **argv, int i)
{
	int	y;

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

void	check_if_int(char **str, int i)
{
	long	temp;
	int 	j;

	j = 0;
	while (str[i])
	{
		temp = ft_atol(str[i]);
		if (temp < INT_MIN || temp > INT_MAX)
			error();
		if (str[i][j] < 43 || str[i][j] > 57)
			error();
		if (str[i][j] == ',' || str[i][j] == '.' || str[i][j] == '/')
			error();
		i++;
	}
}

long	ft_atol(const char *str)
{
	int		i;
	int		nb_neg;
	long	number;

	i = 0;
	nb_neg = 0;
	number = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
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
		return (number * -1);
	return (number);
}

int	ft_strchr1(const char *s, int c)
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

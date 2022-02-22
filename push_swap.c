/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:55:41 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/02/15 14:18:40 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int main(int argc, char *argv[])
{
    int stack_a[100]; // ici je d/clare ma 1`ere stack qui est d'une grosseur de 100
    int stack_b[100]; // ici je declare ma 2e stack qui est d'une grosseur de 100
    int number;
    int i;

   if (argc > 1)
    {
        i = 0;
        number = 0;
        while (argc > 1)
        {
            argc = (argc - 1);
            number = ft_atoi(argv[argc]);
            tab[i] = number;
            i++;
        }      
        printf("%d\n", tab[0]); 
        printf("%d\n", tab[1]);  
        printf("%d\n", tab[2]);  
        printf("%d\n", tab[3]);  
        printf("%d\n", tab[4]);  
    }
    return (0);
}
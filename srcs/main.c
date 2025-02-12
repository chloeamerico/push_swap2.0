/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:46:28 by chloeameric       #+#    #+#             */
/*   Updated: 2025/02/12 13:53:29 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// print_stack(a);
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (write(1, "\n", 1), 0);
	if (check_args(argc, argv) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	a = NULL;
	b = NULL;
	main2(argc, argv, &a);
	if (check_double(a))
	{
		write(1, "Error\n", 6);
		free_stack(&a);
		return (0);
	}
	which_algo(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

void	main2(int argc, char **argv, t_stack **a)
{
	int		i;
	int		j;
	char	**numbers;

	i = 1;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		if (!numbers || !numbers[0])
			free_split(numbers);
		else
		{
			j = 0;
			while (numbers[j])
			{
				create_node_last(a, ft_atoi(numbers[j]));
				j++;
			}
			free_split(numbers);
		}
		i++;
	}
}

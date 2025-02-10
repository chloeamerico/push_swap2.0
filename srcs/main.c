/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:46:28 by chloeameric       #+#    #+#             */
/*   Updated: 2025/02/10 15:59:17 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	i; // pour parcourir les argv
	int j; // pour parcourir les arguments qui ont ete divises grace au split
	char	**numbers; //tableau temporaire pour stocker les nb apres le split

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	if (check_args(argc, argv) == 1) //check si c'est valide et les limites
	{
		write(1, "Error\n", 6);
		return (0);
	}
	
	a = NULL;
	b = NULL;
	i = argc - 1;
	while(i >= 1)
	{
		numbers = ft_split(argv[i], ' ');
		j = 0;
		while (numbers[j])
		{
			create_node_first(&a, ft_atoi(numbers[j]));
			j++;
		}
		free_split(numbers);
		i--;
	}
	if (check_double(a)) // check les doubles dans a
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

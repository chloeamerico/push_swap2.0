/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:19:02 by camerico          #+#    #+#             */
/*   Updated: 2025/02/12 13:16:52 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// NORMALISER ET TRIER

// dupliquer les valeurs de a dans un tableau
int	*dupplicate_in_array(t_stack *stack)
{
	int	*array;
	int	size;
	int	i;

	size = stack_size(stack);
	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (stack)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (array);
}

// parcourir chaque nombre et leur attribuer un index
void	search_index(t_stack *stack)
{
	int		i;
	int		index;
	int		size;
	t_stack	*current;
	int		*array;

	size = stack_size(stack);
	current = stack;
	array = dupplicate_in_array(stack);
	if (array == NULL)
		return ;
	while (current)
	{
		i = 0;
		index = 0;
		while (i < size)
		{
			if (current->value > array[i])
				index++;
			i++;
		}
		current->index = index;
		current = current->next;
	}
	free(array);
}

// trouver l'index le plus grand, et donc le nombre de bit a utiliser.
// puis calculer le nb de bits qui corrsp a cet index qd on le passe en base 2
int	nb_of_bits(t_stack *stack)
{
	int	index_max;
	int	bits;

	bits = 0;
	index_max = 0;
	search_index(stack);
	while (stack)
	{
		if (stack->index > index_max)
			index_max = stack->index;
		stack = stack->next;
	}
	while (index_max > 0)
	{
		index_max /= 2;
		bits++;
	}
	return (bits);
}

//fonction pour verifier un bit specifique
int	check_bit(int index, int bit)
{
	return ((index >> bit) & 1);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

	size = stack_size(*a);
	max_bits = nb_of_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (check_bit((*a)->index, i))
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

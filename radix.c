/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloeamerico <chloeamerico@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:19:02 by camerico          #+#    #+#             */
/*   Updated: 2025/01/31 16:02:36 by chloeameric      ###   ########.fr       */
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

	size = stack_size(stack); //on determine la taille de la pile
	array = malloc(sizeof(int) * size);  //on alloue un tableau dynamique pourstocker les valeurs
	if (!array)
		return(NULL);
	i = 0;
	while(stack)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (array);
}

// parcourir chaque nombre et leur attribuer un index
void	search_index(t_stack *stack, int *array)
{
	int	i; // pour parcourir le tableau
	int	index; // valeur a attribuer au champ "index" de la structure
	int	size;
	t_stack	*current; //pointeur pour parcourir la pile

	size = stack_size(stack);
	current = stack;
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
}

// trouver l'index le plus grand, et donc le nombre de bit a utiliser.
// puis calculer le nb de bits qui correspondent a cet index auqnd on le passe en base 2
int	nb_of_bits(t_stack *stack)
{
	int	index_max;
	int	bits;

	bits = 0;
	index_max = 0;
	while (stack)
	{
		if (stack->index > index_max)
			index_max = stack->index; // dans un premier temps on trouve l'index max
		stack = stack->next; 
	}
	while (index_max > 0)
	{
		index_max /= 2;
		bits++; // puis on calcule cb de bits seront necessaires, ce qui correspondra au nb de coups
	}
	return (bits);
}

//fonction pour verifier un bit specifique
int check_bit(int index, int bit)
{
    return (index >> bit) & 1; // Décale les bits et vérifie si le bit est 0 ou 1
}



// A VERIFIER - VERSION CHAT GPT

void radix_sort(t_stack **a, t_stack **b)
{
    int max_bits;	// Nombre de bits nécessaires
    int size;
    int i;	// Bit actuel
    int j;  // Pour parcourir les éléments de la pile

    size = stack_size(*a);
    max_bits = nb_of_bits(*a);

    i = 0;
    while (i < max_bits)	// Parcourir chaque bit (0 à max_bits - 1)
    {
        j = 0;
        while (j < size)	 // Parcourir tous les éléments de 'a'
        {
            if (check_bit((*a)->index, i))	// Vérifie si le iᵉ bit est 1
                ra(*a);				// Conserver dans 'a' avec ra
            else
                pb(a, b);				// Déplacer dans 'b' avec pb
            j++;
        } 
        while (*b)				// Réintégrer tous les éléments de 'b' dans 'a'
            pa(a, b);
        i++;
    }
}

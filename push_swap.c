/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:53:36 by camerico          #+#    #+#             */
/*   Updated: 2025/01/21 17:41:15 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack *init_stack(int value)
// {
// 	t_stack *stack;

// 	stack = malloc(sizeof(t_stack));
// 	if (!stack)
// 		return (NULL);
// 	stack->value = value;
// 	stack->index = -1;
// 	stack->next = NULL;
// 	return (stack);
// }

// void *add_first(int value, t_stack *stack)
// {
// 	t_stack	*new;
	
// 	new = malloc(sizeof(*new));
// 	if (!new)
// 		return;
// 	new->value = value;
// 	new->index = 1;
// 	new->next = NULL;
// }

// fonction pour cree un nouveau noeud avec la valeur qu'il doit stocker
t_stack *new_node(int value)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

// fonction pour ajouter un noeud en haut de la stack
void	add_first(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

// OU on fusionne les deux du dessus
t_stack	*create_node_first(t_stack **stack, int	value)
{
	t_stack	*new;
	
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = *stack;

	*stack = new;
	return (new); //peut etre renvoyer *stack ??
}

// // initialiser une pile a vide
// t_stack	*init_empty_stack(void)
// {
// 	return (NULL);
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	i;

	if (check_args == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	i = argc - 1;
	while(i > 0)
	{
		create_node_first(&stack_a, ft_atol(argv[i]));
		i--;
	}
	
	
	return (0);
}
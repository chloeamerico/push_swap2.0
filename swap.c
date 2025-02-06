/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:18:00 by camerico          #+#    #+#             */
/*   Updated: 2025/02/06 15:45:56 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// //version ou on ne modifie que les valeurs et non les pointeurs.
// void	swap(t_stack *stack)
// {
// 	int	tmp;		//variable temporaire pour stocker la valeur

// 	tmp = 0;
// 	if (stack && stack->next) //verifie si la pile a au moins 2 elemnts
// 	{
// 		tmp = stack->next->value;
// 		stack->next->value= stack->value;
// 		stack->value = tmp;
// 	}
// }

// //version ou on change directement les pointeurs de la pile pour echanger les deux premiers noeuds.
void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;

		first->next = second->next; // le premier noeud pointe sur le 3e
		second->next = first; // le deuxieme noeud pointe vers le premier
		*stack = second; // le second noeud devient la tête de la pile 
	}
}

void	sa(t_stack **a, int *steps)
{
	swap(a);
	printf("sa\n"); //ATTENTION !! mettre ft_printf avant de push
	(*steps)++;
}

void	sb(t_stack **b, int *steps)
{
	swap(b);
	printf("sb\n");
	(*steps)++;
}

void	ss(t_stack **a, t_stack **b, int *steps)
{
	swap(a);
	swap(b);
	printf("ss\n");
	(*steps)++;
}
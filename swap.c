/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloeamerico <chloeamerico@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:18:00 by camerico          #+#    #+#             */
/*   Updated: 2025/01/29 20:45:55 by chloeameric      ###   ########.fr       */
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
		second = *stack; // le second noeud devient la tête de la pile 
	}
}

void	sa(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
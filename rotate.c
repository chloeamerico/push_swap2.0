/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloeamerico <chloeamerico@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:28:21 by chloeameric       #+#    #+#             */
/*   Updated: 2025/01/29 19:29:58 by chloeameric      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// // Décale d’une position vers le haut tous les élements de la pile a.
// // Le premier élément devient le dernier.
// void	rotate(t_stack *stack)
// {
// 	int	tmp;
// 	if (stack && stack->next)
// 	{
// 		tmp = stack->value;
// 		while (stack->next)
// 		{
// 			stack->value = stack->next->value;
// 			stack = stack->next;
// 		}
// 		stack->value = tmp;
// 	}
// }

//version ou on modifie directement les pointeurs au lieu de la valeur
void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = *stack;

		while (last->next)
			last = last->next; // on a determine le dernier pointeur de la pile
		
		*stack = first->next; //mise a jour des pointeurs
		first->next = NULL; //le premier noeud devient devient le dernier et donc pointe sur NULL
		last->next = first; // le dernier passe avant dernier car son next pointe sur first qui vient de passer dernier.
	}
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
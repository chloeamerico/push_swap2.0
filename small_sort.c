/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:54:05 by camerico          #+#    #+#             */
/*   Updated: 2025/02/04 15:01:47 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
	t_stack	*second;
	t_stack	*third;
	
	if (stack_size(*a) < 2)
		return ;
	second = (*a)->next;
	third = second->next;
	if (stack_size(*a) == 2 && ((*a)->value > second->value))
		sa(a);
	else if (stack_size(*a) == 3)
	{
		if ((*a)->value > second->value && (*a)->value > third->value)
			ra(a);
		else if (second->value > (*a)->value && second->value > third->value)
			rra(a);
		if ((*a)->value > second->value)
			sa(a);
	}
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	index_min;

	if (stack_size(*a) <= 3)
	{
		sort_3(a);
		return;
	}
	while (stack_size(*a) > 3)
	{
		index_min = find_index_min(*a);
		if (index_min == 0)
			pb(a, b);
		else if (index_min <= (stack_size(*a) / 2))
			ra(a);
		else
			rra(a);
	}
	sort_3(a); 
	if (stack_size(*b) > 1 && (*b)->value < (*b)->next->value) // pour gerer le cas ou on travaille avec 4 nb, donc seulement 1 nb dans stack b
		sb(b);
	while (stack_size(*b) > 0)
		pa(b, a);
}

int	find_index_min(t_stack *a)
{
	int	index_min;
	int	current_index;
	int	min_value;
	t_stack	*current;

	index_min = 0;
	current_index = 0;
	current = a;
	min_value = current->value;
	while (current_index < stack_size(a)) // ou juste while (current) ??
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			index_min = current_index;
		}
		current_index++;
		current = current->next;
	}
	return (index_min);	
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:54:05 by camerico          #+#    #+#             */
/*   Updated: 2025/02/12 13:17:13 by camerico         ###   ########.fr       */
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
	if (!third)
	{
		if ((*a)->value > second->value)
			sa(a);
		return ;
	}
	if ((*a)->value > second->value && (*a)->value > third->value)
		ra(a);
	else if (second->value > (*a)->value && second->value > third->value)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	index_min;

	index_min = 0;
	if (stack_size(*a) <= 3)
	{
		sort_3(a);
		return ;
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
	while (stack_size(*b) > 0)
		pa(a, b);
}

int	find_index_min(t_stack *a)
{
	int		index_min;
	int		current_index;
	int		min_value;
	t_stack	*current;

	index_min = 0;
	current_index = 0;
	current = a;
	min_value = a->value;
	while (current)
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

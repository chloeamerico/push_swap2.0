/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:52:57 by camerico          #+#    #+#             */
/*   Updated: 2025/01/23 12:46:41 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* ************************************************************************** */
/* INCLUDES                                                                   */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
#include <limits.h>

/* ************************************************************************** */
/* DEFINES                                                                    */
/* ************************************************************************** */

/* ************************************************************************** */
/* STRUCTURES                                                                 */
/* ************************************************************************** */

typedef struct 		s_stack
{
	int				value; //valeur stockee dans le noeud
	int				index; // index de l'element dans la pile
	struct s_stack 	*next; //pointe vers le prochain element
} t_stack;

// typedef struct s_stack_info
// {
// 	t_stack			*head; //pointe vers le sommet de la pile
// 	int				size; //taille actuelle de la pile
// } t_stack_info;


/* ************************************************************************** */
/* PROTO                                                                      */
/* ************************************************************************** */

int valid_number(char *str);
int check_args(int argc, char **argv);
int	check_limits(t_stack *stack);
int check_double(t_stack *stack);
t_stack *new_node(int value);
void	add_first(t_stack **stack, t_stack *new);
t_stack	*create_node_first(t_stack **stack, int	value);
void	sort_3(t_stack *a, t_stack *b);


/* ************************************************************************** */
/* DEBUG                                                                      */
/* ************************************************************************** */

#endif
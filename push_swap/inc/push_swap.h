/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:00:40 by jcallejo          #+#    #+#             */
/*   Updated: 2024/07/15 12:47:24 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/inc/libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				current_pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_data;

void	pa(t_data *data);
void	pb(t_data *data);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

/**
 * @brief Converts string to long
 * 
 * @param str 
 * @return long 
 */
long	ft_atol(const char *str);

/**
 * @brief Function to get last node
 * 
 * @param stack 
 * @return t_stack* 
 */
t_stack	*ft_last_node(t_stack *stack);

/**
 * @brief Creates the stack
 * 
 * @param argc 
 * @param argv 
 * @return t_stack 
 */
t_stack	*ft_init(int argc, char **argv);

/**
 * @brief Check all the members in stack are numbers
 * 
 * @param split 
 * @return int 
 */
int		ft_check_numbers(char **split);

/**
 * @brief Check if all members in stack are int
 * 
 * @param split 
 * @return int 
 */
int		ft_check_range(char **split);

/**
 * @brief Cleans arrays
 * 
 * @param array 
 */
void	ft_clean_array(char **array);

/**
 * @brief Cleans stacks
 * 
 * @param stack 
 */
void	ft_clean_stack(t_stack *stack);

/**
 * @brief Checks if provided stack is sorted
 * 
 * @param stack 
 * @return int 
 */
int		ft_check_sorted(t_stack *stack);

/**
 * @brief Check errors in provided stack
 * 
 * @param data 
 * @return int 
 */
int		ft_errors(t_data *data);

/**
 * @brief Strlen, but with stacks
 * 
 * @param stack 
 * @return int 
 */
int		ft_stack_size(t_stack *stack);

/**
 * @brief Indexes stack
 * 
 * @param data 
 */
void	ft_index(t_data *data);

/**
 * @brief Check the sorting of stack, and if not sorted, sorts
 * 
 * @param data 
 */
void	ft_sort(t_data *data);

/**
 * @brief Looks for the position a number has to get to get sorted
 * 
 * @param data 
 */
void	ft_target_pos(t_data *data);

#endif
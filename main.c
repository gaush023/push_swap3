/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 02:36:23 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/22 16:37:36 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

__attribute__((destructor)) static void destructor()
{
	system("leaks -q push_swap");
}

static int	malloc_stacks(t_list ***stack_a, t_list ***stack_b)
{
	*stack_a = (t_list **)malloc(sizeof(t_list));
	*stack_b = (t_list **)malloc(sizeof(t_list));
	if (!*stack_a || !*stack_b)
	{
		if (*stack_a)
			free(*stack_a);
		if (*stack_b)
			free(*stack_b);
		return (-1);
	}
	**stack_a = NULL;
	**stack_b = NULL;
	return (0);
}

static void	create_stacks(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	if (argc == 2)
		free_split(args);
}

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		flag;

	if (argc < 2)
		return (0);
	flag = ft_check_argc(argc, argv);
	if (flag < 0)
		return (ft_print_error(flag));
	if (malloc_stacks(&stack_a, &stack_b) == -1)
		return (ft_print_error(-5));
	create_stacks(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	execute_sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

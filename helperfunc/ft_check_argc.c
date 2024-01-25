/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:30:42 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/25 16:32:34 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helperfunc.h"

static int	ft_check_duplication(char **args, int i)
{
	int	j;
	int	tmp;

	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		j = i + 1;
		while (args[j])
		{
			if (tmp == ft_atoi(args[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_maximamu(char **args, int i)
{
	int	j;

	while (args[i])
	{
		j = 0;
		while (args[i][j] != '\0')
			j++;
		if (j > 11)
			return (-1);
		if (ft_atoi(args[i]) > INT_MAX || ft_atoi(args[i]) < INT_MIN)
			return (-1);
		i++;
	}
	return (0);
}

static int	ft_check_helper(char **args, int i)
{
	if (args[i][0] == '\0')
		return (-1);
	else if (check_maximamu(args, i) == -1)
		return (-2);
	else if (ft_isnum(args, i) == -1)
		return (-3);
	else if (ft_check_duplication(args, i) == -1)
		return (-4);
	return (0);
}

int	ft_check_argc(int argc, char **argv)
{
	int		i;
	int		flag;
	char	**args;

	i = 0;
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
			return (0);
		args = ft_split(argv[1], ' ');
	}
	else
	{
		i = 1;
		args = argv;
	}
	flag = ft_check_helper(args, i);
	if (argc == 2)
		free_split(args);
	if (flag < 0)
		return (flag);
	return (flag);
}

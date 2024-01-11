/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:45:19 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/11 20:18:04 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helperfunc.h"

int	ft_print_error(int flag)
{
	if (flag == -1)
		ft_putendl_fd("none numbers", 2);
	if (flag == -2)
		ft_putendl_fd("over the maximamu number", 2);
	if (flag == -3)
		ft_putendl_fd("Invalid numbers", 2);
	if (flag == -4)
		ft_putendl_fd("duplicated numbers", 2);
	if (flag == -5)
		ft_putendl_fd("malloc error", 2);
	return (-1);
}

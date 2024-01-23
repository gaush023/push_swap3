/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_array_memory.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:30:10 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/23 20:26:04 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

int	allocate_array_memory(int **array, int size)
{
	*array = (int *)malloc(sizeof(int) * size);
	if (!*array)
		return (-1);
	return (0);
}

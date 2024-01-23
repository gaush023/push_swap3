/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:30:10 by sagemura          #+#    #+#             */
/*   Updated: 2024/01/23 02:43:40 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

void	delete_memory(int **flag)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		free(flag[i]);
		i++;
	}
	free(flag);
}

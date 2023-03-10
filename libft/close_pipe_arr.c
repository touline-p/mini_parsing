/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipe_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:46:01 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/10 21:46:14 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	close_pipe_arr(int **pipe_arr)
{
	while (*pipe_arr)
	{
		close(*pipe_arr[0]);
		close(*pipe_arr[1]);
		pipe_arr++;
	}
}
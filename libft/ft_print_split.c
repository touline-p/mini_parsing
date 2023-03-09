/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:45:17 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/09 23:47:48 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_split(char **split)
{
	while (*split)
	{
		if (write(1, *split, ft_strlen(*split)) == -1
			|| write(1, "\n", 1) == -1)
			write(2, "Error write ft_print_split", 26);
		split++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_block_tree_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:04:39 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/09 22:13:59 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parsing.h"

t_instruction_block_tree	*instruction_block_tree_constructor(void)
{
	t_instruction_block_tree	*new;

	new = malloc(sizeof(t_instruction_block_tree));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->sub_block = NULL;
	new->cmd = NULL;
	new->args = NULL;
	new->fd_in = -1;
	new->fd_out = -1;
	return (new);
}

void	instruction_block_tree_destructor( \
	t_instruction_block_tree *trash \
	        )
{
	if (trash == NULL)
		return ;
	instruction_block_tree_destructor(trash->sub_block);
	instruction_block_tree_destructor(trash->next);
	ft_free_split(trash->args);
	free(trash->cmd);
}
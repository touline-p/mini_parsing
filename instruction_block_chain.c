/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_block_chain.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:32:06 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/09 23:56:16 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parsing.h"


t_ert	*token_lst_to_instruction_block_tree( \
		t_token *tok, \
		char **env, \
		t_instruction_block_tree **tree_pt
		)
{
	(void)tok;
	(void)env;
	t_instruction_block_tree	*new;

	if (instruction_block_tree_constructor_on(&new) == MLC_ERR)
		return (FAILURE);

	return (SUCCESS);
}
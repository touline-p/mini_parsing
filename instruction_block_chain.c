/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_block_chain.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:32:06 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/10 00:18:07 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parsing.h"

static t_ert	_get_next_block_on_and_reset_pin_pt(t_token **pin, \
	t_instruction_block_tree **block_pt);

t_ert	*token_lst_to_instruction_block_tree( \
		t_token *tok, \
		char **env, \
		t_instruction_block_tree **tree_pt
		)
{
	t_instruction_block_tree	*first_block;
	t_token 					*pin;

	if (_get_next_block_on_and_reset_pin_pt(&pin, &first_block) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

static t_ert	_get_next_block_on_and_reset_pin_pt(t_token **pin, t_instruction_block_tree **block_pt)
{
	t_instruction_block_tree	*new;

	if (instruction_block_tree_constructor_on(&new) != SUCCESS)
		return (FAILURE);

	return (SUCCESS);
}
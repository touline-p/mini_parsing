/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_block_chain.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:32:06 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/09 21:50:04 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parsing.h"

static t_instr_blck_tree	*_get_next_block(t_token *tok);

t_instruction_block_tree	*token_lst_to_instruction_block_tree( \
		t_token *tok, \
		char **env \
		)
{
	t_instr_blck_tree	*tree;
	t_token				*pin;

	while (pin->token != EOL)
	{
		tree = _get_next_block(tok);
	}
	token_lst_clear(tok);
}

static t_instr_blck_tree	*_get_next_block(t_token *tok)
{
	t_instr_blck_tree	*block;

	block = instr_blck_tree_constructor();

}


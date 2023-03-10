/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_block_chain.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:32:06 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/10 21:49:23 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "mini_parsing.h"

static t_ert	_init_first_instruction_block(t_string_token **token, t_instruction_block_tree **tree_pt);

t_ert	str_token_to_instruction_block_tree_on(t_string_token *tok, t_instruction_block_tree **tree_pt)
{
	int **pipe_arr;

	if (init_pipe_arr_on(&pipe_arr, tok) != SUCCESS)
		return (FAILURE);
	if (get_block_and_reset_pin())
	if (*tree_pt == NULL)
		return (MLC_ERR);
	string_token_destructor(tok);
	return (SUCCESS);
}

static t_ert	get_block_and_reset_pin(t_string_token **pin, t_instruction_block_tree **tree_pt, int **pipe_arr)
{
	if (instruction_block_tree_constructor_on(tree_pt) == FAILURE)
		return (MLC_ERR);
	(*tree_pt)->fd_in = get_fd_in_from_str_tok(pin);
	(*tree_pt)->fd_out = get_fd_out_from_str_tok(pin);
	(*tree_pt)->args = get_args_from_str_tok(pin);
	if ((*tree_pt)->args == NULL)
		return (MLC_ERR);
	(*tree_pt)->cmd = get_cmd_from_args((*tree_pt)->args);
	if ((*tree_pt)->cmd == NULL)
		return (MLC_ERR);
	return (SUCCESS);
}

int get_fd_in_from_str_tok()
{

}
 */
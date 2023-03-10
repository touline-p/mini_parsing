/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_block_chain.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:32:06 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/10 19:14:13 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parsing.h"


t_ert	str_token_to_instruction_block_tree_on(t_string_token *tok, t_instruction_block_tree **tree_pt)
{
	//t_string_token *tmp;
	(void)tok;

	*tree_pt = instruction_block_tree_constructor();
	if (*tree_pt == NULL)
		return (MLC_ERR);
	string_token_destructor(tok);
	return (SUCCESS);
}

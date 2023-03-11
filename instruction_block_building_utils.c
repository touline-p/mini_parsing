/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_block_building_utils.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:02:15 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/11 21:04:00 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by bpoumeau on 3/11/23.
//

#include "mini_parsing.h"

t_ert	dn(t_instruction_block_tree *block, t_string_token *tok);
t_ert	open_chevron_in(t_instruction_block_tree *block, t_string_token *tok);

t_ert	stock_last_redirect(t_instruction_block_tree *block, t_string_token *tok)
{
	const t_fd_ft	fd_ft_arr[] = {&dn, &dn, &dn, &open_chevron_in, &dn, &dn, &dn, &dn, \
		&dn, &dn, &dn, &dn, &dn, &dn, &dn, &dn, &dn, &dn, &dn, &dn, &dn, &dn};
	t_ert			ret_val;

	ret_val = SUCCESS;
	while (tok->token != EOL && is_control_operator(tok->token) != SUCCESS)
	{
		if (fd_ft_arr[tok->token](block, tok) != SUCCESS)
			ret_val = FAILURE;
		tok = tok->next;
	}
	return (ret_val);
}

t_ert	dn(t_instruction_block_tree *block, t_string_token *tok)
{
	(void)block;
	(void)tok;
	return (SUCCESS);
}

t_ert	open_chevron_in(t_instruction_block_tree *block, t_string_token *tok)
{
	int fd;

	fd = open(tok->next->content, O_RDONLY);
	printf("\n\n\noh damn %d \n\n\n\n", fd);
	if (fd == -1)
		per_n_set_errno((char *)tok->next->content);
	if (fd > 2)
		close(block->fd_in);
	block->fd_in = fd;
	return (SUCCESS);
}
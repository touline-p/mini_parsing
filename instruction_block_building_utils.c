/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_block_building_utils.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:02:15 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/11 17:02:15 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by bpoumeau on 3/11/23.
//

#include "mini_parsing.h"

void	stock_last_redirect(int *fd_out_pt, t_string_tok *tok)
{
	t_string_token *pin;

	pin = tok;
	while (is_control_operator(tok->token) != SUCCESS)
	{

	}
}
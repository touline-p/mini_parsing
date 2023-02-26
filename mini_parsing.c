/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:11:04 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/26 02:33:29 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parsing.h"

static t_token	*_token_lst_constructor_ep(t_token *trash, t_token *ret_val);

t_token	*token_lst_constructor(char *str)
{
	t_token	*token;
	t_token	*pin;
	char 	*tmp;

	token = token_constructor(START, STRT_CHR);
	pin = token;
	tmp = str;
	while (*str != EOSTR)
	{
		pin->next = token_constructor(LETTER, *str);
		if (!pin->next)
			return (_token_lst_constructor_ep(token, NULL));
		pin = pin->next;
		str++;
	}
	pin->next = token_constructor(EOL, EOSTR);
	free(tmp);
	return (token);
}

static t_token	*_token_lst_constructor_ep(t_token *trash, t_token *ret_val)
{
	token_lst_clear(trash);
	return (ret_val);
}
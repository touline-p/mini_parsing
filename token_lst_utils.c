/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:57:21 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/26 19:13:16 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parsing.h"

t_token	*token_constructor(t_emt emt, char msg)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->token = emt;
	new->sign_char = msg;
	new->next = NULL;
	new->esec = UNSECURED;
	new->next_word = NULL;
	return (new);
}

void	token_lst_clear(t_token *trash)
{
	t_token *tmp;

	while (trash)
	{
		tmp = trash->next;
		del_token(trash);
		trash = tmp;
	}
}

void	del_next_token(t_token *token)
{
	t_token *tmp;

	tmp = token->next->next;
	del_token(token->next);
	token->next = tmp;
}

void	del_token(t_token *token)
{
	token_lst_clear(token->next_word);
	free(token);
}
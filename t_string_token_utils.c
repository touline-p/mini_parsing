/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string_token_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 00:25:09 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/10 03:24:44 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parsing.h"

t_string_token	*string_token_creator(void)
{
	t_string_token	*new;

	new = malloc(sizeof(t_string_token));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->content = NULL;
	new->token = NONE;
	return (new);
}

t_ert	string_token_creator_on(t_string_token **tok_pt)
{
	t_string_token *new;

	new = string_token_creator();
	if (new == NULL)
		return (MLC_ERR);
	*tok_pt = new;
	return (SUCCESS);
}

void	string_token_destructor(t_string_token *trash)
{
	t_string_token *tmp;

	if (trash == NULL)
		return ;
	free(trash->content);
	tmp = trash->next;
	free(trash);
	string_token_destructor(tmp);
}

void	cpy_token_lst_to_str(t_token *tok, char *str)
{
	int i;

	str[0] = tok->sign_char;
	tok = tok->next;
	i = 1;
	while (tok->token == LETTER)
	{
		str[i] = tok->sign_char;
		i++;
		tok = tok->next;
	}
	str[i] = 0;
}
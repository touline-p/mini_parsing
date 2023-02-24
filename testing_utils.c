/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:58:54 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/24 01:11:54 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by bpoumeau on 2/21/23.
//

# include "test_mini.h"
# include "basic_enums.h"
# include "mini_parsing.h"


void	display_tokens(t_token *token_lst)
{
	while (token_lst != NULL)
	{
		display_t_emt(token_lst);
		token_lst = token_lst->next;
	}
	printf("\n");
}

void	display_t_emt(t_token *token)
{
	char	*msg;
	int 	i = 0;

	if (token->token == EOL)
		msg = ft_strdup("eol");
	if (token->token == LETTER) {
		if (token->esec == SECURED)
			i += 1;
		msg = malloc(2 + i);
		if (token->esec == SECURED)
			msg[0] = '\\';
		msg[i] = token->sign_char;
		msg[i + 1] = 0;
	} else if (token->token == START)
		msg = ft_strdup("start");
	printf("<%s>", msg);
	free(msg);
}

void	preserv(t_token *tok)
{
	(void)tok;
	//escaping_chars();
	return ;
}

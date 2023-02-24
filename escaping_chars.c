/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escaping_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:12:38 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/24 03:40:53 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parsing.h"

static t_ert	_escaping_chars_ep(void);
static t_ert	_escape_process(t_token *last_pt, t_token *tok);

t_ert	escaping_chars(t_token *tok)
{
	t_token *pin;

	pin = tok->next;
	while (pin->token != EOL)
	{
		printf("start \n");
		printf("tok :");
		display_t_emt(tok);
		put_esec(tok);
		printf("\npin :");
		display_t_emt(pin);
		put_esec(pin);
		printf("\n");
		if (_escape_process(tok, pin) != SUCCESS)
			return (_escaping_chars_ep());
		tok = tok->next;
		printf("tok p : %p\n", tok);
		pin = tok->next;
		printf("pin p : %p\n", pin);
	}
	return (SUCCESS);
}

static t_ert	_escape_process(t_token *last_pt, t_token *tok)
{
	if (tok->token != LETTER
		|| tok->sign_char != '\\'
		|| tok->esec != UNSECURED)
		return (SUCCESS);
	printf("je passe ici\n");
	display_t_emt(tok->next);
	printf("\n");
	if (tok->next->token == EOL)
		return (FAILURE);
	tok->next->esec = SECURED;
	del_next_token(last_pt);
	return (SUCCESS);
}

static t_ert	_escaping_chars_ep(void)
{
	write(2, "syntax error near newline.\nLine can't be end by '\\'\n", 52);
	return (FAILURE);
}

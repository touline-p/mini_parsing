/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escaping_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:12:38 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/24 01:12:38 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_ert	_escaping_chars_ep(void);
static t_ert	_escape_process(t_token *tok);

t_ert	escaping_chars(t_token **tok_pt)
{
	t_token *pin;

	pin = *tok;
	while (pin != NULL)
	{
		if (escape_process(pin) != SUCCESS)
			return (_escaping_chars_ep());
		pin = pin->next;
	}
}

static t_ert	_escape_process(t_token *tok)
{
	if (tok->sign_char != '\\' || tok->esec != UNSECURED)
		return (SUCCESS);
	if (tok->next != NULL)
	{
		tok->next->esec = SECURED;
		return (SUCCESS);
	}
	return (FAILURE);
}

static t_ert	_escaping_chars_ep(void)
{
	write(2, "syntax error near newline.\nLine can't be end by '\\'\n");
	return (FAILURE);
}

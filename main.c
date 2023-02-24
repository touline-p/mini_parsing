/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:33:30 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/24 04:51:02 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>
#include "test_mini.h"
#include "mini_parsing.h"

void	test1()
{
	printf("when \"\"\n");
	t_token *tok = token_lst_constructor(ft_strdup(""));
	display_tokens(tok);
	token_lst_clear(tok);
}

void	test_line(char *str)
{
	printf("when ->%s<-\n", str);
	t_token	*tok = token_lst_constructor(str);
	display_tokens(tok);
	token_lst_clear(tok);
}

void	test_lexing(char *str)
{
	printf("when ->%s<-\nlexed :\n", str);
	t_token *tok = token_lst_constructor(str);
	//t_lexed	*lex = lexor(tok);
	(void)tok;
}

void	test_display_secured(t_token *tok)
{
	printf("test secured ->\\h<-\n");
	display_tokens(tok);
}
void	test_display_unsecured(t_token *hy)
{
	printf("test unsecured ->h<-\n");
	display_tokens(hy);
}

void	test_squote(t_token *tok)
{
	while (tok->token != EOL)
	{
		if (tok->sign_char == '\''
			&& squoting_process(tok->next, &tok) != SUCCESS)
			return ;
		tok = tok->next;
	}
}

void	test_double_quote_launcher(t_token *tok)
{
	while (tok->token != EOL)
	{
		if ((tok->sign_char == '\"')
			&& dquoting_process(tok->next, &tok) != SUCCESS)
			return ;
		tok = tok->next;
	}
}

void	tests_double_quote(void)
{
	t_token *tok;
	printf("when starting with double quote\n->\"test<-\n");
	tok = token_lst_constructor(ft_strdup("\"test"));
	test_double_quote_launcher(tok);
	display_tokens(tok);
	token_lst_clear(tok);
}

void	test_preserv(char *str)
{
	printf("all chars between simple quotes must be protected\n->%s<-\n", str);
	str = ft_strdup(str);
	t_token *tok = token_lst_constructor(str);
	test_squote(tok);
	display_tokens(tok);
	token_lst_clear(tok);
}

void	test_escaping(char *str)
{
	printf("all chars after\\ must be protected\n->%s<-\n", str);
	str = ft_strdup(str);
	t_token *tok = token_lst_constructor(str);
	escaping_chars(tok);
	display_tokens(tok);
	token_lst_clear(tok);
}

int main(int ac, char **av) {

	if (ac != 2)
		return (0);
	test1();
	char *str = ft_strdup(av[1]);
	test_line(str);
	t_token	hy;
	hy.esec = SECURED;
	hy.next = NULL;
	hy.sign_char = 'h';
	hy.token = LETTER;
	test_display_secured(&hy);
	hy.esec = UNSECURED;
	test_display_unsecured(&hy);
	test_preserv(av[1]);
	test_escaping(av[1]);
	tests_double_quote();
	return (0);
}

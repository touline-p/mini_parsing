/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:33:30 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/24 06:49:34 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define S SILENCIEUX
#define B BAVARD

#ifndef SILENCIEUX
# define SILENCIEUX true
#endif
#define BAVARD false

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

t_ert 	test_squote_launcher(t_token *tok)
{
	while (tok->token != EOL)
	{
		if (tok->sign_char == '\''
			&& squoting_process(NULL, tok->next, &tok) != SUCCESS)
			return (FAILURE);
		tok = tok->next;
	}
	return (SUCCESS);
}

t_ert 	test_double_quote_launcher(t_token *tok)
{
	while (tok->token != EOL)
	{
		if ((tok->sign_char == '\"')
			&& dquoting_process(NULL, tok, &tok) != SUCCESS)
			return (FAILURE);
		tok = tok->next;
	}
	return (SUCCESS);
}

void	tests(char *str, t_ert(*launcher)(t_token *), char *msg, bool silence)
{
	if (silence)
		return;
	printf("\n");
	if (msg)
		printf("%s\n", msg);
	printf("pour ->%s<-\n", str);
	t_token *tok = token_lst_constructor(ft_strdup(str));
	display_tokens(tok);
	if (launcher(tok) == SUCCESS)
		display_tokens(tok);
	token_lst_clear(tok);

}
void	tests_double_quote(void)
{
	tests("\"test", test_double_quote_launcher, "erreure ligne non terminee", SILENCIEUX);
	tests("\"test\"", test_double_quote_launcher, "cas normale les char entre quotes sont preserve mais pas les quotes", SILENCIEUX);
	tests("\"t\\e\\\"st\"", test_double_quote_launcher, "slash avant la double quote doit preserver puis partir", SILENCIEUX);
	tests("\"$\"", test_double_quote_launcher, "le $ ne peut pas etre preserve par les double quote", SILENCIEUX);
}

void	tests_simple_quote(void)
{
	tests("\'test\'", test_squote_launcher, "cas normal les char entre quotes sont preserve mais pas les quotes", SILENCIEUX);
	tests("\'test", test_squote_launcher, "cas normal les char entre quotes sont preserve mais pas les quotes", SILENCIEUX);
	tests("\'\'te\'st\'", test_squote_launcher, "seul les char entre quotes sont preserve", SILENCIEUX);
	tests("\'te\'st", test_squote_launcher, "seul les char entre quotes sont preserve", SILENCIEUX);
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



void	tests_preserves(void)
{
	tests("", preserve_token_lst, "chaine vide", B);
	tests("\\bonjour a \"toi $petit \\$NOM et toi $USER\"", preserve_token_lst,NULL, B);
}///

int main(int ac, char **av) {

	if (ac != 2)
		return (0);
	if (SILENCIEUX == false) {
		test1();
		char *str = ft_strdup(av[1]);
		test_line(str);
		t_token hy;
		hy.esec = SECURED;
		hy.next = NULL;
		hy.sign_char = 'h';
		hy.token = LETTER;
		test_display_secured(&hy);
		hy.esec = UNSECURED;
		test_display_unsecured(&hy);
		test_escaping(av[1]);
	}
	tests_double_quote();
	tests_simple_quote();
	tests_preserves();
	return (0);
}

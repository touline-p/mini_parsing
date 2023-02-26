/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:33:30 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/26 03:18:39 by bpoumeau         ###   ########.fr       */
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
			&& dquoting_process(tok, NULL, &tok) != SUCCESS)
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
	if (launcher(tok) == SUCCESS)
		display_tokens(tok);
	token_lst_clear(tok);

}
void	tests_double_quote(void)
{
	tests("\"test", test_double_quote_launcher, "erreure ligne non terminee", B);
	tests("\"test\"", test_double_quote_launcher, "cas normale les char entre quotes sont preserve mais pas les quotes", B);
	tests("\"t\\e\\\"st\"", test_double_quote_launcher, "slash avant la double quote doit preserver puis partir", B);
	tests("\"$\"", test_double_quote_launcher, "le $ ne peut pas etre preserve par les double quote", B);
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

void	tests_meta_split(t_token *token_lst, t_token*(*launcher)(t_token *), char *msg, bool silence)
{
	if (silence)
		return;
	if (msg)
		printf("%s\n", msg);
	printf("\npour\n");
	display_tokens(token_lst);
	launcher(token_lst);
	display_tokens(token_lst);
	token_lst_clear(token_lst);
	printf("\n");
}

#define TLC(x) token_lst_constructor(ft_strdup(x))

void	tests_split_on_meta(void)
{
	tests_meta_split(TLC("no metachar"), split_toklst_on_meta, NULL, B);
	tests_meta_split(TLC("just a | metachar"),split_toklst_on_meta, NULL, B);
	tests_meta_split(TLC("just a & metachar"),split_toklst_on_meta, NULL, B);
	tests_meta_split(TLC("just a ( metachar"),split_toklst_on_meta, NULL, B);
	tests_meta_split(TLC("just a ) metachar"),split_toklst_on_meta, NULL, B);
	tests_meta_split(TLC(""),split_toklst_on_meta, "nothing", B);
	tests_meta_split(TLC("||j;fk&<>()"),split_toklst_on_meta, "Only metachar", B);
}

#define TMG_M(x) split_toklst_on_meta(TLC(x))

void	tests_metachar_groupment()
{
	tests_meta_split(TMG_M("no metachar"), regroup_meta, NULL, B);
	tests_meta_split(TMG_M("||j;fk&<>()"), regroup_meta, NULL, B);


}

void	tests_preserves(void)
{
	/*t_token hy;
	hy.esec = SECURED;
	hy.next = NULL;
	hy.sign_char = 'h';
	hy.token = LETTER;
	test_display_secured(&hy);
	hy.esec = UNSECURED;
	test_display_unsecured(&hy);
	test_escaping("iescape:\\t: i don t ::\n");*/
	//tests_double_quote();
	//tests_simple_quote();
	//tests("", preserve_token_lst, "chaine vide", B);
	//tests("\\bonjour a \\\'toi $petit \\a$NOM et toi $USER\\\'", preserve_token_lst,NULL, B);
}

int main() {

	//tests_preserves();
	//tests_split_on_meta();
	tests_split_on_meta();
	tests_metachar_groupment();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:33:30 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/28 21:07:26 by bpoumeau         ###   ########.fr       */
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
			&& squoting_process(NULL, tok, &tok) != SUCCESS)
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
	tests("\'test\'", test_squote_launcher, "cas normal les char entre quotes sont preserve mais pas les quotes", B);
	tests("\'test", test_squote_launcher, "cas normal les char entre quotes sont preserve mais pas les quotes", B);
	tests("\'\'te\'st\'", test_squote_launcher, "seul les char entre quotes sont preserve", B);
	tests("\'te\'st", test_squote_launcher, "seul les char entre quotes sont preserve", B);
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
	t_token *mem;

	mem = token_lst;
	if (silence)
		return (token_lst_clear(mem));
	if (msg)
		printf("%s\n", msg);
	printf("\npour\n");
	display_tokens(token_lst);
	launcher(token_lst);
	display_tokens(token_lst);
	token_lst_clear(mem);
	printf("\n");
}

#define TLC(x) token_lst_constructor(ft_strdup(x))

void	tests_id_meta(void)
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
	tests_meta_split(TMG_M("||&&>><<"), regroup_meta, NULL, B);
	tests_meta_split(TMG_M("|||&&&>>><<<"), regroup_meta, NULL, B);
}

#define TMS_M(x) regroup_meta(TMG_M(x))

void	tests_metachar_split()
{
	tests_meta_split(TMS_M("a"), split_on_meta, "pipe et commande", B);
	tests_meta_split(TMS_M("echo bonjour | cat -e > outfile"), split_on_meta, "pipe et commande", B);

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
	tests_double_quote();
	tests_simple_quote();
	tests("", preserve_token_lst, "chaine vide", B);
	tests("\\bonjour \" a t\"ous", preserve_token_lst,NULL, B);
}

t_token	*tests_get_next_emt()
{
	tests_meta_split(TMG_M("ihih"), get_next_emt, NULL, B);

	return (NULL);
}

void	launcher(char *str)
{
	t_token *token;

	printf("Pour %s \n", str);
	token = TLC(str);
	display_tokens(token);
	preserve_token_lst(token);
	printf("preservation\n");
	display_tokens(token);
	printf("identification\n");
	split_toklst_on_meta(token);
	display_tokens(token);
	printf("split on them\n");
	split_on_meta(token);
	display_tokens(token);
	token_lst_clear(token);
}

void	tests_str_to_split_token()
{
	launcher("");
	launcher("bonjou\"r a t\"ous");
	launcher("bonjou\"r a $USER\" tous");
	launcher("bonjou\'r a $USER\' tous");
}

int main() {

	tests_preserves();
	//tests_split_on_meta();
//	tests_id_meta();
//	tests_metachar_groupment();
//	tests_metachar_split();
//	tests_get_next_emt();
	tests_str_to_split_token();
	return (0);
}

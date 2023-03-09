/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parsing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:47:29 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/09 18:44:25 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PARSING_MINI_PARSING_H
# define MINI_PARSING_MINI_PARSING_H

# include "test_mini.h"

# include "basic_enums.h"
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "libft/libft.h"

t_token	*mini_parsing(char *str);
t_token	*token_lst_constructor(char *str);

/*** Token Utils ***/

void	token_lst_clear(t_token *trash);
t_token	*token_constructor(t_emt emt, char msg);
void	del_token(t_token *token);
void	del_next_token(t_token *token);
void	del_next_word(t_token *token);
t_ert	insert_str_in_tkn_lst(t_token *token_lst, char *str, t_esec essec);

/*** preserving ***/

typedef t_ert	(*t_preserv_act)(t_token *first, t_token *second, t_token **ref);

t_ert	preserve_token_lst(t_token *token);
t_ert 	escaping_chars(t_token *tok);
t_ert	escape_process(t_token *last_pt, t_token *tok, t_token **voided);
t_ert	dquoting_process(t_token *voided, t_token *last_token, t_token **end_of_quot_pt);
t_ert	squoting_process(t_token *voided, t_token *token, t_token **end_of_quot_pt);

/*** split on meta ***/

t_token	*split_toklst_on_meta(t_token *tok);
t_token	*regroup_meta(t_token *tok);
t_token	*split_on_meta(t_token *tok);

/*** expand on dollars ***/

t_ert	expand_dollars(t_token *token_lst, char **env);


void	suppress_quotes(t_token *tok);


t_token	*get_next_emt(t_token *tok);

#endif //MINI_PARSING_MINI_PARSING_H

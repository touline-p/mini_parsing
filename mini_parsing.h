/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parsing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:47:29 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/24 02:50:26 by bpoumeau         ###   ########.fr       */
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

t_token	*mini_parsing(char *str);
t_token	*token_lst_constructor(char *str);

/*** Token Utils ***/

void	token_lst_clear(t_token *trash);
t_token	*token_constructor(t_emt emt, char msg);
void	del_token(t_token *token);
void	del_next_token(t_token *token);


/*** preserving ***/
void	preserv(t_token *tok);
t_ert 	escaping_chars(t_token *tok);

#endif //MINI_PARSING_MINI_PARSING_H

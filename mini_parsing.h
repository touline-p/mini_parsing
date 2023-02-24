/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parsing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:47:29 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/24 01:06:03 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PARSING_MINI_PARSING_H
# define MINI_PARSING_MINI_PARSING_H

# include "basic_enums.h"
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>

t_token	*mini_parsing(char *str);
t_token	*token_lst_constructor(char *str);

/*** Token Utils ***/

void	token_lst_clear(t_token *trash);
t_token	*token_constructor(t_emt emt, char msg);


/*** preserving ***/
void	preserv(t_token *tok);
void	escaping_chars(t_token *tok);

#endif //MINI_PARSING_MINI_PARSING_H

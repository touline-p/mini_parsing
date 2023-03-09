/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mini.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:35:11 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/09 23:37:15 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MINI_H
# define TEST_MINI_H

# include "basic_enums.h"
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"




void	display_tokens(t_token *token_lst);
void	display_t_emt(t_token *token);
void	put_esec(t_token *tok);



char *_get_env_variable(t_token *token, char **env);
void	display_instruction_block_tree(t_instruction_block_tree *tree);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_enums.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:42:21 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/23 22:05:20 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PARSING_BASIC_ENUMS_H
# define MINI_PARSING_BASIC_ENUMS_H

# ifndef ERT
#  define ERT
typedef enum	e_return_status
{
	SUCCESS = 0,
	FAILURE = 1,
	MLC_ERR = 2,
	WRT_ERR = 4
}	t_ert;
# endif

# define STRT_CHR -1
# define EOSTR 0
typedef enum 	e_token_minishell
{
	START,
	CHEVRON,
	PIPE,
	STRING,
	LETTER,
	EOL
}	t_emt;

typedef enum  e_secured
{
	SECURED,
	UNSECURED
}	t_esec;

typedef struct	s_token
{
	t_emt			token;
	char 			sign_char;
	t_esec			esec;
	struct s_token	*next;

}	t_token;


#endif //MINI_PARSING_BASIC_ENUMS_H

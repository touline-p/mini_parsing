/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_enums.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:42:21 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/26 17:24:54 by bpoumeau         ###   ########.fr       */
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

# define  METACHAR_SET "|&<>();"
typedef enum 	e_token_minishell
{
	START = 0,
	PIPE = 1,
	AMPERSAND = 2,
	CHEVRON_IN = 3,
	CHEVRON_OT = 4,
	OR = 5,
	AND = 6,
	HERE_DOC = 7,
	APPENDS = 8,
	O_PRTSS = 9,
	C_PRTSS = 10,
	SEMICOLON = 11,
	LETTER = 12,
	EOL = 13,
	STRING = 14
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
	struct s_token	*next_word;
}	t_token;


#endif //MINI_PARSING_BASIC_ENUMS_H

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:19:16 by iqattami          #+#    #+#             */
/*   Updated: 2024/08/31 18:10:38 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL
#define MINISHELL

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# define pip 1
# define input 2
# define output 3
# define delimiter 4
# define redirect 5
# define squote 6
# define dquote 7
 
typedef struct f_env
{
    char *line;
    char *key;
    char *value;
    struct f_env *next;
} f_env;

typedef struct s_parse
{
    char *content;
    int type;
    struct s_parse *next;
}t_parse;

char *put_prompt();
void sd_quotes(char *line);
char	*ft_strdup(const char *s);
 int	count_word(char const *str, char charset);
 char	**ft_split(char const *str, char charset);

#endif

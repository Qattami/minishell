/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:19:16 by iqattami          #+#    #+#             */
/*   Updated: 2024/10/15 14:58:21 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL
#define MINISHELL

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
#include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

# define pipe 1
# define input 2
# define output 3
# define heredoc 4
# define redirection 5
# define squote 6
# define dquote 7
# define word 8
#define command 9
 
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

//libtf

void	ft_putstr_fd(char *s, int fd);


char *put_prompt();
int sd_quotes(char *line);
char	*ft_strdup(const char *s);
// int	count_word(char const *str, char charset);
// char	**ft_split(char *str);
void ft_free(char **str);
void add_token(t_parse **head, char *content, int type);
int cmp(char *split);
t_parse *split_line(char *line);
int ft_strlen(char *str);
int check_redirection_syntax(char *inpt);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *str, char charset);
void *fill_env(char *str);


#endif

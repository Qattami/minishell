/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:07:34 by iqattami          #+#    #+#             */
/*   Updated: 2024/09/09 16:46:59 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int is_whitespace(char *str)
{
    while (*str)
    {
        if (!isspace((unsigned char)*str))
            return 0;
        str++;
    }
    return 1;
}

int pipe_at_begining(char *str)
{
    if (str[0] == '|')
    {
        printf("Syntax Error: Pipe at the beginning of the command\n");
        return 1;
    }
    return 0;
}
int pipe_at_end(char *str, int i, int len)
{
    if (str[i] == '|' && i == len - 1)
    {
         printf("Syntax Error: Pipe at the end of the command\n");
        return 1;
    }
    return 0;
}
int check_pipe_syntax(char *inpt)
{
    int i = 0;
    int last_was_pipe = 0;
    int in_quotes = 0;
    int len = strlen(inpt);
    char quote_char = 0;

    if (pipe_at_begining(inpt))
        return 1;

    while (inpt[i] != '\0')
    {
        if (inpt[i] == '\'' || inpt[i] == '"')
        {
            if (in_quotes && inpt[i] == quote_char)
                in_quotes = 0;
            else if (!in_quotes)
            {
                in_quotes = 1;
                quote_char = inpt[i];
            }
        }
        if (!in_quotes)
        {
            if (pipe_at_end(inpt, i, len))
                return 1;
            // Case 3 and 4: Consecutive pipes without commands
            if (inpt[i] == '|')
            {
                if (last_was_pipe)
                {
                    printf("Syntax Error: Consecutive pipes without commands\n");
                    return 1;
                }
                last_was_pipe = 1;
            }
            else if (!isspace((unsigned char)inpt[i]))
            {
                last_was_pipe = 0;
            }
        }
        i++;
    }
    // Case 5: Pipe with only whitespace before or after
    char *first_pipe = strchr(inpt, '|');
    if (first_pipe != NULL)
    {
        char *before_pipe = strndup(inpt, first_pipe - inpt);
        if (is_whitespace(before_pipe))
        {
            printf("Syntax Error: Pipe with only whitespace before the pipe\n");
            free(before_pipe);
            return 1;
        }
        free(before_pipe);
    }

    char *last_pipe = strrchr(inpt, '|');
    if (last_pipe != NULL)
    {
        char *after_pipe = strdup(last_pipe + 1);
        if (is_whitespace(after_pipe))
        {
            printf("Syntax Error: Pipe with only whitespace after the pipe\n");
            free(after_pipe);
            return 1;
        }
        free(after_pipe);
    }

    // Case 6: Unclosed quotes
    if (in_quotes)
    {
        printf("Syntax Error: Unclosed quotation marks\n");
        return 1;
    }

    return 0;
}
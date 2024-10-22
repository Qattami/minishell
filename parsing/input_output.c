/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inpt_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 01:31:21 by iqattami          #+#    #+#             */
/*   Updated: 2024/09/10 01:31:51 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int my_isspace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || 
            c == '\v' || c == '\f' || c == '\r');
}


int is_whitespace(char *str)
{
    while (*str)
    {
        if (!my_isspace((unsigned char)*str))
            return 0;
        str++;
    }
    return 1;
}
int at_begining(char *inpt)
{
    if(inpt[0] == '>' || inpt[0] == '<')
    {
        printf("Syntax Error: Redirection at the beginning without a command\n");
        return 1;
    }
    return 0;
}
int at_the_end(int i, int len)
{
    if (i == len - 1)
    {
        printf("Syntax Error: Redirection at the end without a file\n");
        return 1;
    }
    return 0;
}
int quotes(char *inpt, int i)
{
    char quote_char = '\0';
    int in_quotes;

    in_quotes = 0;
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
    return in_quotes;
}

int check_redirection_syntax(char *inpt)
{
    int i ;
    int last ;

    i = 0;
    last = 0;
    while (inpt[i] != '\0')
    {
        if (!quotes(inpt, i))
        {
            if (inpt[i] == '>' || inpt[i] == '<')
            {
                if (i == 0)
                    return (at_begining(inpt));
                if(at_the_end( i, ft_strlen(inpt)) == 1)
                    return 1;
                if (last)
                    return(printf("Syntax Error: Consecutive redirection operators\n"), 1);
                last = 1;
            }
            else if (!my_isspace((unsigned char)inpt[i]))
                last = 0;
        }
        i++;
    }
    return 0;
}



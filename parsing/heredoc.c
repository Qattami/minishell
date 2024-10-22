/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:26:33 by iqattami          #+#    #+#             */
/*   Updated: 2024/09/26 14:38:00 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int count_heredoc(t_parse *token)
{
    int heredocs;

    heredocs = 0;
    while(token)
    {
        if(token->type == 4 && (token->next->type == 8 || token->next->type == 9))
            heredocs++;
        else
            return -1;
        
        token = token->next;
    }
    return heredocs;
}

char *read_herdoc(char *key)
{
    char *text;
    char *line;
    int i;

    i = 0;
    line = readline(">");
    while(line || strcmp(key, line))
    {
        if(i++ == 0)
            text = ft_strjoin(line, "\n");
        else
        {
            text = ft_strjoin(text, line);
            text = ft_strjoin(text, "\n");
            
        }
        free(line);
        line = readline(">");
    }
    return(text);
}

void open_fd(char *text)
{
    int fd;

    fd = open("../tmp/heredoc",     O_RDWR);
    if(fd > 0)
    {
        write(fd, &read_herdoc, ft_strlen(read_herdoc));
    }
    close(fd);
}
void heredocs()
{
    
}
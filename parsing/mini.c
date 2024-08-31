/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:00:07 by iqattami          #+#    #+#             */
/*   Updated: 2024/08/31 18:14:23 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
    char **split;
    int count;
	int i = 0;
    
    while (1)
    {
        char *line = put_prompt();
        count = count_word(line, ' ');
        split = malloc(sizeof(char *) * (count + 1));
		
		split = ft_split(line, ' ');
		while (split[i])
		{
			printf("%s\n", split[i++]);
		}
        
        
        if (!line || strcmp(line, "exit") == 0)
        {
            free(line);
            break;
        }

        if (*line)
            add_history(line);

        printf("You entered: %s\n", line);
        
        free(line);
    }

    printf("Exiting...\n");
    return 0;
}


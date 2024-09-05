/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:00:07 by iqattami          #+#    #+#             */
/*   Updated: 2024/09/05 19:30:59 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int main()
{
    
        t_parse *split;
        char *str = "jh | sgd  \" kajsdhfkajhf\" ";
        printf ("----------\n");
        if(sd_quotes(str))
        {
            exit(1);
        }
        split = split_line (str);
        while (split)
        {
            printf("%s\n", split->content);
            split = split->next;
        }

    // char **split;
    
    // while (1)
    // {
    //     char *line = put_prompt();
    //     if (sd_quotes(line) == 0)
    //     {
	// 	    split = ft_split(line);        
    //         if (!line || strcmp(line, "exit") == 0)
    //         {
    //             free(line);
    //          break;
    //         }


    //         printf("You entered: %s\n", line);
    //         ft_free (split);
    //     }
    //     if (*line)
    //         add_history(line);
    //     free(line);
    // }
    // printf("Exiting...\n");
    // return 0;
}


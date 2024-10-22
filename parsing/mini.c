/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:00:07 by iqattami          #+#    #+#             */
/*   Updated: 2024/10/12 17:24:41 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    char **split;
    int i = 0;
  
    while(env[i])
    {
        fill_env(env[i++]);
    }
    return 0;
}
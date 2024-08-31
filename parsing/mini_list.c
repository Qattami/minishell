/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:08:18 by iqattami          #+#    #+#             */
/*   Updated: 2024/08/31 17:56:05 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_parse *new_token(char *content, int type)
{
    t_parse *new_node = malloc(sizeof(t_parse));
    if (!new_node)
        return NULL;
    new_node->content = ft_strdup(content); 
    new_node->type = type;
    new_node->next = NULL;
    return new_node;
}

t_parse	*ft_lstlast(t_parse *lst)
{
	t_parse	*tmp;

	tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_lstadd_back(t_parse **lst, t_parse *new)
{
	t_parse	*tmp;

	if (lst == NULL || new == NULL)
		return ;
	tmp = *lst;
	if (tmp)
	{
		tmp = ft_lstlast(tmp);
		tmp->next = new;
	}
	else
		*lst = new;
}


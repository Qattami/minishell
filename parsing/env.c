/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:53:53 by iqattami          #+#    #+#             */
/*   Updated: 2024/10/12 17:33:25 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

f_env	*ft_lstnew(char *s1, char *s2)
{
	f_env	*node;

	node = (f_env *)malloc(sizeof(f_env));
	if (node == NULL)
		return (NULL);
	node->key = s1;
    node->value = s2;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(f_env **lst, f_env *new)
{
	f_env   *tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return i;
}

void *fill_env(char *str)
{
    f_env *lst;
	char *s1 = NULL;
	char *s2 = NULL;
	int i ;
	int j;
	
    lst = NULL;
	i = 0;
	j = 0;

	while(str[i] != '=')
		i++;
	s1 = malloc((sizeof(char) * i) + 1);
	s2 = malloc(sizeof(char) * ft_strlen(str) - i);
    i = 0;
	while(str[i] != '=')
	{
		s1[i] = str[i];
		i++;
	}
		
	s1[i++] = '\0';
	while(str[i])
		s2[j++] = str[i++];
	s2[j] = '\0';
	printf("%s = ", s1);
    printf("%s\n", s2); 
    ft_lstadd_back(&lst, ft_lstnew(s1, s2));
    free(s1);
	free(s2);
   
}


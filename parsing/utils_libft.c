/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:37:17 by iqattami          #+#    #+#             */
/*   Updated: 2024/09/26 11:24:19 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return i;
}

char	*ft_copy(char *m, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		m[i] = s1[i];
		i++;
	}
    m[i] = ' ';
    i++;
	while (s2[j])
		m[i++] = s2[j++];
	m[i] = '\0';
	return (m);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s;
	char	*m;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 2;
	m = malloc(sizeof(char) * s);
	if (!m)
		return (NULL);
	m = ft_copy(m, s1, s2);
	// free(s1);
	return (m);
}
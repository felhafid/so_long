/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:19:43 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/16 16:11:43 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strcat(char *s, char *s1)
{
	int	i;
	int	j;

	if (!s || !s1)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	while (s1[i])
	{
		s[i + j] = s1[i];
		i++;
	}
	s[i + j] = '\0';
	return (s);
}

char	*ft_strcpy(char *s, char *s1)
{
	int	i;

	if (!s || !s1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_afterline(char *s)
{
	int		i;
	int		j;
	char	*aftrline;

	i = 0;
	j = 1;
	if (!s)
		return (NULL);
	while (s[i] && j != 0)
	{
		if (s[i] == '\n')
			j = 0;
		i++;
	}
	aftrline = malloc(ft_strlen(s) - i + 1);
	if (!aftrline)
		return (NULL);
	j = 0;
	while (s[i])
		aftrline[j++] = s[i++];
	aftrline[j] = '\0';
	free(s);
	return (aftrline);
}

char	*ft_strjoin(char *s, char *s1)
{
	char	*p;

	if (!s && !s1)
		return (NULL);
	if (!s1)
		return (NULL);
	if (!s)
	{
		p = malloc(ft_strlen(s1) + 1);
		if (!p)
			return (NULL);
		ft_strcpy(p, s1);
	}
	else
	{
		p = malloc(ft_strlen(s) + ft_strlen(s1) + 1);
		if (!p)
			return (NULL);
		ft_strcpy(p, s);
		ft_strcat(p, s1);
		free(s);
	}
	return (p);
}

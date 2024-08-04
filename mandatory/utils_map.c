/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:16:32 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/24 07:45:54 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	map_name(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (len < 4)
		return (1);
	if (s[len - 4] != '.' || s[len - 3] != 'b' || s[len - 2] != 'e' 
		|| s[len - 1] != 'r')
		return (1);
	else
		return (0);
}

char	*ft_join2string(char *s, char *s1, int i)
{
	int		j;
	char	*str;

	if (s1[0] == '\n')
	{
		free(s);
		free(s1);
		exit(write(2, "Error\nremove new line\n", 22));
	}
	if (s == NULL)
		return (s1);
	str = malloc(ft_strlen(s) + ft_strlen(s1) + 1);
	if (!str) 
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	str[i] = '\0';
	return (free(s), free(s1), str);
}

char	**fill_map(int fd, t_so_long *p)
{
	char	*s;
	char	*gt;
	char	**str;

	s = get_next_line(fd);
	if (s == NULL)
	{
		write(2, "Error\nempty file\n", 17);
		exit(1);
	}
	gt = NULL;
	while (s != NULL)
	{
		gt = ft_join2string(gt, s, 0);
		s = get_next_line(fd);
	}
	str = ft_split(gt);
	p->copy_map = ft_split(gt);
	free(gt);
	return (str);
}

void	frees(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

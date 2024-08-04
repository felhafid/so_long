/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:29:46 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/27 11:14:43 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	checkword(char *s)
{
	int	i;
	int	word;

	if (!s) 
		return (0);
	i = 0;
	word = 0;
	while (s[i])
	{
		if ((s[i] == '\n' && s[i + 1] != '\n' && s[i + 1] != '\0') 
			|| (i == 0 && s[i] != ' '))
			word++;
		i++;
	}
	return (word);
}

char	**allocation(char *s, char **v, int i)
{
	int		j;
	int		k;
	int		o;

	j = 0;
	while (i < checkword(s))
	{
		while (s[j] && s[j] == '\n' )
			j++;
		k = 0;
		while (s[j + k] && s[j + k] != '\n')
			k++;
		v[i] = malloc(k + 1);
		if (!v[i])
			return (NULL);
		o = 0;
		while (s[j] && s[j] != '\n' && o < k)
			v[i][o++] = s[j++];
		v[i][o] = '\0';
		i++;
	}
	v[i] = NULL;
	return (v);
}

char	**ft_split(char *s)
{
	int		i;
	char	**v;

	i = 0;
	v = NULL;
	v = malloc((checkword(s) + 1) * sizeof(char *));
	if (!v) 
		return (NULL);
	return (allocation(s, v, i));
}

void	free_tt(void **texturei)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (texturei[i] == NULL)
			i++;
		else
		{
			mlx_delete_texture(texturei[i]);
			i++;
		}
	}
	free(texturei);
}

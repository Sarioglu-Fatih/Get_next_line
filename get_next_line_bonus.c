/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:43:42 by fsariogl          #+#    #+#             */
/*   Updated: 2021/12/10 16:19:57 by fsariogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *s1)
{
	int		i;
	char	*str;

	i = 0;
	while (s1[i] != '\0' && s1[i - 1] != '\n')
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && s1[i - 1] != '\n')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	if (str[0] == '\0')
	{
		free(str);
		str = NULL;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	i = ft_strlennl(s1, 0);
	j = ft_strlennl(s2, 0);
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	j = -1;
	while (s1[++j] != '\0')
		str[j] = s1[j];
	i = 0;
	str[j] = 'a';
	while (s2[i] != '\0' && s2[i - 1] != '\n')
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

void	raz(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlennl(buff, 1);
	if (buff[j] != '\0')
	{
		j++;
		while (buff[j] != '\0')
		{
			buff[i] = buff[j];
			i++;
			j++;
		}
		while (i < j)
		{
			buff[i] = '\0';
			i++;
		}
	}
}

char	*get_next_line(int fd)
{
	int			i;
	int			j;
	char		*str;
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];

	i = 0;
	j = 1;
	if (fd < 0)
		return (NULL);
	str = ft_strdup(buff[fd]);
	while (j > 0 && buff[fd][i] != '\n')
	{
		i = 0;
		while (buff[fd][i] != '\0' && buff[fd][i] != '\n' && i < BUFFER_SIZE)
			i++;
		if (buff[fd][i] != '\n')
		{
			j = read(fd, buff[fd], BUFFER_SIZE);
			buff[fd][j] = '\0';
			str = ft_strjoin(str, buff[fd]);
		}
	}
	raz(buff[fd]);
	return (str);
}

int	main(void)
{
	int		i;
	int		fd[2];
	char	*str[2];

	fd[0] = open("test1.txt", O_RDONLY);
	fd[1] = open("test2.txt", O_RDONLY);
	i = 0;
	while (i < 12)
	{	
		str[0] = get_next_line(fd[0]);
		printf("%s", str[0]);
		free(str[0]);
		str[1] = get_next_line(fd[1]);
		printf("%s", str[1]);
		free(str[1]);
		i++;
	}
	close (fd[0]);
	close(fd[1]);
	return (0);
}


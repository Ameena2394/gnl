/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammustaf <ammustaf@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:17:49 by ammustaf          #+#    #+#             */
/*   Updated: 2022/12/12 18:17:49 by ammustaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_get(char *str)
{
	int		i;
	char	*strstr;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	strstr = (char *)malloc(sizeof(char) * (i + 2));
	if (!strstr)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		strstr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		strstr[i] = str[i];
		i++;
	}
	strstr[i] = '\0';
	return (strstr);
}

char	*ft_new_str(char *str)
{
	int		i;
	int		j;
	char	*strstr;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	strstr = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!strstr)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		strstr[j++] = str[i++];
	strstr[j] = '\0';
	free(str);
	return (strstr);
}

char	*ft_read_str(int fd, char *str)
{
	char	*buffer;
	int		readb;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	readb = 1;
	while (!ft_strchr(str, '\n') && readb != 0)
	{
		readb = read(fd, buffer, BUFFER_SIZE);
		if (readb == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readb] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*readl;
	static char	*str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = ft_read_str(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	readl = ft_get(str[fd]);
	str[fd] = ft_new_str(str[fd]);
	return (readl);
}

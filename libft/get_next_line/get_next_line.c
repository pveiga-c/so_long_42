/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:12:47 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/09 15:35:14 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft.h"


static char	*check(char *stash, int nbits)
{
	if (nbits == 0 && *stash == '\0')
	{
		free(stash);
		return (NULL);
	}
	if (stash == NULL)
	{
		stash = malloc(1);
		if (stash == NULL)
			return (NULL);
		*stash = '\0';
	}
	return (stash);
}

char	*ft_read_line(int fd, char *stash)
{
	int		nbits;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	nbits = 1;
	while (!ft_strchr(stash, '\n') && nbits > 0)
	{
		nbits = read(fd, buff, BUFFER_SIZE);
		if (nbits == -1)
		{
			free(stash);
			free(buff);
			return (NULL);
		}
		buff[nbits] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	stash = check(stash, nbits);
	free(buff);
	return (stash);
}

char	*ft_next_line(char *stash)
{
	char	*str;
	char	*str_f;
	int		nl_pos;

	if (!ft_strchr(stash, '\n'))
		str_f = stash + (ft_strlen(stash) - 1);
	else
		str_f = ft_strchr(stash, '\n');
	nl_pos = str_f - stash + 1;
	str = (char *)malloc(nl_pos + 1);
	if (str == NULL)
	{
		free(stash);
		free(str);
		return (0);
	}
	ft_memmove(str, stash, nl_pos);
	str[nl_pos] = '\0';
	ft_memmove(stash, nl_pos + stash, ft_strlen(stash) - nl_pos + 1);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[1024];

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_read_line(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_next_line(stash[fd]);
	return (line);
}

/*
int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;

	fd1 = open("testes/teste1.txt", O_RDONLY);
	fd2 = open("testes/teste2.txt", O_RDONLY);
	fd3 = open("testes/teste3.txt", O_RDONLY);
	if (fd1 == -1 && fd2 == -1 && fd3 == -1)
	{
		printf("Failed to open file.\n");
		return (1);
	}
	line = get_next_line(fd1);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd1);
	}
	line = get_next_line(fd2);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
	}
	line = get_next_line(fd3);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd3);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/

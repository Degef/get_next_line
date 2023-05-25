/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:40:29 by Degef             #+#    #+#             */
/*   Updated: 2023/01/19 13:27:57 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_to_main_str(int fd, char *main_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc(((size_t)(BUFFER_SIZE) + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(main_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		main_str = ft_strjoin(main_str, buff);
	}
	free(buff);
	return (main_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*main_str[256];

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (0);
	main_str[fd] = read_to_main_str(fd, main_str[fd]);
	if (!main_str[fd])
		return (0);
	line = ft_get_line(main_str[fd]);
	main_str[fd] = ft_new_main_str(main_str[fd]);
	return (line);
}

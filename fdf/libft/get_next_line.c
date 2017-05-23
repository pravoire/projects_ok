/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 21:32:48 by pravoire          #+#    #+#             */
/*   Updated: 2016/02/18 10:24:34 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int			gnl_get_line(char **content, char **line, int res)
{
	char			*tmp;
	char			*off;

	tmp = *content;
	off = ft_strchr(tmp, '\n');
	if (off)
	{
		*line = ft_strsub(tmp, 0, off - tmp);
		*content = ft_strdup(off + 1);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(tmp);
		free(*content);
		*content = NULL;
	}
	if ((!*line) || (off && !*content))
		return (-1);
	if ((!res && *content) || (*line))
		return (1);
	return (res);
}

static int			gnl_get_content(int fd, char **content)
{
	char			*buf;
	char			*tmp;
	int				res;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	res = 1;
	while ((ft_strchr(*content, '\n') == NULL) && res > 0)
	{
		tmp = *content;
		res = read(fd, buf, BUFF_SIZE);
		if (res > 0)
		{
			buf[res] = '\0';
			if (!(*content = ft_strjoin(tmp, buf)))
			{
				*content = ft_strcat(tmp, buf);
				free(buf);
				return (-1);
			}
			free(tmp);
		}
	}
	free(buf);
	return (res);
}

int					get_next_line(int const fd, char **line)
{
	static char		*content[1024];
	int				res;

	if (fd < 0 || fd > 1023 || !line)
		return (-1);
	res = 0;
	if (content[fd] == NULL)
		if ((content[fd] = ft_strnew(BUFF_SIZE * 2)) == NULL)
			return (-1);
	if (ft_strchr(content[fd], '\n') == NULL)
		res = gnl_get_content(fd, &content[fd]);
	if (res > 1)
		res = 1;
	if (res == 0 && *content[fd] == '\0')
	{
		*line = NULL;
		free(content[fd]);
		content[fd] = NULL;
	}
	else if (res > 0 || *content[fd] != '\0')
		res = gnl_get_line(&content[fd], line, res);
	return (res);
}

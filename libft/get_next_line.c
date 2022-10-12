/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:00:51 by mrantil           #+#    #+#             */
/*   Updated: 2022/09/19 17:57:57 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	manage_str(int fd, char **stat_buf, char **line)
{
	char	*temp;

	*line = ft_strsub(stat_buf[fd], 0, ft_strclen(stat_buf[fd], '\n'));
	if (ft_strchr(stat_buf[fd], '\n'))
		temp = ft_strdup(ft_strchr(stat_buf[fd], '\n') + 1);
	ft_strdel(&stat_buf[fd]);
	stat_buf[fd] = ft_strdup(temp);
	ft_strdel(&temp);
	return (1);
}

static int	work_it(int fd, char **stat_buf, char *read_buf, char **line)
{
	char	*temp;

	temp = ft_strsub(read_buf, 0, ft_strclen(read_buf, '\n'));
	stat_buf[fd] = ft_strupdate(stat_buf[fd], temp);
	ft_strdel(&temp);
	temp = ft_strdup(ft_strchr(read_buf, '\n') + 1);
	*line = ft_strdup(stat_buf[fd]);
	ft_strdel(&stat_buf[fd]);
	stat_buf[fd] = ft_strdup(temp);
	ft_strdel(&temp);
	return (2);
}

static int	read_file(int fd, char **stat_buf, char *read_buf, char **line)
{
	int				ret;

	ret = read(fd, read_buf, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	read_buf[ret] = '\0';
	if (ft_strchr(read_buf, '\n') == NULL)
		stat_buf[fd] = ft_strupdate(stat_buf[fd], read_buf);
	else
		return (work_it(fd, stat_buf, read_buf, line));
	if (ret == 0)
		return (0);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	char			read_buf[BUFF_SIZE + 1];
	static char		*stat_buf[FD_MAX];
	int				ret;

	ret = 1;
	if (!line || fd < 0 || fd > FD_MAX || BUFF_SIZE <= 0)
		return (-1);
	if (!stat_buf[fd])
		stat_buf[fd] = ft_strnew(BUFF_SIZE);
	if (ft_strchr(stat_buf[fd], '\n') != NULL)
		return (manage_str(fd, stat_buf, line));
	while (ret)
	{
		ret = read_file(fd, stat_buf, read_buf, line);
		if (ret == -1)
			return (-1);
		if (ret == 2)
			return (1);
	}
	*line = ft_strdup(stat_buf[fd]);
	ft_strdel(&stat_buf[fd]);
	if (ft_strlen(*line) > 0)
		return (1);
	return (0);
}

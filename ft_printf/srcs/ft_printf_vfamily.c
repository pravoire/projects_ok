/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_vfamily.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravoire <pravoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:20:55 by pravoire          #+#    #+#             */
/*   Updated: 2017/04/26 19:46:58 by pravoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vfprintf(int fd, const char *format, va_list ap)
{
	int	len;

	len = ft_vlprintf(format, ap);
	if (len != -1)
		flush_fd(fd);
	return (len);
}

int		ft_vsprintf(char *str, const char *format, va_list ap)
{
	int	len;

	len = ft_vlprintf(format, ap);
	if (len != -1)
		flush_str(str);
	return (len);
}

int		ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	int	len;

	len = ft_vlprintf(format, ap);
	if (len != -1)
		flush_nstr(str, size);
	return ((len > 0 && len > (int)size) ? (int)size : len);
}

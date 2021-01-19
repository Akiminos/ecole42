/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:23:03 by bdruez            #+#    #+#             */
/*   Updated: 2019/12/03 19:02:51 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
int		is_in(char *str, int chr);
char	*ft_substr(char *str, size_t start, size_t len);
char	*flush_rest(char *rest, int pos);
int		ft_exit(int code, char **buffer, char **rest);
int		ft_return(int code, char *buffer, char *rest);
int		get_next_line(int fd, char **line);

#endif

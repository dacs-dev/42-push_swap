/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:59:29 by dcid-san          #+#    #+#             */
/*   Updated: 2024/11/16 01:22:16 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(GET_NEXT_LINE_H)
# define GET_NEXT_LINE_H
# if !defined(BUFFER_SIZE)
#  define BUFFER_SIZE 100
# endif
# include <stddef.h>

char			*get_next_line(int fd);
void			*ft_realloc(void *src, unsigned long oldsize,
					unsigned long newsize);
char			*ft_strdup(char *str);
unsigned long	ft_find_chr(char *str, char c, unsigned long size);
char			*ft_strncpy(char *dst, const char *src, size_t dsize);
char			*ft_buffzero(char *buff);

#endif

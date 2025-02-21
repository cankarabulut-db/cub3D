/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayigit <hayigit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:11:56 by nkarabul          #+#    #+#             */
/*   Updated: 2025/02/21 16:12:05 by hayigit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_exists(char *str, char c);
int		ft_strlenn(char *str);
char	*get_next_line(int fd);
char	*ft_strjoinn(char *dst, char *src);
char	*ft_readline(int fd, char *dst);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

#endif
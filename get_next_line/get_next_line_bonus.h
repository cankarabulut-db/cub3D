/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarabul <nkarabul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:11:09 by nkarabul          #+#    #+#             */
/*   Updated: 2024/01/20 19:14:07 by nkarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

int		ft_exists(char *str, char c);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *dst, char *src);
char	*ft_readline(int fd, char *dst);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif  
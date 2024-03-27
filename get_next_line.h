/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:09:29 by fsariogl          #+#    #+#             */
/*   Updated: 2021/12/08 14:31:15 by fsariogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

void	raz(char *buff);
char	*ft_reader(int fd);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
int		ft_strlennl(char *str, int nb);
char	*ft_strjoin(char *s1, char *s2);

#endif

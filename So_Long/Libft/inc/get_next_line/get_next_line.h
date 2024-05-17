/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:40:45 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/03 13:34:58 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/**
 * @brief Get the next line from an fd
 * 
 * @param fd 
 * @return char* 
 */
char	*get_next_line(int fd);

/**
 * @brief Joins new line to buffer
 * 
 */
char	*ft_strjoin(char *s1, char *s2);

/**
 * @brief Returns lenth of string
 * 
 */
size_t	ft_strlen(char *str);

/**
 * @brief Returns first ocurrence of character in string
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Removes the line you just copied into an aux and leaves 
 * the rest of the buffer
 * 
 * @param buff 
 * @return char* 
 */
char	*cut_buff(char *buff);

/**
 * @brief Get the next line from the buffer
 * 
 * @param buff 
 * @return char* 
 */
char	*ft_getline(char *buff);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:40:45 by jcallejo          #+#    #+#             */
/*   Updated: 2024/05/01 09:19:57 by jcallejo         ###   ########.fr       */
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
 * @brief Get the next line objectMain funciton to get next line in a file using
 * it's file descriptor
 * 
 * @param fd 
 * @return char* 
 */
char	*get_next_line(int fd);

/**
 * @brief Function to join a string with the end of the other string
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Function to get the lenth of a string
 * 
 * @param str 
 * @return int 
 */
int		ft_strlen(const char *str);

/**
 * @brief Locates the first occurrence of character c in the string s.
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Extracts a substring of size len from string s. Starts
 * 		  at the given start value.
 * 
 * @param s 
 * @param start 
 * @param len 
 * @return char* 
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
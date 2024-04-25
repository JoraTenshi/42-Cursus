/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:51:47 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/25 10:21:00 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

/**
 * @brief Main function that replicates the function printf without returning -1 
 *on error
 * 
 * @param str 
 * @param ... 
 * @return int 
 */
int		ft_printf(const char *str, ...);

/**
 * @brief Function to write a char
 * 
 * @param c 
 * @return int 
 */
int		ft_putchar(char c);

/**
 * @brief Function to write an integer
 * 
 * @param nb 
 * @return int 
 */
int		ft_putnbr(int nb);

/**
 * @brief Function to write an unsigned integer
 * 
 * @param nb 
 * @return int 
 */
int		ft_putunbr(int nb);

/**
 * @brief Function to write a string
 * 
 * @param s 
 * @return int 
 */
int		ft_putstr(char *s);

/**
 * @brief Function to write a hexadecimal number passing it 
 * in decimal base and checking if caps or not
 * 
 * @param n 
 * @param format 
 * @return int 
 */
int		ft_puthex(unsigned int n, char format);

/**
 * @brief Function to convert an integer to ascii character
 * 
 * @param n 
 * @return char* 
 */
char	*ft_itoa(int n);

/**
 * @brief Function to convert unsigned integer to ascii character
 * 
 * @param n 
 * @return char* 
 */
char	*ft_utoa(unsigned int n);

/**
 * @brief Function to get the lenth of a string
 * 
 * @param str 
 * @return int 
 */
int		ft_strlen(const char *str);

/**
 * @brief Function to write the memory region of a pointer in hexadecimal
 * 
 * @param n 
 * @return int 
 */
int		ft_putptr(__UINTPTR_TYPE__ n);

/**
 * @brief Function to get the lenth of a hexadecimal number
 * 
 * @param n 
 * @return int 
 */
int		ft_hlen(long unsigned int n);

/**
 * @brief Function auxiliar to print the hexadecimal number
 * 
 * @param n 
 * @param base 
 */
void	ft_phex(long unsigned int n, char *base);

#endif
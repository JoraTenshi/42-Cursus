/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:51:47 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/19 13:18:48 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putunbr(int nb);
int		ft_putstr(char *s);
int		ft_puthex(unsigned int n, char format);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
int		ft_strlen(const char *str);
int		ft_putptr(__UINTPTR_TYPE__ n);

#endif
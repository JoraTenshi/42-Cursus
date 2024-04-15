/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:03:59 by jcallejo          #+#    #+#             */
/*   Updated: 2024/04/15 21:22:15 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @brief Tests if character c is a letter.
 * 
 * @param c 
 * @return int 
 */
int		ft_isalpha(int c);

/**
 * @brief Tests if character c is a number.
 * 
 * @param c 
 * @return int 
 */
int		ft_isdigit(int c);

/**
 * @brief Tests if character c is a letter or number.
 * 
 * @param c 
 * @return int 
 */
int		ft_isalnum(int c);

/**
 * @brief Tests if character c is an ascii character.
 * 
 * @param c 
 * @return int 
 */
int		ft_isascii(int c);

/**
 * @brief Tests if character c is a printable character.
 * 
 * @param c 
 * @return int 
 */
int		ft_isprint(int c);

/**
 * @brief Computes the length of string s.
 * 
 * @param s 
 * @return size_t 
 */
int		ft_strlen(const char *s);

/**
 * @brief Sets len memory addresses to value c starting at memory address b.
 * 
 * @param b 
 * @param c 
 * @param len 
 * @return void* 
 */
void	*ft_memset(void *b, int c, size_t len);

/**
 * @brief Sets n memory addresses to 0 starting at memory address s.
 * 
 * @param s 
 * @param n 
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief Copies n bytes from memory address src to memory address dst.
 * 
 * @param dst 
 * @param src 
 * @param n 
 * @return void* 
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * @brief Copies len bytes from memory address src to memory address dst. 
 * 		  Contemplates memory overlapping.
 * 
 * @param dst 
 * @param src 
 * @param len 
 * @return void* 
 */
void	*ft_memmove(void *dst, const void *src, size_t len);

/**
 * @brief Copies string src to string dst with len length
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t 
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * @brief Concatenates string dst onto string dst and returns total len.
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t 
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * @brief Transforms character c into its uppercase variant if it's a letter.
 * 
 * @param c 
 * @return int 
 */
int		ft_toupper(int c);

/**
 * @brief Transforms character c into its lowercase variant if it's a letter.
 * 
 * @param c 
 * @return int 
 */
int		ft_tolower(int c);

/**
 * @brief Locates the first occurrence of character c in the string s.
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Locates the last occurrence of character c in the string s.
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Compares strings s1 and s2 and returns the difference of 
 * 		  the first two different characters.
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locates the first occurrence of character c in 
 * 			memory of string s.
 * 
 * @param s 
 * @param c 
 * @param n 
 * @return void* 
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares byte string s1 against byte string s2.
 *     	  Both strings are assumed to be n bytes long.
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Locates the first occurrence of the null-terminated 
 * 		  string needle in the string haystack, where not more 
 * 		  than len characters are searched.
 * 
 * @param haystack 
 * @param needle 
 * @param len 
 * @return char* 
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/**
 * @brief Transforms string str into an int.
 * 
 * @param str 
 * @return int 
 */
int		ft_atoi(const char *str);

/**
 * @brief Allocates count memory addresses with specified size as 0.
 * 
 * @param count 
 * @param size 
 * @return void* 
 */
void	*ft_calloc(size_t count, size_t size);

/**
 * @brief Duplicates string s1.
 * 
 * @param s1 
 * @return char* 
 */
char	*ft_strdup(const char *s1);

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

/**
 * @brief Concatenates strings s1 and s2 onto a new string.
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Removes any character contained on set from the start
 * 		  and end of s1.
 * 
 * @param s1 
 * @param set 
 * @return char* 
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Splits string s using character c as a delimiter.
 * 
 * @param s 
 * @param c 
 * @return char** 
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Transforms int n into a string.
 * 
 * @param n 
 * @return char* 
 */
char	*ft_itoa(int n);

/**
 * @brief Applies the function f to every character in s.
 * 		  Returns a new string.
 * 
 * @param s 
 * @param f 
 * @return char* 
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Iterates the string s applying the function f 
 * 		  to each one of its characters.
 * 
 * @param s 
 * @param f 
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Writes character c to the file pointed by file descriptor fd.
 * 
 * @param c 
 * @param fd 
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Writes string s to the file pointed by file descriptor fd.
 * 
 * @param s 
 * @param fd 
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Writes string s to the file pointed by file descriptor fd
 * 		  and adds a line skip at the end.
 * 
 * @param s 
 * @param fd 
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Writes number n to the file pointed by file descriptor fd.
 * 
 * @param n 
 * @param fd 
 */
void	ft_putnbr_fd(int n, int fd);

// BONUS //

/**
 * @brief Creates a new node of the list with the content given.
 * 
 * @param content 
 * @return t_list* 
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Adds a new node to the begginning of the list lst.
 * 
 * @param lst 
 * @param new 
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Computes the size of the list after the node lst.
 * 
 * @param lst 
 * @return int 
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Traverses the list after the node lst to find the last node.
 * 
 * @param lst 
 * @return t_list* 
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Adds a new node to the end of the list lst.
 * 
 * @param lst 
 * @param new 
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Deletes the node lst using the function pointed by del.
 * 
 * @param lst 
 * @param del 
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Clears the list lst using the function pointed by del.
 * 
 * @param lst 
 * @param del 
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates every node after lst while applying the function
 * 		  f to every one of them.
 * 
 * @param lst 
 * @param f 
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates every node after lst while applying the function
 * 		  f to every one of them and creating a new list.
 * 		  The function pointed by del is used to free everything if
 * 		  anything fails.
 * 
 * @param lst 
 * @param f 
 * @param del 
 * @return t_list* 
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif

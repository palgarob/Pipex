/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:44:19 by pepaloma          #+#    #+#             */
/*   Updated: 2023/12/22 13:03:04 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stddef.h> //NULL, size_t
# include <sys/types.h> //ssize_t
# include <stdarg.h>

# define HEXADECIMAL_LO "0123456789abcdef"
# define HEXADECIMAL_UP "0123456789ABCDEF"
# define DECIMAL "0123456789"

# define ERROR_ARRAY2DSIZE "to get the size of a t_array2d, \
the array must be rectangular"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_array2d
{
	char	**array;
	t_point	size;
}	t_array2d;

int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *s, int c, size_t len);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char \
		*src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char \
		*src, size_t dstsize);
size_t		ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		**ft_split(char const *s, char c);
char		*ft_strtrim(char *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

char		*ft_gnl(int fd);
char		*ft_strjoin_gnl(char *s1, char *s2);

int			ft_printf(char const *format, ...);
int			ft_print_hex(unsigned int n, int lcase);
int			ft_print_char(int c);
int			ft_print_str(char *str);
int			ft_print_ptr(void *ptr);
int			ft_print_dec(int n);
int			ft_print_uns(unsigned int n);

char		**ft_array2d_create(int fd, char c);
int			ft_array2d_valid_path(t_array2d array2d,
				t_point begin, const char *floodplain);
int			ft_array2d_search(t_array2d array2d, char c, t_point *position);
int			get_size(char **array, t_point *size);
t_array2d	*ft_array2d_cpy(t_array2d array2d);
int			ft_array2d_len(char **array);

int			ft_error(const char*message,
				void (*free_func)(void *), void *content, int exit_bool);
void		*ft_error_ptr(const char*message,
				void (*free_func)(void *), void *content, int exit_bool);
void		ft_array2d_free(char **array, int i);

#endif

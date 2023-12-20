/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 19:08:14 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/20 14:15:26 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// Lib Includes
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

//// Macros
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

///Colors
# define C_WHITE "\033[0m"
# define C_RED "\033[38;5;196m"
# define C_LBLUE "\033[38;5;32m"
# define C_BROWN "\033[38;5;130m"
# define C_DBLUE "\033[38;5;21m"
# define C_NCYAN "\033[38;5;37m"
# define C_GREEN "\033[38;5;40m"

// Struct Define
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

////// SOURCE FILES
//// ft_isx
int		ft_open_quotes(char *s, char c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

//// ft_tox
char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);
int		ft_toupper(int c);
int		ft_tolower(int c);

//// ft_mem
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memdel(void *ptr);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

//// ft_put
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(char *s);
void	ft_putnbr(int nb);

//// ft_str
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_rejoin(char *s1, char *s2);
char	*ft_strrep(char *body, char *news);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//// ft_tab
char	**ft_tabcpy(char **old);
void	ft_freetab(char **tab);
int		ft_tablen(char **tab);

//// ft_list
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_lstsize(t_list *lst);

//// ft_printf
void	ft_lputchar(int c, int *len);
int		ft_printf(const char *str, ...);
int		ft_printc(char *color, const char *str, ...);
int		ft_ftypes(va_list args, const char format);
int		ft_printpercent(void);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printnbr(int nb);
int		ft_printunsigned(unsigned int nb);
int		ft_printhex(int nb, const char format);
int		ft_printpointer(unsigned long long ptr);
int		ft_nbrlen(int nb);

//// ft_gnl
char	*get_next_line(int fd);

//// ft_readline
char	*ft_readline(char *prompt);

#endif

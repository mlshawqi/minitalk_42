#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

// typedef struct s_list
// {
//         char                    **arr;
//         struct s_list   *next;
// }                                       t_list;

// char                            **ft_split(char const *s, char c);
// size_t                          ft_strlen(const char *s);
// int                                     ft_isdigit(int c);
// void                            add_node(t_list **head, char **arr);
int                                     ft_atoi(char *str);
void *ft_calloc(size_t count, size_t size);
size_t  ft_strlen(const char *s);
// void                            ft_lstclear(t_list **lst);
// void                            ft_lstdelone(t_list *lst);
// void                            del(char **t);
// int                                     check_overflow(long result, int digit, int sign,
//                                                 int *error);
void                            ft_bzero(void *s, size_t n);
// int                                     ft_isspace(int c);
// int                                     ft_strcmp(char *s1, char *s2);
// int                                     ft_isempty(char *str);
// int                                     is_sign(char *str, int i);

#endif
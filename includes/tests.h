/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 16:21:31 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 22:17:48 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# define RED "\e[91m"
# define GREEN "\e[32m"
# define MAGENTA "\e[35m"
# define BLUE "\e[34m"
# define NORMAL "\e[0m"

# define INT 1
# define STRING 2
# define PRINT 1
# define NO_PRINT 0

# include <libasm.h>

int		write_tests(void);
int		read_tests(void);
int		strlen_tests(void);
int		strcpy_tests(void);
int		strcmp_tests(void);
int		strdup_tests(void);
void	expect_eq(char *actual, const char *expected);
void	ft_list_add_elem_end(t_list **head, void *data);
void	print_list(t_list *head, int type);
void	free_list(t_list *head);
t_list	*create_list(int type, void *data, int len);
void	compare_lists(t_list *head1, t_list *head2, int (*cmp)(), int type);
int		cmp_num(int *data1, int *data2);

#endif

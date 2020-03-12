/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_sort_bonus_tests.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 22:07:37 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 22:09:42 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <libasm.h>
#include <stdio.h>
#include <tests.h>

void	ft_list_sort_test(int type, void *data, int len)
{
	t_list		*head;
	t_list		*sortedhead;
	int			int_sort_array[8] = {-400, 5, 13, 20, 35, 70, 420, 999};
	char		*sorted_array[8] = {
		"Anteater",
		"Baboon",
		"Chimpanzee",
		"Giraffe",
		"Lion",
		"Monkey",
		"Rhinoceros",
		"Thijs"
	};

	head = create_list(type, data, len);
	if (type == INT)
		sortedhead = create_list(INT, int_sort_array, 8);
	if (type == STRING)
		sortedhead = create_list(STRING, sorted_array, 8);
	/* print_list(head, type); */
	if (type == INT)
	{
		ft_list_sort(&head, &cmp_num);
		compare_lists(head, sortedhead, &cmp_num, type);
	}
	if (type == STRING)
	{
		ft_list_sort(&head, &strcmp);
		compare_lists(head, sortedhead, &strcmp, type);
	}
	/* print_list(head, type); */
	free_list(head);
	free_list(sortedhead);
}

Test(Bonus_Tests, ft_list_sort_test)
{
	int		int_array[8] = {20, 5, 70, 35, -400, 999, 13, 420};
	char	*str_array[8] = {
		"Giraffe",
		"Monkey",
		"Anteater",
		"Lion",
		"Thijs",
		"Baboon",
		"Chimpanzee",
		"Rhinoceros"
	};

	ft_list_sort_test(INT, int_array, 8);
	ft_list_sort_test(STRING, str_array, 8);
}

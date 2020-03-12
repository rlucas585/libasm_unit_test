/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_size_bonus_tests.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 22:01:46 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 22:06:06 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <libasm.h>
#include <string.h>
#include <stdio.h>
#include <tests.h>

void	ft_list_size_test(int type, void *data, int len)
{
	t_list		*head;

	head = create_list(type, data, len);
	/* print_list(head, type); */
	cr_expect(ft_list_size(head) == len, "Expected list size: |%d| Actual"
			" list size: %d", len, ft_list_size(head));
}

Test(Bonus_Tests, ft_list_size_test)
{
	int		int_array[4] = {5, 20, 35, 70};
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

	ft_list_size_test(INT, int_array, 4);
	ft_list_size_test(STRING, str_array, 8);
}

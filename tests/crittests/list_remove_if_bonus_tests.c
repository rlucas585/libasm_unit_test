/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_remove_if_bonus_tests.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 22:09:23 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 22:10:50 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <libasm.h>
#include <stdio.h>
#include <tests.h>

void	ft_list_remove_if_test(int type, void *data, int len)
{
	t_list		*head;
	t_list		*actual_list;
	char		removal_string[] = "Disgraceful Visual Studio Code User";
	char		removal_string2[] = "An emacs user???";
	char		removal_string3[] = "Glorious Vim User";
	char		*final_array[5] = {
		"Glorious Vim User",
		"Glorious Vim User",
		"Glorious Vim User",
		"An emacs user???",
		"Glorious Vim User"
	};

	head = create_list(type, data, len);
	actual_list = create_list(type, final_array, 5);
	ft_list_remove_if(&head, removal_string, &strcmp);
	cr_expect(ft_list_size(head) == 5, "Expected list length after element "
			"removal: 5 Actual: %d", ft_list_size(head));
	compare_lists(head, actual_list, &strcmp, type);
	ft_list_remove_if(&head, removal_string2, &strcmp);
	ft_list_remove_if(&head, removal_string3, &strcmp);
	cr_expect(ft_list_size(head) == 0, "Expected list length after element "
			"removal: 0 Actual: %d", ft_list_size(head));
	cr_expect(head == NULL, "head should be null after every element was"
			"removed by ft_list_remove_if.");
	free_list(head);
	free_list(actual_list);
}

Test(Bonus_Tests, ft_list_remove_if_test)
{
	char	*str_array[8] = {
		"Glorious Vim User",
		"Disgraceful Visual Studio Code User",
		"Disgraceful Visual Studio Code User",
		"Disgraceful Visual Studio Code User",
		"Glorious Vim User",
		"Glorious Vim User",
		"An emacs user???",
		"Glorious Vim User"
	};

	ft_list_remove_if_test(STRING, str_array, 8);
}

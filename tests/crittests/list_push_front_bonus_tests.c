/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_push_front_bonus_tests.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 22:12:23 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 22:12:45 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <libasm.h>
#include <stdio.h>
#include <tests.h>

void	ft_list_push_front_test(int type, void *data, int len)
{
	t_list		*head;
	t_list		*actual_list;
	int			new_ints[3] = {6, 61, 65};
	char		*new_strs[5] = {
		"Alien from the movie Alien",
		"Gazorpazorpfield",
		"Predator from the movie Alien vs Predator",
		"Mike Tyson",
		"Completely Normal Dog"
	};
	int			total_ints[7] = {65, 61, 6, 5, 20, 35, 70};
	char		*total_strs[13] = {
		"Completely Normal Dog",
		"Mike Tyson",
		"Predator from the movie Alien vs Predator",
		"Gazorpazorpfield",
		"Alien from the movie Alien",
		"Giraffe",
		"Monkey",
		"Anteater",
		"Lion",
		"Thijs",
		"Baboon",
		"Chimpanzee",
		"Rhinoceros"
	};

	head = create_list(type, data, len);
	if (type == INT)
	{
		actual_list = create_list(type, total_ints, 7);
		ft_list_push_front(&head, new_ints);
		ft_list_push_front(&head, new_ints + 1);
		ft_list_push_front(&head, new_ints + 2);
		compare_lists(head, actual_list, &cmp_num, type);
	}
	if (type == STRING)
	{
		actual_list = create_list(type, total_strs, 13);
		ft_list_push_front(&head, *new_strs);
		ft_list_push_front(&head, *(new_strs + 1));
		ft_list_push_front(&head, *(new_strs + 2));
		ft_list_push_front(&head, *(new_strs + 3));
		ft_list_push_front(&head, *(new_strs + 4));
		compare_lists(head, actual_list, &strcmp, type);
	}
	/* print_list(head, type); */
	free_list(head);
	free_list(actual_list);
}

Test(Bonus_Tests, ft_list_push_front_test)
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

	ft_list_push_front_test(INT, int_array, 4);
	ft_list_push_front_test(STRING, str_array, 8);
}

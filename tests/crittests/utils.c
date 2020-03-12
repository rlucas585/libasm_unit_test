/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 19:34:37 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 22:19:31 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <libasm.h>
#include <tests.h>
#include <stdlib.h>
#include <stdio.h>

void	expect_eq(char *actual, const char *expected)
{
	if (!actual)
		cr_expect_fail("*Actual*: NULL\nExpected: \"%s\"", expected);
	else
		cr_expect_str_eq(actual, expected, "*Actual*: \"%s\""
				"\nExpected: \"%s\"", actual, expected);
}

void	ft_list_add_elem_end(t_list **head, void *data)
{
	t_list		*current;

	if (head == NULL)
		return ;
	if (*head == NULL)
	{
		*head = (t_list *)malloc(sizeof(t_list));
		(*head)->data = data;
		(*head)->next = NULL;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = (t_list *)malloc(sizeof(t_list));
	current = current->next;
	current->data = data;
	current->next = NULL;
}

void	print_list(t_list *head, int type)
{
	t_list	*current;
	int		i;

	i = 0;
	current = head;
	while (current)
	{
		if (type == INT)
			printf("List member [%d]: %d\n", i, *(int *)current->data);
		if (type == STRING)
			printf("List member [%d]: %s\n", i, (char *)current->data);
		current = current->next;
		i++;
	}
}

void	free_list(t_list *head)
{
	t_list	*current;
	t_list	*next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

t_list	*create_list(int type, void *data, int len)
{
	t_list	*head;
	int		i;

	i = 0;
	head = NULL;
	while (i < len)
	{
		if (type == INT)
			ft_list_add_elem_end(&head, data + 4 * i);
		if (type == STRING)
			ft_list_add_elem_end(&head, *(void **)(data + 8 * i));
		i++;
	}
	return (head);
}

void	compare_lists(t_list *head1, t_list *head2, int (*cmp)(), int type)
{
	t_list		*current1;
	t_list		*current2;
	int			i;

	current1 = head1;
	current2 = head2;
	i = 0;
	while (current1 && current2)
	{
		if (type == INT)
			cr_expect(cmp(current1->data, current2->data) == 0, "At position "
					"[%d] of your list, %d was expected, and %d was found",
					i, *(int *)current2->data, *(int *)current1->data);
		if (type == STRING)
			cr_expect(cmp(current1->data, current2->data) == 0, "At position "
					"[%d] of your list, %s was expected, and %s was found",
					i, (char *)current2->data, (char *)current1->data);
		current1 = current1->next;
		current2 = current2->next;
		i++;
	}
	cr_expect(current1 == current2, "Your list is not the same length as"
			" was expected.");
}

int		cmp_num(int *data1, int *data2)
{
	return (*data1 - *data2);
}

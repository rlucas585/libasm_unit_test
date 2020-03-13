/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcmp_tests.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 21:58:47 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/13 15:04:02 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <libasm.h>
#include <string.h>
#include <stdio.h>

void	strcmp_test(const char *str1, const char *str2)
{
	char		*str3;
	char		*str4;

	str3 = strdup(str1);
	str4 = strdup(str2);
	cr_expect(strcmp(str3, str4) == ft_strcmp(str3, str4));
	free(str3);
	free(str4);
}

Test(Mandatory_Tests, strcmp_test)
{
	strcmp_test("STRing 1", "STRing 2");
	strcmp_test("", "STRing 2");
	strcmp_test("", "");
	strcmp_test("STRing 2", "");
	strcmp_test("oadkfskfjl", "--wkwefjk3jf");
	strcmp_test("Exactly the same", "Exactly the same");
	strcmp_test("String for compare", "");
}

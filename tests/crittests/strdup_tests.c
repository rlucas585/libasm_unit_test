/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cr_strdup_test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 19:33:48 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 22:07:17 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <libasm.h>
#include <stdio.h>
#include <tests.h>

void	strdup_test(const char *str)
{
	char		*mystr;
	char		*teststr;

	mystr = ft_strdup(str);
	teststr = strdup(str);
	expect_eq(mystr, teststr);
	free(mystr);
	free(teststr);
}

Test(Mandatory_Tests, strdup_test)
{
	strdup_test("A test with a moderate length string\n");
	strdup_test("");
	strdup_test("											"
			"							empty				"
			"with				tabs");
}

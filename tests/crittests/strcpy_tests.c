/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcpy_tests.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 21:57:35 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 21:58:34 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <libasm.h>
#include <string.h>
#include <stdio.h>

void	strcpy_test(const char *str)
{
	char		*str1;
	char		*str2;
	char		str3[300];
	char		str4[300];

	str1 = (char *)malloc(sizeof(char) * strlen(str) + 1);
	if (!str1)
		return ;
	str2 = (char *)malloc(sizeof(char) * strlen(str) + 1);
	if (!str2)
	{
		free(str1);
		return ;
	}
	strcpy(str1, str);
	ft_strcpy(str2, str);
	cr_expect_str_eq(str2, str1, "*Actual*: \"%s\""
			"\nExpected: \"%s\"", str2, str1);
	cr_expect(strcmp(str1, str2) == 0);
	free(str1);
	free(str2);
	strcpy(str3, str);
	ft_strcpy(str4, str);
	cr_expect_str_eq(str4, str3, "*Actual*: \"%s\""
			"\nExpected: \"%s\"", str4, str3);
	cr_expect(strcmp(str3, str4) == 0);
	bzero(str3, 300);
	bzero(str4, 300);
}

Test(Mandatory_Tests, strcpy_test)
{
	strcpy_test("Baba Ganoush");
	strcpy_test("");
	strcpy_test("akfjdsklfjsenioeanvevjawklcjekcmkescaklemcklejacklejaklj"
			"cjeisojfesickjcskljeksjeksjcklesjcklejskcje");
	strcpy_test("Have you ever heard the story of Darth Plageuius the Wise?"
			"I thought not. It's not a story the Jedi would teach you.");
}

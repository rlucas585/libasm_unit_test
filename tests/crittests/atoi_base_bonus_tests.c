/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atoi_base_bonus_tests.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 22:10:39 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 22:11:16 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <libasm.h>
#include <stdio.h>
#include <tests.h>

void	ft_atoi_base_test(const char *test, const char *base,
		int expected, int print)
{
	int		actual;

	actual = ft_atoi_base((char *)test, (char *)base);
	cr_expect(actual == expected, "Number: %s Base: %s Expected: %d Actual %d",
			test, base, expected, actual);
	if (print)
	{
		printf("Number: %s Base: %s Expected: %d Actual: %d\n",
				test, base, expected, actual);
	}
}

Test(Bonus_Tests, ft_atoi_base_test)
{
	ft_atoi_base_test("510", "011", 0, NO_PRINT);
	ft_atoi_base_test("510", "0123456789", 510, NO_PRINT);
	ft_atoi_base_test("-ryan", "0123456789abcdefghijklmnopqrstuvwxyz",
			-1304159, NO_PRINT);
	ft_atoi_base_test("+ryan", "0123456789abcdefghijklmnopqrstuvwxyz",
			1304159, NO_PRINT);
	ft_atoi_base_test("ryan", "0123456789abcdefghijklmnopqrstuvwxyz",
			1304159, NO_PRINT);
	ft_atoi_base_test("aec", "0abcdefghi", 153, NO_PRINT);
	ft_atoi_base_test("11001010101011", "01", 12971, NO_PRINT);
	ft_atoi_base_test("", "01", 0, NO_PRINT);
	ft_atoi_base_test("1500", "", 0, NO_PRINT);
	ft_atoi_base_test("15		", "	123456789", 1500, NO_PRINT);
	ft_atoi_base_test("	1500", "0123456789", 0, NO_PRINT);
	ft_atoi_base_test("			\n-15   00", "0123456789", 0, NO_PRINT);
	ft_atoi_base_test("-X4ny;;;", ";xy4[]fnGX", -9372000, NO_PRINT);
	ft_atoi_base_test("-X4ny;;;", ";xy4[ffnGX", 0, NO_PRINT);
	ft_atoi_base_test("XXX", "OoXx", 42, NO_PRINT);
	ft_atoi_base_test("01010", "01", 10, NO_PRINT);
	ft_atoi_base_test("0101010", "01", 42, NO_PRINT);
	ft_atoi_base_test("thijs", "0123456789abcdefghijklmnopqrstuvwxyz",
			49526056, NO_PRINT);
}

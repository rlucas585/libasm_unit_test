/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_tests.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 21:52:33 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 22:20:48 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <libasm.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	read_test(const char *str)
{
	int		fd;
	int		ret1;
	int		ret2;
	char	mybuf[150];
	char	sysbuf[150];

	fd = open(str, O_RDONLY);
	ret1 = read(fd, sysbuf, 148);
	sysbuf[ret1] = '\0';
	close(fd);
	fd = open(str, O_RDONLY);
	ret2 = ft_read(fd, mybuf, 148);
	mybuf[ret2] = '\0';
	cr_expect(ret1 == ret2);
	cr_expect_str_eq(mybuf, sysbuf, "*Actual*: \"%s\""
			"\nExpected: \"%s\"", mybuf, sysbuf);
	close(fd);
}

Test(Mandatory_Tests, read_test)
{
	read_test("tests/texts/darth_plagueis.txt");
	read_test("tests/texts/testread.txt");
	read_test("tests/texts/notafile.txt");
	read_test("tests/texts/empty.txt");
}

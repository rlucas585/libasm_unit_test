/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_tests.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 21:44:05 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 22:32:01 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <libasm.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	write_test(const char *str)
{
	int		fd;
	int		fd2;
	int		ret1;
	int		ret2;
	FILE	*file;
	FILE	*expected;

	fd = open("tests/texts/actualoutput.txt", O_RDWR | O_CREAT, 0644);
	fd2 = open("tests/texts/output.txt", O_RDWR | O_CREAT, 0644);
	ret1 = write(fd, str, strlen(str));
	ret2 = ft_write(fd2, str, strlen(str));
	close(fd);
	close(fd2);
	file = fopen("tests/texts/output.txt", "r");
	expected = fopen("tests/texts/actualoutput.txt", "r");
	cr_expect(ret1 == ret2);
	cr_expect_file_contents_eq(file, expected, "When str = '%s'\n", str);
	fclose(file);
	fclose(expected);
	remove("tests/texts/actualoutput.txt");
	remove("tests/texts/output.txt");
}

Test(Mandatory_Tests, write_test)
{
	/* Commented out section demonstrates that cr_expect_file_contents_eq fails */
	/* 	when the files are both empty */
	/* This is why the test with empty string will always fail. */

	/* FILE *test1; */
	/* FILE *test2; */
	/* test1 = fopen("tests/texts/empty.txt", "r"); */
	/* test2 = fopen("tests/texts/empty2.txt", "r"); */
	write_test("starting with something easy\n");
	/* write_test(""); */ // Always fails
	write_test("a");
	write_test("Did you ever hear the tragedy of Darth Plagueis The Wise? "
			"I thought not."
			" It's not a story the Jedi would tell you. It's a Sith legend. Darth "
			"Plagueis was a Dark Lord of the Sith, so powerful and so wise he could "
			"use the Force to influence the midichlorians to create life... He had "
			"such a knowledge of the dark side, he could even keep the ones he cared "
			"about from dying. The dark side of the Force is a pathway to many "
			"abilities some consider to be unnatural. He became so powerful... the "
			"only thing he was afraid of was losing his power, which eventually, "
			"of course, he did. Unfortunately, he taught his apprentice everything "
			"he knew, then his apprentice killed him in his sleep. Ironic. He could "
			"save others from death, but not himself.\n");
	/* cr_expect_file_contents_eq(test1, test2, "Empty file comparison problem?\n"); */
	/* fclose(test1); */
	/* fclose(test2); */
}

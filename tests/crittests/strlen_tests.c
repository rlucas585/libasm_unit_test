/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strlen_tests.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlucas <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 21:56:43 by rlucas        #+#    #+#                 */
/*   Updated: 2020/03/12 21:57:46 by rlucas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <libasm.h>
#include <string.h>
#include <stdio.h>

void	strlen_test(const char *str)
{
	cr_expect(strlen(str) == ft_strlen(str));
}

Test(Mandatory_Tests, strlen_test)
{
	strlen_test("string with length");
	strlen_test("longlonglonglonglonglonglonglonglonglonglonglonglong"
			"longlonglonglonglonglonglonglonglonglonglong"
			"longlonglonglonglonglonglonglonglonglonglonglonglong");
	strlen_test("");
	strlen_test(
			"Did you ever hear the tragedy of Darth Plagueis The Wise? I thought not."
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
	strlen_test(
			"Porcupines are large rodents with coats of sharp spines, or "
			"quills, that protect them against predators. The term covers "
			"two families of animals: the Old World porcupines of family "
			"Hystricidae, and the New World porcupines af family Erethizontidae"
			". Both families belong to the infraorder Hystricognathi within the"
			" profoundly diverse order Rodentia and display superficially "
			"similar coats of quills: despite this, the two groups are distinct"
			" from each other and are not closely related to each other within "
			"the Hystricognathi."
			);
}


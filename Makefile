# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rlucas <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/20 10:00:23 by rlucas        #+#    #+#                  #
#    Updated: 2020/03/12 19:11:52 by rlucas        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#-------------------------------------------------------------------------------


LIB = libasm.a

HEADDIR = includes/

TESTDIR = tests/

TESTEXEC = test


#-----------------------------Select sources------------------------------------

SRC = $(TESTDIR)nocrit_main.c \
	  $(TESTDIR)write_tests.c \
	  $(TESTDIR)read_tests.c \
	  $(TESTDIR)strlen_tests.c \
	  $(TESTDIR)strcpy_tests.c \
	  $(TESTDIR)strcmp_tests.c \
	  $(TESTDIR)strdup_tests.c

CRITSRC = $(TESTDIR)tests.c \
	  $(TESTDIR)testmain.c

BONUSCRITSRC = $(TESTDIR)testmain_bonus.c \
		   $(TESTDIR)tests_bonus.c

ifdef WITH_BONUS
	CRITSRC += $(BONUSCRITSRC)
endif

#------------------------Library and Flags definitions--------------------------

FLAGS = -Wall -Wextra -Werror

#---------------------Compile test executable (criterion)-----------------------

test:
	@gcc $(FLAGS) -I$(HEADDIR) -o $(TESTEXEC) $(CRITSRC) -L. \
		-l$(subst .a,,$(subst lib,,$(LIB))) \
		-lcriterion
	@./$(TESTEXEC)
	@rm -f $(TESTEXEC)

bonustest:
	@$(MAKE) WITH_BONUS=1 test

#---------------------Compile test executable (no criterion)--------------------

nocrit:
	@$(MAKE) NOCRIT=1 nocrittest

nocrittest:
	@gcc $(FLAGS) -I$(HEADDIR) -o $(TESTEXEC) $(SRC) -L. \
		-l$(subst .a,,$(subst lib,,$(LIB)))
	@./$(TESTEXEC)
	@rm -f $(TESTEXEC)

#-----------------------------Phony instructions--------------------------------

.PHONY: test bonustest nocrit

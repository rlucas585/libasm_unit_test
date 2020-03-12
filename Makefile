# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rlucas <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/20 10:00:23 by rlucas        #+#    #+#                  #
#    Updated: 2020/03/12 22:39:21 by rlucas        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#-------------------------------------------------------------------------------


LIB = libasm.a

HEADDIR = includes/

TESTDIR = tests/

CRITTESTDIR = tests/crittests/

TESTEXEC = test

#-----------------------------Select sources------------------------------------

SRC = $(TESTDIR)nocrit_main.c \
	  $(TESTDIR)write_tests.c \
	  $(TESTDIR)read_tests.c \
	  $(TESTDIR)strlen_tests.c \
	  $(TESTDIR)strcpy_tests.c \
	  $(TESTDIR)strcmp_tests.c \
	  $(TESTDIR)strdup_tests.c

ALLOBJ = ft_write.o \
		 ft_read.o \
		 ft_strlen.o \
		 ft_strcpy.o \
		 ft_strcmp.o \
		 ft_strdup.o

BONUSOBJ = ft_list_size_bonus.o \
		   ft_list_push_front_bonus.o \
		   ft_list_sort_bonus.o \
		   ft_list_remove_if_bonus.o \
		   ft_atoi_base_bonus.o

PAREN1 = (
PAREN2 = )

CRITSRC = $(CRITTESTDIR)utils.c

PRESENTFUNCS = $(shell nm libasm.a | grep "\.o")

FUNCS = $(foreach object,$(PRESENTFUNCS),$(subst libasm.a$(PAREN1),,$(subst $(PAREN2):,,$(object))))

ABSENT = $(filter-out $(FUNCS),$(ALLOBJ) $(BONUSOBJ))

TOCOMPILE = $(filter-out $(ABSENT),$(ALLOBJ) $(BONUSOBJ))

CRITSRC += $(patsubst ft_%.o,$(CRITTESTDIR)%_tests.c,$(TOCOMPILE))

check:
	@printf "$(CRITSRC)\n"

#------------------------Library and Flags definitions--------------------------

FLAGS = -Wall -Wextra -Werror

#---------------------Compile test executable (criterion)-----------------------


test:
ifneq ($(ABSENT),)
	@printf "The following functions are absent from your libasm.a: $(ABSENT)\n\n"
endif
	@gcc $(FLAGS) -I$(HEADDIR) -o $(TESTEXEC) $(CRITSRC) -L. \
		-l$(subst .a,,$(subst lib,,$(LIB))) \
		-lcriterion
	@./$(TESTEXEC)
	@rm -f $(TESTEXEC)

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

#ifndef SUITE_H
# define SUITE_H

#include <string.h>
#include <stdlib.h>
#include <test.h>
# define MAX_TESTS_PER_SUITE 1000

typedef struct s_suite t_suite;

typedef	void (t_suite_fn)(t_suite *);

typedef struct				s_suite
{
	char					*name;
	t_suite_fn				*fn;
	t_test					**tests;
	int						x_success_count;
	int						x_warning_count;
}							t_suite;

t_suite			*suite_create(char *name, t_suite_fn *fn);
void			suite_add_test(t_suite *suite, t_test	*test);
void			suite_exec(t_suite *suite);

#endif

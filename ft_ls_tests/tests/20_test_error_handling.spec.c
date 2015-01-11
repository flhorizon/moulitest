#include <project.h>



static 	char *cmd;
static	char *ls_out_str;
static	char *ft_ls_out_str;

static void unitTest_00(t_test *test)
{
	reset_sandbox();
	cmd = "does_not_exit";
	mt_assert(strlen(ft_ls_err(cmd)) > 0);
}

static void unitTest_01(t_test *test)
{
	sandbox_cmd("mkdir -p not_allowed_file");
	sandbox_cmd("chmod 000 not_allowed_file");
	cmd = "not_allowed_file";
	mt_assert(strlen(ft_ls_err(cmd)) > 0);
	reset_sandbox();	
}

static void unitTest_02(t_test *test) 
{
	cmd = "-Z_this_option_does_not_exist";
	mt_assert(strlen(ft_ls_err(cmd)) > 0);
	
}


static void unitTest_03(t_test *test) 
{
	cmd = "-la--t"; // Invalid hyphen option
	mt_assert(strlen(ft_ls_err(cmd)) > 0);
	
}


static void unitTest_04(t_test *test) 
{
	cmd = "--a";
	mt_assert(strlen(ft_ls_err(cmd)) > 0);
	
}

static void unitTest_05(t_test *test) 
{
	cmd = "\"\"";
	mt_assert(strlen(ft_ls_err(cmd)) > 0);
	
}

static void unitTest_06(t_test *test) 
{
	cmd = "''";
	mt_assert(strlen(ft_ls_err(cmd)) > 0);
}

static void unitTest_07(t_test *test) 
{
	sandbox_cmd("touch a b");
	cmd = "a '' b";
	mt_assert(strlen(ft_ls_err(cmd)) > 0);	
}


static void unitTest_08(t_test *test) 
{
	cmd = "-lZWYX243";
	ft_ls_out_str = strip_illegal_opt_err(ft_ls(cmd));
	ls_out_str = strip_illegal_opt_err(ls(cmd));
	mt_assert(strcmp(ls_out_str, ft_ls_out_str));	
}


static void unitTest_09(t_test *test) 
{
	cmd = "--a";
	ft_ls_out_str = strip_illegal_opt_err(ft_ls(cmd));
	ls_out_str = strip_illegal_opt_err(ls(cmd));
	mt_assert(strcmp(ls_out_str, ft_ls_out_str));

	reset_sandbox();
}

static void unitTest_10(t_test *test) 
{
	cmd = "a b";
	ft_ls_out_str = strip_no_such_file_or_dir(ft_ls(cmd));
	ls_out_str = strip_no_such_file_or_dir(ls(cmd));
	mt_assert(strcmp(ls_out_str, ft_ls_out_str));
}

static void unitTest_11(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir b");
	cmd = "-1 a b";
	ft_ls_out_str = strip_no_such_file_or_dir(ft_ls(cmd));
	ls_out_str = strip_no_such_file_or_dir(ls(cmd));
	mt_assert(strcmp(ls_out_str, ft_ls_out_str));
}

static void unitTest_12(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("mkdir adir zdir");
	sandbox_cmd("touch afile zfile");
	sandbox_cmd("ln -s adir asymdir");
	sandbox_cmd("ln -s adir zsymdir");
	sandbox_cmd("ln -s afile asymfile");
	sandbox_cmd("ln -s afile zsymfile");
	cmd = "-1 adir zdir aNotExist zNotExistB afile zfile asymdir zsymdir asymfile zsymfile";
	ft_ls_out_str = strip_no_such_file_or_dir(ft_ls(cmd));
	ls_out_str = strip_no_such_file_or_dir(ls(cmd));
	mt_assert(strcmp(ls_out_str, ft_ls_out_str));
}


static void unitTest_13(t_test *test) 
{
	reset_sandbox();
	sandbox_cmd("touch K j l");
	cmd = "-1r a c b l K j";
	ft_ls_out_str = strip_no_such_file_or_dir(ft_ls(cmd));
	ls_out_str = strip_no_such_file_or_dir(ls(cmd));
	mt_assert(strcmp(ls_out_str, ft_ls_out_str));
}

void	suite_20_test_error_handling(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unitTest_00);
	SUITE_ADD_TEST(suite, unitTest_01);
	SUITE_ADD_TEST(suite, unitTest_02);
	SUITE_ADD_TEST(suite, unitTest_03);
	SUITE_ADD_TEST(suite, unitTest_04);
	SUITE_ADD_TEST(suite, unitTest_05);
	SUITE_ADD_TEST(suite, unitTest_06);
	SUITE_ADD_TEST(suite, unitTest_07);
	SUITE_ADD_TEST(suite, unitTest_08);
	SUITE_ADD_TEST(suite, unitTest_09);
	SUITE_ADD_TEST(suite, unitTest_10);
	SUITE_ADD_TEST(suite, unitTest_11);
	SUITE_ADD_TEST(suite, unitTest_12);
	SUITE_ADD_TEST(suite, unitTest_13);	
}
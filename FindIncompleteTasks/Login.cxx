#include"Header.h"

int ITK_user_main(int 	argc, char** argv)
{
	int status = ITK_ok;

	char* ID = ITK_ask_cli_argument("-id=");

	status = ITK_init_module("dcproxy", "dcproxy", "dba");

	if (status == ITK_ok)
	{
		cout << "Login Success\n";
		
		PromoteTask();
	}
	else
	{
		char* text = NULL;
		status = EMH_ask_error_text(status, &text);
		cout << "\n" << text;
		if (text)
		{
			MEM_free(text);
		}
	}
	status = ITK_exit_module(true);
	return status;
}
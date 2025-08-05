#include"Header.h"

int PromoteTask()
{
	int status = ITK_ok;
	tag_t query = NULLTAG;

	status = QRY_find2("to find all incomplete tasks", &query);
	ERRHAND;

	int n_entries = NULL;

	char** entries = (char**)MEM_alloc(sizeof(char**));
	entries[0] = (char*)MEM_alloc(strlen("Id") * sizeof(char*));
	strcpy(entries[0], "Id");
	ERRHAND;
	char** values = (char**)MEM_alloc(sizeof(char**));
	values[0] = (char*)MEM_alloc(strlen("dcproxy") * sizeof(char*));
	strcpy(values[0], "dcproxy");
	ERRHAND;

	status = QRY_find_user_entries(query, &n_entries, &entries, &values);
	ERRHAND;

	int n_found = NULL;
	tag_t* results = nullptr;
	status = QRY_execute(query, n_entries, entries, values, &n_found, &results);
 	ERRHAND;

	date_t start_date = { 0 };
	

	for (int i = 0; i < n_found; i++)
	{
		status = AOM_ask_value_date(results[i], "fnd0StartDate", &start_date);
		ERRHAND;

		int day = start_date.day;
		int month = start_date.month;
		int year = start_date.year;

		time_t now;
		time(&now);

		struct tm a;
		a.tm_mday = day;
		a.tm_mon = month;
		a.tm_year = year - 1900;
		a.tm_hour = 0;
		a.tm_min = 0;
		a.tm_sec = 0;

		time_t z = mktime(&a);
		double u = difftime(now, z);

		char* task_name = nullptr;

		status = AOM_ask_value_string(results[i], "task_type", &task_name);
		ERRHAND;

		if (u > 172800)
		{
			status = ITK_set_bypass(true);
			ERRHAND;

			status = EPM_promote_task(results[i], "task promoted due to incompletion of 2 days");
			ERRHAND;

			status = ITK_set_bypass(false);
			ERRHAND;
		}
	}

	return status;
}
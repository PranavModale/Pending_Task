#undef _DEBUG
#undef DEBUG

#define ERRHAND if(status != ITK_ok) { char* text = NULL; status = EMH_ask_error_text(status, &text); cout << "\n" << text; if (text) MEM_free(text); exit(0);}
#define _CRT_SECURE_NO_WARNINGS
#include<tc/tc_startup.h>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<tcinit/tcinit.h>
#include<tc/emh.h>
#include<tccore/tctype.h>
#include<tccore/aom_prop.h>
#include<tccore/aom.h>
#include<sa/user.h>
#include<tccore/item.h>
#include<tc/folder.h>
#include<tccore/grm.h>
#include<ae/dataset.h>
#include<fstream>
#include<string>
#include<string.h>
#include<tccore/workspaceobject.h>
#include<sstream>
#include<qry/qry.h>
#include<bom/bom.h>
#include<bom/bom_attr.h>
#include<epm/epm.h>
using namespace std;

int PromoteTask();

//tc_strcmp(task_name, "EPMSelectSignoffTask") != 0 && tc_strcmp(task_name, "EPMPerformSignOffTask") != 0
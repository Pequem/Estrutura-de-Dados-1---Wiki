#include <stdio.h>
#include <stdlib.h>
#include "Definicoes.h"
#include "Log.h"

int printLog(char * msg, char *msg2, char *msg3)
{
	FILE *log;
	log = fopen("log.txt", "w");
	
	if (log == NULL)
	{
		return 0; 
	}

	fprintf(log, "%s %s %s\n", msg,msg2,msg3);

	return 1;
	fclose(log);
}

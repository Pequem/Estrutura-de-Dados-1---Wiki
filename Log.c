#include <stdio.h>
#include <stdlib.h>
#include "Log.h"

int printLog(char * msg, char *msg2, char *msg3)
{
    FILE *log;
    log = fopen("log.txt", "w"); //TROCA PARA "APENND"!
	
    if (log == NULL)
        return 0;

    fprintf(log, "%s %s %s\n", msg,msg2,msg3);

    fclose(log);
    
    return 1;
}
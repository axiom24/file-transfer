#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
int main() { 
	
	int system_exit_integer;

	char command_buffer[200];
	time_t ltime; /* calendar time */
    ltime=time(NULL); /* get current cal time */
    printf("%s",asctime( localtime(&ltime) ) );
	char *str1;
	char *st;

	char *str2;
	st=asctime( localtime(&ltime) );
	while(*st++ && *str1)
     {
        if (!isspace(*st)) 
             *str1++ = *st;
        else
        	strcat (str1,"-");
        	
     }
	
	strcat (str1,".tar.gz");
	str2="/media/livingstore";
	sprintf(command_buffer, "tar -zcvf %s %s", str1,str2);
	printf("calling system(%s)\n", command_buffer);
	system_exit_integer = system(command_buffer);
	printf("system() returned %d \n",system_exit_integer);
	if(system_exit_integer != EXIT_SUCCESS) {
		printf("Bhenchod! \n");
		return EXIT_FAILURE;
	}

	sprintf(command_buffer,"rm -r %s", str2);
	printf("calling system(%s)\n", command_buffer);
	system_exit_integer = system(command_buffer);
	printf("system() returned %d \n",system_exit_integer);
	if(system_exit_integer != EXIT_SUCCESS) {
		printf("Bhenchod! \n");
		return EXIT_FAILURE;
	}

	return 0;	

}

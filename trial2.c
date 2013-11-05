#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() { 
	
	

	time_t ltime; /* calendar time */
    ltime=time(NULL); /* get current cal time */
    printf("%s",asctime( localtime(&ltime) ) );
    
   
    char command[50];

    strcpy( command, "zip -r " );
    char st[50],str1[50];
    strcpy(st,asctime( localtime(&ltime) ));
	int i=0;
	int y=strlen(st);
	printf("%d",y);
	while(i<19)
     {
        if (!isspace(st[i])) 
           {  str1[i] = st[i];
         	i++;
         }
        else
        	{
        		strcat (str1,"-");
        		i++;
        	}
        	
     }
     printf("%s", st);
    printf("%s", str1);
	strcat (command,str1);
	strcat (command,".zip ");
	strcat (command,"/media/livingstore");   //replace livingstore with your username

	system(command);
	
	return 0;	

}

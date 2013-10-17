#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) { 
	
	int system_exit_integer;

	char command_buffer[200];

	if(argc != 3) {
		printf("USAGE: ./file_transfer destination_zip_file_path source_directory_path\n");

		return -1;
		}
	
	sprintf(command_buffer, "tar -cvzf %s %s", argv[1], argv[2]);
	printf("calling system(%s)\n", command_buffer);
	system_exit_integer = system(command_buffer);
	printf("system() returned %d \n",system_exit_integer);
	if(system_exit_integer != EXIT_SUCCESS) {
		printf("Bhenchod! \n");
		return EXIT_FAILURE;
	}

	sprintf(command_buffer,"rm -r %s", argv[2]);
	printf("calling system(%s)\n", command_buffer);
	system_exit_integer = system(command_buffer);
	printf("system() returned %d \n",system_exit_integer);
	if(system_exit_integer != EXIT_SUCCESS) {
		printf("Bhenchod! \n");
		return EXIT_FAILURE;
	}

	return 0;	

}

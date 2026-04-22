#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	char *file;
	int fd;
	struct flock lock;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return 1;
	}
	file = argv[1];
	printf("Opening %s\n", file);
	//TODO: Open the File for read write
	fd=open("assignments.txt",O_RDWR);
         if (fd < 0) {
        perror("open");
        return 1;
       }

	
	printf("\nLocking ... ");
	//TODO: Zero out the 'lock' and initialize the various fields to lock the 
	//Entire file
	// Initialize lock structure
       memset(&lock, 0, sizeof(lock));
       lock.l_type = F_RDLCK;   // Write lock
       lock.l_whence = SEEK_SET; // From beginning
       lock.l_start = 0;         // Start of file
       lock.l_len = 0;           // 0 means lock entire file


	//TODO: Invoke fcntl to lock the file
	  // Apply lock
       if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl lock");
        return 1;
        }

	printf("Done. Hit <Enter> to unlock ...\n");
	getchar();
	printf("Unlocking ... ");
	//TODO: Invoke fcntl to unlock the file
	lock.l_type = F_UNLCK;
        if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl unlock");
        return 1;
        }

	printf("Done.\n");

	close(fd);
	return 0;
}

#include <stdlib.h>

int main()
{
	int return_value;

	return_value = system("ls -l /");
	int ret;
	ret=system("ps -x");
	printf("%d",ret);
	return return_value;
}

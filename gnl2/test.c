
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

#include "get_next_line_bonus.h"


int main(int argc, char *argv[]) {
	int fd;
	if (argc >= 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	char *line;
	printf("fd %d\n", fd);

	for (int i = 0; line = get_next_line(fd); i++) {
		printf("line %d - len %d : %s", i, (int)strlen(line), line);
		free(line);
	}
}

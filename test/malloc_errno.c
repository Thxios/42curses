
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>


int main() {
	void *tmp = calloc(10, 1000000000000);
	assert(tmp == NULL);
	printf("errno %d\n", errno);
	printf(strerror(errno));
}

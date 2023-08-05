
#include <stdio.h>
#include <sys/time.h>


int main() {
	struct timeval st;


	gettimeofday(&st, 0);
	printf("%li, %d\n", st.tv_sec, st.tv_usec);
}

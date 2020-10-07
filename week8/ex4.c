#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>

int main(void) {
  int *data = NULL;
  size_t s = 0;
  struct rusage usage;
  printf("User CPU time, System CPU time and shared memory for every second: ");

  for (int i = 0; i < 10; i++){
    s = s + 10*1024*1024;
    data = realloc(data, s);
    
    memset(data, 0, s);

    getrusage(RUSAGE_SELF, &usage);
    printf("%ld, %ld, %ld\n",
    usage.ru_utime.tv_usec,
		usage.ru_stime.tv_usec,
    usage.ru_ixrss);

    sleep(1);
  }

  free(data);
}
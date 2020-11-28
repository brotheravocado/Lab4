#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 3
#include <string.h>

void *thread (char *s)
{
printf("Thread %d: Hello, World!\n", *s);
return *s;
}
int main(int argc , char *argv )
{
char s[10] = "hello";
pthread_t tid[NUM_THREADS];
int i, status;

/* 쓰레드 생성 */
for (i = 0; i < NUM_THREADS; i++) {
status = pthread_create (&tid[i], NULL,thread, *s);
if (status != 0) {
fprintf (stderr, "Create thread %d: %d", i, status);
exit (1);
}
}
pthread_exit (NULL);
}
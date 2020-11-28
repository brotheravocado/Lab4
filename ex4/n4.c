

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

int status = 0;
int c = 0;
int count = 0;
int check = 1;
pthread_t tid[3];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex_parent = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_parent = PTHREAD_COND_INITIALIZER;

void *child(void *arg)
{
    while (1)
    {
        sleep(1);

        int random = rand() % 3 + 1;

        if (status == 0 && check == 1)
        {
            check = 0;
            printf("\n");

            printf("%dst child thread - call message\n", *((int *)arg));
            c = *((int *)arg);
            status = 1;
        }

        if (count == NUM_THREADS && check == 0)
        {

            count = 0;
            check = 1;

            pthread_cond_broadcast(&cond_parent);
            sleep(1);
        }
        else if (count < NUM_THREADS && check == 0)
        {

            count++;
            sleep(1);
            pthread_mutex_lock(&mutex);
            pthread_cond_wait(&cond, &mutex);

            printf("%dst child thread - message \n", *((int *)arg));
            pthread_mutex_unlock(&mutex);
        }
    }
}

void *parent(void *arg)
{
    while (1)
    {
        sleep(1);
        if (status == 1)
        {

            pthread_mutex_lock(&mutex_parent);
            printf("\n");
            printf("");
            status = 0;
            pthread_cond_broadcast(&cond);

            pthread_mutex_unlock(&mutex_parent);
        }
        else
        {

            sleep(1);
        }
    }
}

void main()
{
    srand(time(NULL));
    int i;
    int id[NUM_THREADS];

    status = pthread_create(&tid[0], NULL, parent, (void *)&id[0]);

    for (i = 1; i <= NUM_THREADS; i++)
    {
        id[i] = i;

        status = pthread_create(&tid[i], NULL, child, (void *)&id[i]);
    }

    for (i = 1; i <= NUM_THREADS; i++)
    {
        pthread_join(tid[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex_parent);

    pthread_cond_destroy(&cond_parent);
}
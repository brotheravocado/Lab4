/* 4. 클라이언트(자식) 쓰레드들로부터 메시지 전송 요청을 받으면 서버(부모) 쓰레
드는 모든 클라이언트 쓰레드에게 메시지를 방송하는 프로그램을 구현하시오.
(힌트: 소켓은 사용하지 말고 데이터 전송을 위한 동기화를 위해 뮤텍스와 조건
변수를 사용한다.)*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM 3

int status = 0;
int count = 0;
int check = 1;
pthread_t tid[3];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex_parent = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_parent = PTHREAD_COND_INITIALIZER;

void *client(void *arg)
{
    while (1)
    {
        sleep(1);

        if (status == 0 && check == 1)
        {
            check = 0;
            printf("\n [%d] client 쓰레드 메세지 요청 \n", *((int *)arg));
            status = 1;
        }

        if (count == NUM && check == 0)
        {
            count = 0;
            check = 1;

            pthread_cond_broadcast(&cond_parent);
            sleep(1);
        }
        else if (count < NUM && check == 0)
        {

            count++;
            sleep(1);
            pthread_mutex_lock(&mutex);
            pthread_cond_wait(&cond, &mutex);
            printf("\n [%d] 자식 쓰레드\n", *((int *)arg));
            pthread_mutex_unlock(&mutex);
        }
    }
}

void *server(void *arg)
{
    while (1)
    {
        sleep(1);
        if (status == 1)
        {

            pthread_mutex_lock(&mutex_parent);

            printf("\n 부모 쓰레드 - 요청받음\n");
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

    int id[NUM];

    status = pthread_create(&tid[0], NULL, server, (void *)&id[0]);

    for (int i = 1; i <= NUM; i++)
    {
        id[i] = i;
        status = pthread_create(&tid[i], NULL, client, (void *)&id[i]);
    }

    for (int i = 1; i <= NUM; i++)
    {
        pthread_join(tid[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex_parent);
    pthread_cond_destroy(&cond_parent);
}
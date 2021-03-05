#include <stdio.h>
#include <string.h>
#include <pthread.h>

int check_prime(int n)
{
    int c;
    for (c = 2; c <= n - 1; c++)
    {
        if (n % c == 0)
            return 0;
    }

    return 1;
}

void *get_primes(void *p)
{
    int i;
    for (i = 1; i < *(int *)p; i++)
    {
        if (check_prime(i))
            printf("%d\n", i);
    }

    pthread_exit(NULL);
}

int main(void)
{
    pthread_t id;

    int number;
    scanf("%d", &number);

    pthread_create(&id, NULL, get_primes, &number);

    printf("The thread was created\n");

    pthread_join(id, NULL);

    printf("The thread ended\n");

    return 0;
}

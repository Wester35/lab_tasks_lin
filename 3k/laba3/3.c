#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

typedef struct {
    int* array;
    int start;
    int end;
    int* result;
    sem_t* semaphore;
} ThreadData;

void* sum_negative_numbers(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int local_sum = 0;

    for (int i = data->start; i < data->end; i++) {
        if (data->array[i] < 0) {
            local_sum += data->array[i];
        }
    }

    sem_wait(data->semaphore);
    *data->result += local_sum;
    sem_post(data->semaphore);

    return NULL;
}

int main() {
    int size, num_threads;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    int* array = malloc(size * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 200 - 100;
    }

    printf("Сгенерированный массив:\n");
    for (int i = 0; i < size; i++) {
        printf("%5d ", array[i]);
    }
   
    
    printf("\nВведите количество потоков: ");
    scanf("%d", &num_threads);
    clock_t start = clock();
    pthread_t threads[num_threads];
    ThreadData thread_data[num_threads];
    int chunk_size = size / num_threads;
    int neg_sum = 0;
    sem_t semaphore;
    sem_init(&semaphore, 0, 1);

    for (int i = 0; i < num_threads; i++) {
        thread_data[i] = (ThreadData){
            .array = array,
            .start = i * chunk_size,
            .end = (i == num_threads - 1) ? size : (i + 1) * chunk_size,
            .result = &neg_sum,
            .semaphore = &semaphore,
        };
        pthread_create(&threads[i], NULL, sum_negative_numbers, &thread_data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Сумма отрицательных чисел: %d\n", neg_sum);

    free(array);
    sem_destroy(&semaphore);
    clock_t end = clock();


    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n\nВремя выполнения программы: %.6f секунд\n", time_taken);
    return 0;
}

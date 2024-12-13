#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef struct {
    int* array;
    int start;
    int end;
    int* result;
    pthread_mutex_t* mutex;
    pthread_barrier_t* barrier;
} ThreadData;

void* sum_positive_numbers(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int local_sum = 0;

    for (int i = data->start; i < data->end; i++) {
        if (data->array[i] > 0) {
            local_sum += data->array[i];
        }
    }

    pthread_barrier_wait(data->barrier);

    pthread_mutex_lock(data->mutex);
    *data->result += local_sum;
    pthread_mutex_unlock(data->mutex);

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
    printf("\n");

    printf("Введите количество потоков: ");
    scanf("%d", &num_threads);
    clock_t start = clock();
    pthread_t threads[num_threads];
    ThreadData thread_data[num_threads];
    int chunk_size = size / num_threads;
    int pos_sum = 0;
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_barrier_t barrier;
    pthread_barrier_init(&barrier, NULL, num_threads);

    for (int i = 0; i < num_threads; i++) {
        thread_data[i] = (ThreadData){
            .array = array,
            .start = i * chunk_size,
            .end = (i == num_threads - 1) ? size : (i + 1) * chunk_size,
            .result = &pos_sum,
            .mutex = &mutex,
            .barrier = &barrier,
        };
        pthread_create(&threads[i], NULL, sum_positive_numbers, &thread_data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Сумма положительных чисел: %d\n", pos_sum);

    free(array);
    pthread_mutex_destroy(&mutex);
    pthread_barrier_destroy(&barrier);
    
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n\nВремя выполнения программы: %.6f секунд\n", time_taken);
    return 0;
}

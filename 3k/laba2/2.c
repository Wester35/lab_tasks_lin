#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define SIZE 100 


typedef struct {
    int* arr;
    int start_index;
    int end_index;
    int* max_value;
    int* min_value;
    pthread_mutex_t* mutex;
} ThreadArgs;


int global_max = -1;
int global_min = 101;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void* process_array_part(void* args) {
    ThreadArgs* data = (ThreadArgs*)args;
    int local_max = -1;
    int local_min = 101;

    for (int i = data->start_index; i < data->end_index; i++) {
        if (data->arr[i] > local_max) {
            local_max = data->arr[i];
        }
        if (data->arr[i] < local_min) {
            local_min = data->arr[i];
        }
    }

    pthread_mutex_lock(data->mutex);
    if (local_max > *data->max_value) {
        *data->max_value = local_max;
    }
    if (local_min < *data->min_value) {
        *data->min_value = local_min;
    }
    pthread_mutex_unlock(data->mutex);

    return NULL;
}


void replace_max_with_min(int* arr, int size, int max, int min) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == max) {
            arr[i] = min;
        }
    }
}

int main() {
    srand(time(NULL));

    clock_t start = clock();
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100 + 1;  
    }

 
    printf("Исходный массив:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

   

  
    int num_threads = 2;  
    pthread_t threads[num_threads];
    ThreadArgs thread_args[num_threads];
    int chunk_size = SIZE / num_threads;

    
    for (int i = 0; i < num_threads; i++) {
        thread_args[i].arr = arr;
        thread_args[i].start_index = i * chunk_size;
        thread_args[i].end_index = (i == num_threads - 1) ? SIZE : (i + 1) * chunk_size;
        thread_args[i].max_value = &global_max;
        thread_args[i].min_value = &global_min;
        thread_args[i].mutex = &mutex;
        pthread_create(&threads[i], NULL, process_array_part, &thread_args[i]);
    }

    
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    
    replace_max_with_min(arr, SIZE, global_max, global_min);

    
    clock_t end = clock();

    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;


    printf("Измененный массив:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Время выполнения программы: %.6f секунд\n", time_taken);

    return 0;
}

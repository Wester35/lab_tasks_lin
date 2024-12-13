#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

#define PID_FILE "/var/run/mydemond.pid"

volatile sig_atomic_t paused = 0;

void handle_signal(int sig) {
    switch (sig) {
        case SIGTERM:
            printf("Демон завершает работу\n");
            remove(PID_FILE);
            exit(0);
        case SIGUSR1:
            printf("Демон приостановлен\n");
            paused = 1;
            break;
        case SIGUSR2:
            printf("Демон возобновляет работу\n");
            paused = 0;
            break;
    }
}

void run_daemon() {
    while (1) {
        if (!paused) {
            printf("Демон работает...\n");
            sleep(5);
        } else {

            sleep(1);
        }
    }
}

int main() {
    pid_t pid, sid;


    FILE *pid_file = fopen(PID_FILE, "r");
    if (pid_file) {
        pid_t existing_pid;
        if (fscanf(pid_file, "%d", &existing_pid) == 1 && kill(existing_pid, 0) == 0) {
            fprintf(stderr, "Демон уже запущен с PID %d\n", existing_pid);
            fclose(pid_file);
            return EXIT_FAILURE;
        }
        fclose(pid_file);
    }


    pid = fork();
    if (pid < 0) {
        perror("Ошибка создания процесса");
        return EXIT_FAILURE;
    }
    if (pid > 0) {

        return EXIT_SUCCESS;
    }


    umask(0);
    sid = setsid();
    if (sid < 0) {
        perror("Ошибка создания сеанса");
        return EXIT_FAILURE;
    }

    
    if (chdir("/") < 0) {
        perror("Ошибка перехода в корневой каталог");
        return EXIT_FAILURE;
    }


    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);


    pid_file = fopen(PID_FILE, "w");
    if (!pid_file) {
        perror("Ошибка записи PID файла");
        return EXIT_FAILURE;
    }
    fprintf(pid_file, "%d\n", getpid());
    fclose(pid_file);
    printf("Демон запущен с PID: %d\n", getpid());  


    signal(SIGTERM, handle_signal);
    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);

    
    run_daemon();

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

#define PID_FILE "/var/run/mydemond.pid" 

pid_t get_daemon_pid() {
    FILE *pid_file = fopen(PID_FILE, "r");
    if (!pid_file) {
        return -1;
    }

    pid_t pid;
    if (fscanf(pid_file, "%d", &pid) != 1) {
        fclose(pid_file);
        return -1;
    }

    fclose(pid_file);
    return pid;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Использование: %s <start|status|stop|sleep|awake>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pid_t pid = get_daemon_pid();

    if (strcmp(argv[1], "start") == 0) {
        if (pid > 0 && kill(pid, 0) == 0) {
            printf("Демон уже запущен с PID %d\n", pid);
        } else {
            pid_t daemon_pid = fork();
            if (daemon_pid == 0) {
                execlp("./mydemond", "./mydemond", NULL);
            } else if (daemon_pid < 0) {
                perror("Ошибка запуска демона");
                return EXIT_FAILURE;
            }
            printf("Демон запущен с PID %d\n", daemon_pid);
        }
    } else if (strcmp(argv[1], "status") == 0) {
        if (pid > 0 && kill(pid, 0) == 0) {
            printf("Демон запущен с PID %d\n", pid);
        } else {
            printf("Демон не запущен\n");
        }
    } else if (strcmp(argv[1], "stop") == 0) {
        if (pid > 0 && kill(pid, SIGTERM) == 0) {
            printf("Демон остановлен\n");
        } else {
            printf("Демон не запущен\n");
        }
    } else if (strcmp(argv[1], "sleep") == 0) {
        if (pid > 0 && kill(pid, SIGUSR1) == 0) {
            printf("Демон приостановлен\n");
        } else {
            printf("Демон не запущен\n");
        }
    } else if (strcmp(argv[1], "awake") == 0) {
        if (pid > 0 && kill(pid, SIGUSR2) == 0) {
            printf("Демон возобновил работу\n");
        } else {
            printf("Демон не запущен\n");
        }
    } else {
        fprintf(stderr, "Неизвестная команда: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

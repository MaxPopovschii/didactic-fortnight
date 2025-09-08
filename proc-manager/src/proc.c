#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "proc.h"

void list_processes() {
    printf("PID\tUSER\tCOMMAND\n");
    system("ps -eo pid,user,comm --sort=-%mem | head -20");
}

void search_process(const char *name) {
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "ps -eo pid,user,comm | grep %s", name);
    system(cmd);
}

int kill_process(int pid) {
    if (kill(pid, SIGTERM) == 0) {
        printf("Process %d terminated.\n", pid);
        return 0;
    } else {
        perror("kill");
        return -1;
    }
}
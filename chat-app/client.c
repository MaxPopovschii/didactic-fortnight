#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 9001
#define BUF_SIZE 1024

void *recv_handler(void *arg) {
    int sock = *(int*)arg;
    char buf[BUF_SIZE];
    int n;
    while ((n = recv(sock, buf, BUF_SIZE - 1, 0)) > 0) {
        buf[n] = '\0';
        printf("%s", buf);
        fflush(stdout);
    }
    return NULL;
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buf[BUF_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Connected to chat server. Type messages and press Enter.\n");

    char nickname[32];
    printf("Enter your nickname: ");
    fgets(nickname, sizeof(nickname), stdin);
    nickname[strcspn(nickname, "\n")] = 0; // rimuovi newline

    // Invia il nickname al server subito dopo la connessione
    send(sock, nickname, strlen(nickname), 0);

    pthread_t tid;
    pthread_create(&tid, NULL, recv_handler, &sock);

    while (fgets(buf, BUF_SIZE, stdin)) {
        send(sock, buf, strlen(buf), 0);
    }

    close(sock);
    return 0;
}
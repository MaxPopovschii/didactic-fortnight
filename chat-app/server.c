#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 9001
#define MAX_CLIENTS 10
#define BUF_SIZE 1024

int clients[MAX_CLIENTS];
char nicknames[MAX_CLIENTS][32];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void broadcast(char *msg, int sender) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (clients[i] != 0 && clients[i] != sender) {
            send(clients[i], msg, strlen(msg), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void *handle_client(void *arg) {
    int sock = *(int*)arg;
    char buf[BUF_SIZE];
    int n;

    // Ricevi nickname
    n = recv(sock, buf, sizeof(nicknames[0]) - 1, 0);
    if (n <= 0) { close(sock); return NULL; }
    buf[n] = 0;

    // Find the index of this client
    int idx = -1;
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (clients[i] == sock) {
            idx = i;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);

    if (idx != -1) {
        strncpy(nicknames[idx], buf, sizeof(nicknames[0]));
        nicknames[idx][sizeof(nicknames[0]) - 1] = '\0'; // Ensure null-termination
    }

    char joinmsg[64];
    snprintf(joinmsg, sizeof(joinmsg), "%s has joined the chat.\n", nicknames[idx]);
    broadcast(joinmsg, 0);

    while ((n = recv(sock, buf, BUF_SIZE - 1, 0)) > 0) {
        buf[n] = '\0';

        // Gestione comandi speciali
        if (strcmp(buf, "/quit\n") == 0) break;

        if (strncmp(buf, "/who", 4) == 0) {
            char userlist[512] = "Connected users:\n";
            pthread_mutex_lock(&clients_mutex);
            for (int i = 0; i < MAX_CLIENTS; ++i) {
                if (clients[i] != 0) {
                    strcat(userlist, nicknames[i]);
                    strcat(userlist, "\n");
                }
            }
            pthread_mutex_unlock(&clients_mutex);
            send(sock, userlist, strlen(userlist), 0);
            continue;
        }
        if (strncmp(buf, "/help", 5) == 0) {
            char *helpmsg = "Commands:\n/who - list users\n/msg <nick> <text> - private message\n/quit - exit\n/help - this help\n";
            send(sock, helpmsg, strlen(helpmsg), 0);
            continue;
        }
        if (strncmp(buf, "/msg ", 5) == 0) {
            // /msg <nick> <text>
            char *space = strchr(buf + 5, ' ');
            if (space) {
                *space = 0;
                char *target_nick = buf + 5;
                char *msg_text = space + 1;
                int found = 0;
                pthread_mutex_lock(&clients_mutex);
                for (int i = 0; i < MAX_CLIENTS; ++i) {
                    if (clients[i] != 0 && strcmp(nicknames[i], target_nick) == 0) {
                        char privmsg[BUF_SIZE + 64];
                        snprintf(privmsg, sizeof(privmsg), "[PM from %s]: %s\n", nicknames[idx], msg_text);
                        send(clients[i], privmsg, strlen(privmsg), 0);
                        found = 1;
                        break;
                    }
                }
                pthread_mutex_unlock(&clients_mutex);
                if (!found) {
                    char err[] = "User not found.\n";
                    send(sock, err, strlen(err), 0);
                }
            } else {
                char err[] = "Usage: /msg <nick> <text>\n";
                send(sock, err, strlen(err), 0);
            }
            continue;
        }

        // Messaggio pubblico
        char msg[BUF_SIZE + 32];
        snprintf(msg, sizeof(msg), "%s: %s", nicknames[idx], buf);
        broadcast(msg, sock);
    }

    // Notify others that this client has left
    snprintf(joinmsg, sizeof(joinmsg), "%s has left the chat.\n", nicknames[idx]);
    broadcast(joinmsg, 0);

    // Remove client
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (clients[i] == sock) {
            clients[i] = 0;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    close(sock);
    return NULL;
}

int main() {
    int server_fd, new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        new_sock = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
        if (new_sock < 0) {
            perror("accept");
            continue;
        }

        pthread_mutex_lock(&clients_mutex);
        int added = 0;
        for (int i = 0; i < MAX_CLIENTS; ++i) {
            if (clients[i] == 0) {
                clients[i] = new_sock;
                added = 1;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        if (!added) {
            char *msg = "Server full\n";
            send(new_sock, msg, strlen(msg), 0);
            close(new_sock);
        } else {
            pthread_t tid;
            pthread_create(&tid, NULL, handle_client, &new_sock);
            pthread_detach(tid);
        }
    }
    return 0;
}
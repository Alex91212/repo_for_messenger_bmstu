//
// Created by alex on 17.03.25.
//

#include "errorproc.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> // он нужен для поддерижки констант типа AF_INET
#include <sys/socket.h> // тут уже определена функция socket
#include <sys/socket.h>
#include <unistd.h> // это для функции read
#include <arpa/inet.h>

int Socket(int domain, int type, int protocol) {
    int res = socket(domain, type, protocol);
    if (res == -1) {
        perror("socket failed"); // вывод в стандартный поток ошибок, по сути ничем не отличатеся от обычного вывода
        exit(EXIT_FAILURE); // Функция exit(), находящаяся в стандартной библиотеке, вызывает немедленное окончание работы программы.
    }
    return res;
}

void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) { // это мы делаем как бы репер для этой функции, чтобы отлавливать ошибки с ней связанные, насколько я понял
    int res = bind(sockfd, addr, addrlen);
    if (res == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
}

void Listen(int sockfd, int backlog) { // это мы как бы опять пишем обертку
    int res = listen(sockfd, backlog);
    if (res == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen) { // опять мы пишем обертку, чтобы каждый раз не писать проверку на ошбику
    int res = accept(sockfd, addr, addrlen);
    if (res == -1) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    return res;
}

void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    int res = connect(sockfd, addr, addrlen);
    if (res == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }
}

void Inet_pton(int af, const char *src, void *dst) {
    int res = inet_pton(af, src, dst);
    if (res == 0) {
        printf("inet_pton failed: inet_pton failed: src does not contain"
                " a character string representing a valid network addres in the"
                " specified address family.\n ");
        exit(EXIT_FAILURE);
    }
    if (res == -1) {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }
}
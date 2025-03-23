//
// Created by alex on 17.03.25.
//


// ВОТ В ЭТОМ ФАЙЛЕ МЫ БУДЕМ ЗРАНИТЬ ОБЕРТКИ ДЛЯ НАШИХ ФУНКЦИЙ

#ifndef ERRORPROC_H
#define ERRORPROC_H // это чтобы дважды include не сработал


#include <sys/types.h>
#include<sys/socket.h>

int Socket(int domain, int type, int protocol);

void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen); // это мы делаем как бы репер для этой функции, чтобы отлавливать ошибки с ней связанные, насколько я понял


void Listen(int sockfd, int backlog); // это мы как бы опять пишем обертку


int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen); // опять мы пишем обертку, чтобы каждый раз не писать проверку на ошбику

void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

void Inet_pton(int af, const char *src, void *dst);

#endif //ERRORPROC_H

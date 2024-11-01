#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h> // inet_addr()
#define SA struct sockaddr

// we will be creating a single socket connection
// int sockfd;

int connect()
{
    // declare variables
    int status, sockfd;
    struct sockaddr_in serv_addr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("socket creation error");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(30391);
    serv_addr.sin_addr.s_addr = inet_addr('139.59.56.107');

    status = connect(sockfd, (SA *)&serv_addr, sizeof(serv_addr));

    if (status != 0)
    {
        printf("error while connecting to server");
    }else{
        printf("connected to smtp server successfully");
    }
}

int read()
{
    printf("I am reading now");
    return 0;
}
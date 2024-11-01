#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h> // inet_addr()
#include <strings.h>   // bzero()
#include <string.h>
#include <unistd.h> // read(), write(), close()

#define SA struct sockaddr

#include "smpp.h"

int main()
{
    // declare variables
    int status, sockfd;
    struct sockaddr_in serv_addr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("socket creation error");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(30391);
    serv_addr.sin_addr.s_addr = inet_addr("139.59.56.107");

    status = connect(sockfd, (SA *)&serv_addr, sizeof(serv_addr));

    if (status != 0)
    {
        printf("error while connecting to server");
        exit(0);
    }
    else
    {
        printf("connected to smpp server successfully");
    }

    bind_req bind_req;

    bind_req.command_length = htonl(100);
    bind_req.command_id = htonl(9);
    bind_req.command_status = htonl(0);
    bind_req.seq_number = htonl(1);

    char *system_id = "kitun396";
    char *password = "1rea4pok";
    char *system_type = "smpp";

    char *service_type = "CMT";
    char *source_address = "TIARACONECT";
    char *dest_address = "254723624727";

    // bind_req.system_id = malloc(strlen(system_id) + 1);
    strcpy(bind_req.system_id, system_id);

    // bind_req.password = malloc(strlen(password) + 1);
    strcpy(bind_req.password, password);

    // bind_req.system_type = malloc(strlen(system_type) + 1);
    strcpy(bind_req.system_type, system_type);

    bind_req.interface_version = 52;

    bind_req.addr_ton = htonl(0);
    bind_req.addr_npi = htonl(0);
    bind_req.address_range = htonl(0);

    int size = 21 + strlen(system_id) + strlen(password) + strlen(system_type) + 3;
    bind_req.command_length = htonl(size);

    // create bind_trx request
    write(sockfd, &bind_req, sizeof(bind_req));


    sleep(5);
    // submit sm

    submit_sm_req submit_sm_req;
    submit_sm_req.command_id = htonl(4);
    submit_sm_req.command_status = htonl(0);
    submit_sm_req.seq_number = htonl(2);

    strcpy(submit_sm_req.service_id, service_type);

    submit_sm_req.source_addr_ton = 1;
    submit_sm_req.source_addr_npi = htonl(0);

    strcpy(submit_sm_req.source_addr, source_address);

    submit_sm_req.dest_addr_ton = 1;
    submit_sm_req.dest_addr_npi = htonl(0);

    strcpy(submit_sm_req.destination_addr, dest_address);

    submit_sm_req.esm_class = htonl(0);
    submit_sm_req.protocol_id = htonl(0);
    submit_sm_req.priority_flag = 1;
    submit_sm_req.schedule_delivery_time = htonl(0);
    submit_sm_req.validity_period = htonl(0);
    submit_sm_req.registered_delivery = htonl(0);
    submit_sm_req.replace_if_present_flag = htonl(0);
    submit_sm_req.data_coding = 0x11;
    submit_sm_req.sm_default_msg_id = htonl(0);

    char * message = "hello there, this is a text from my custom smpp client built in C";
    int message_length = strlen(message);
    submit_sm_req.sm_length = message_length;

    strcpy(submit_sm_req.short_message, message);

    submit_sm_req.command_length = htonl(128);

    write(sockfd, &submit_sm_req, sizeof(submit_sm_req));

    while (1)
    {
        // printf("waiting for smpp operations\n");
    }
}
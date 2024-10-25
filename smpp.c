#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "smpp.h"

/*
input = bind_type, system_id, password
*/
int bind(char *system_id, char *password, char *system_type, char * esme_address)
{
    bind_req req;

    // infer from
    req.command_id = 0;
    req.command_status = 0;
    req.seq_number = 0;

    strcpy(req.system_id, system_id);
    strcpy(req.password, password);
    strcpy(req.system_type, system_type);
    req.interface_version = 0;
    req.addr_ton = 0;
    req.addr_npi = 0;
    strcpy(req.address_range, esme_address);

    req.command_length = sizeof(req);

    int size_of_password = sizeof(req.password) / sizeof(req.password[0]);

    printf("password size = %d", size_of_password);

    
    printf("size of req = %d", req.command_length);

    unsigned char *buffer = (char *)malloc(sizeof(req));
    memcpy(buffer, (const unsigned char *)&req, sizeof(req));
}

int main()
{

    char *password = "password";
    char *system_id = "system";
    char *system_type = "smpp";
    char *esme_addr = "127.0.0.1";
    bind(system_id, password, system_type, esme_addr);
    return 0;
}
#ifndef SMPP_H
#define SMPP_H

// constants
#define LIMIT 0

// struct definitions
typedef struct bind_req
{
    int command_length;
    int command_id;
    int command_status;
    int seq_number;
    // char system_id[16];
    // char password[9];
    // char system_type[13];
    char system_id[9];
    char password[9];
    char system_type[5];
    char interface_version;
    char addr_ton;
    char addr_npi;
    // char address_range[41];
    char address_range;
} bind_req;

typedef struct bind_resp
{
    int command_length;
    int command_id;
    int command_status;
    int seq_number;
    char system_id[16];
    char password[9];
} bind_resp;

typedef struct unbind_req
{
    int command_length;
    int command_id;
    int command_status;
    int seq_number;
} unbind_req;

typedef struct unbind_resp
{
    int command_length;
    int command_id;
    int command_status;
    int seq_number;
} unbind_resp;

typedef struct enquire_link_req
{
    int command_length;
    int command_id;
    int command_status;
    int seq_number;
} enquire_link_req;

typedef struct enquire_link_resp
{
    int command_length;
    int command_id;
    int command_status;
    int seq_number;
} enquire_link_resp;

typedef struct submit_sm_req
{
    int command_length;
    int command_id;
    int command_status;
    int seq_number;
    // char service_id[6];
    char service_id[4];
    char source_addr_ton;
    char source_addr_npi;
    // char source_addr[21];
    char source_addr[12];
    char dest_addr_ton;
    char dest_addr_npi;
    // char destination_addr[21];
    char destination_addr[13];
    char esm_class;
    char protocol_id;
    char priority_flag;
    // char schedule_delivery_time[17];
    char schedule_delivery_time;
    // char validity_period[17];
    char validity_period;
    char registered_delivery;
    char replace_if_present_flag;
    char data_coding;
    char sm_default_msg_id;
    char sm_length;
    // char short_message[255];
    char short_message[66];
} submit_sm_req;

typedef struct submit_sm_resp
{
    int command_length;
    int command_id;
    int command_status;
    int seq_number;
    char message_id[65];   
} submit_sm_resp;

// function definitions
int bind();
int unbind();
int submit_sm();
int handle_submit_sm_resp();

#endif
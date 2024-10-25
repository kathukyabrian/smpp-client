# Send an SMS
- to send an SMS the following will happen
    - our program will create a tcp connection with the smpp server(Tiara Connect in this case)
    - after a tcp connection is created, we will initiate a bind_trx - so that we are able to receive and transmit SMPP PDUs
    - if the bind_trx is successful we will proceed to initiate a submit_sm PDU, we will wait for submit_sm_resp PDU after which we will terminate
    - later on,  a deliver_sm from the MC(Tiara Connect) could come 
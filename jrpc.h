#ifndef _JRPC_H_
#define _JRPC_H_

#include <stdlib.h>
#include <sys/socket.h>
#include <stdint.h>
#include <string.h>
#include <json/json.h>

struct jrpc_proxy
{
    struct sockaddr_storage remote;
    int sockfd;
    int next_id;
};

struct jrpc_proxy *proxy_init(char *host, uint16_t port);
int proxy_close(struct jrpc_proxy *proxy);
struct json_object *proxy_call(struct jrpc_proxy *proxy, const char *method_name, json_object* parameters);

#endif //_JRPC_H_
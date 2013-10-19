#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "socket.h"

int socket_ip6optionskill(int s)
{
  return setsockopt(s,IPPROTO_IPV6, 1 , (char *) 0,0); 
}

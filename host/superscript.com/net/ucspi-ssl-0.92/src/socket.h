#ifndef SOCKET_H
#define SOCKET_H

#include "uint16.h"
#include "uint32.h"

extern int socket_tcp(void);
extern int socket_udp(void);
extern int socket_tcp6(void);
extern int socket_udp6(void);

extern int socket_connect4(int,const char *,uint16);
extern int socket_connect6(int s,const char *ip,uint16 port,uint32 scope_id);
extern int socket_connected(int);
extern int socket_bind4(int,char *,uint16);
extern int socket_bind4_reuse(int,char *,uint16);
extern int socket_bind6(int s,const char *ip,uint16 port,uint32 scope_id);
extern int socket_bind6_reuse(int s,const char *,uint16 port,uint32 scope_id);
extern int socket_listen(int,int);
extern int socket_accept4(int,char *,uint16 *);
extern int socket_accept6(int s,char *ip,uint16 *port,uint32 *scope_id);
extern int socket_recv4(int,char *,int,char *,uint16 *);
extern int socket_send4(int,const char *,int,const char *,uint16);
extern int socket_recv6(int s,char *buf,unsigned int len,char *ip,uint16 *port,uint32 *scope_id);
extern int socket_send6(int s,const char *buf,unsigned int len,const char *ip,uint16 port,uint32 scope_id);
extern int socket_local4(int,char *,uint16 *);
extern int socket_remote4(int,char *,uint16 *);
extern int socket_local6(int s,char *ip,uint16 *port,uint32 *scope_id);
extern int socket_remote6(int s,char *ip,uint16 *port,uint32 *scope_id);
extern int socket_tcpnodelay(int);
extern int socket_ipoptionskill(int);
extern int socket_ip6optionskill(int);

/* enable sending udp packets to the broadcast address */
extern int socket_broadcast(int);
/* join a multicast group on the given interface */
extern int socket_mcjoin4(int,char *,char *);
extern int socket_mcjoin6(int,char *,int);
/* leave a multicast group on the given interface */
extern int socket_mcleave4(int,char *);
extern int socket_mcleave6(int,char *);
/* set multicast TTL/hop count for outgoing packets */
extern int socket_mcttl4(int,char);
extern int socket_mcttl6(int,char);
/* enable multicast loopback */
extern int socket_mcloop4(int,char);
extern int socket_mcloop6(int,char);

extern const char* socket_getifname(uint32 interface);
extern uint32 socket_getifidx(const char *ifname);

extern void socket_tryreservein(int,int);

extern int ipv4;
#endif

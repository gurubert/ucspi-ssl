#ifndef IP6_H
#define IP6_H

#include "byte.h"
#include "stralloc.h"

extern unsigned int ip6_scan(const char *src,char *ip);
extern unsigned int ip6_compactaddr(char *s, char ip[16]);
extern unsigned int ip6_expandaddr(char *src, stralloc *dest);
extern int ip6tobitstring(char *, stralloc *, unsigned int);
/*
 ip6 address syntax: (h = hex digit), no leading '0' required
   1. hhhh:hhhh:hhhh:hhhh:hhhh:hhhh:hhhh:hhhh
   2. any number of 0000 may be abbreviated as "::", but only once
 flat ip6 address syntax:
   hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
*/

#define IP6_FMT 40

extern const unsigned char V4mappedprefix[12]; /*={0,0,0,0,0,0,0,0,0,0,0xff,0xff}; */
extern const unsigned char V6loopback[16]; /*={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}; */
extern const unsigned char V6any[16]; /*={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; */

#define ip6_isv4mapped(ip) (byte_equal(ip,12,V4mappedprefix))

#define V4MAPPREFIX "::ffff:"

#endif

#ifndef REMOTEINFO_H
#define REMOTEINFO_H

#include "stralloc.h"
#include "uint16.h"

extern int remoteinfo(stralloc *,char *,uint16,char *,uint16,unsigned int);
extern int remoteinfo6(stralloc *,char *,uint16,char *,uint16,unsigned int,uint32);

#endif

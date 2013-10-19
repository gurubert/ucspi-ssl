/* Public domain. */

#define _BSD_SOURCE

#include <grp.h>
#include <sys/types.h>
#include <sys/param.h>
#include <unistd.h>
#include "prot.h"

int prot_gid(int gid)
{
  gid_t x[2];
  x[0] = gid; x[1] = 73; /* catch errors */
  if (setgroups(1,x) == -1) return -1;
  return setgid(gid); /* _should_ be redundant, but on some systems it isn't */
}

int prot_uid(int uid)
{
  return setuid(uid);
}

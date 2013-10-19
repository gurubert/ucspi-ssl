#include "fmt.h"
#include "hexconversion.h"

unsigned int fmt_xlong(register char *s,register unsigned long u)
{
  register unsigned int len; register unsigned long q;
  len = 1; q = u;
  while (q > 15) { ++len; q /= 16; }
  if (s) {
    s += len;
    do { *--s = tohex(u % 16); u /= 16; } while(u); /* handles u == 0 */
  }
  return len;
}

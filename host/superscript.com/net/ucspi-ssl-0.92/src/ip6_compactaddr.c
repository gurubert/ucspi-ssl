#include "fmt.h"
#include "byte.h"
#include "ip4.h"
#include "ip6.h"
#include "hexconversion.h"

/**
 * This function convert a IPv6 address as 16 bytes char array into a compactificated string.
 * @author 	Felix von Leitner
 * @param s 	Destination address.
 * @param ip 	Source address as 16 bytes char array.
 * @return 0: failure, else: the number of characters of the return value.
 */

unsigned int ip6_compactaddr(char *s,char ip[16])
{
  unsigned long len,temp, k, pos0 = 0,len0 = 0, pos1 = 0, compr = 0;
//  const unsigned char V4mappedprefix[12] = {0,0,0,0,0,0,0,0,0,0,0xff,0xff};

  for (k=0; k<16; k+=2) {
    if (ip[k] == 0 && ip[k+1] == 0) {
      if (!compr) {
        compr=1;
        pos1=k;
      }
      if (k == 14) { k = 16; goto last; }
    } else if (compr) {
    last:
      if ((temp=k-pos1) > len0) {
        len0 = temp;
        pos0 = pos1;
      }
      compr=0;
    }
  }

  for (len=0,k=0; k<16; k+=2) {
    if (k == 12 && (byte_equal(ip,12,V4mappedprefix))) {
      len += ip4_fmt(s,ip+12);
      break;
    }
    if (pos0 == k && len0) {
      if (k == 0) { ++len; if (s) *s++ = ':'; }
      ++len; if (s) *s++ = ':';
      k += len0-2;
      continue;
    }
    temp = ((unsigned long) (unsigned char) ip[k] << 8) +
            (unsigned long) (unsigned char) ip[k+1];
    temp = fmt_xlong(s,temp); len += temp; if (s) s += temp;
    if (k<14) { ++len; if (s) *s++ = ':'; }
  }

  return len;
}

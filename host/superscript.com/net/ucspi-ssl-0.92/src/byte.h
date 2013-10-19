/* Public domain. */

#ifndef BYTE_H
#define BYTE_H

extern unsigned int byte_chr(const char *, unsigned int n, int);
extern unsigned int byte_rchr();
extern void byte_copy(char *, unsigned int, const char *);
extern void byte_copyr(char *, unsigned int, const char *);
extern int byte_diff(const char *, unsigned int n, const char *);
extern void byte_zero(char *, unsigned int);

#define byte_equal(s,n,t) (!byte_diff((s),(n),(t)))

#endif

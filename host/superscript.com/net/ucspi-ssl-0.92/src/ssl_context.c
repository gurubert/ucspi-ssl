#include "ucspissl.h"

SSL_CTX *ssl_context(const SSL_METHOD *m)
{
  SSL_CTX *ctx;

  SSL_library_init();
  ctx = SSL_CTX_new(m);
  SSL_CTX_set_options(ctx,SSL_OP_SINGLE_DH_USE);
  return ctx;
}


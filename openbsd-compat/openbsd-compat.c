#include <strings.h>

__attribute__((weak)) void __explicit_bzero_hook(void *buf, size_t len) {}

void explicit_bzero(void *buf, size_t len)
{
    bzero(buf, len);
    __explicit_bzero_hook(buf, len);
}


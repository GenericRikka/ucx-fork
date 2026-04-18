/*
 * Stub implementations of ucm_override_brk() / ucm_override_sbrk() for
 * builds where brk()/sbrk() are not available (HAVE_BRK_SBRK not set).
 *
 * Marked __attribute__((weak)) so a real implementation can override them
 * if the platform later gains brk/sbrk support.
 */

#include <errno.h>
#include <stdint.h>
#include <unistd.h>

__attribute__((weak))
int ucm_override_brk(void *addr)
{
    (void)addr;
    errno = ENOSYS;
    return -1;
}

__attribute__((weak))
void *ucm_override_sbrk(intptr_t increment)
{
    (void)increment;
    errno = ENOSYS;
    return (void*)-1;
}

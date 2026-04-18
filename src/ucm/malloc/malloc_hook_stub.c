/*
 * Stub for UCX malloc hook support on platforms where the glibc/ptmalloc
 * hooking mechanism is not available.
 *
 * Provides the public API declared in malloc_hook.h without attempting to
 * install hooks, relocate symbols, or tune allocator thresholds.
 * Returns UCS_ERR_UNSUPPORTED so callers can fall back gracefully.
 */

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include "malloc_hook.h"

#include <ucm/util/log.h>
#include <ucs/sys/compiler.h>

ucs_status_t ucm_malloc_install(int events)
{
    static int warned = 0;

    if (!warned) {
        ucm_debug("ucm_malloc_install(events=0x%x): stub (malloc hooks not supported on this build)",
                  events);
        warned = 1;
    }

    return (events == 0) ? UCS_OK : UCS_ERR_UNSUPPORTED;
}

void ucm_init_malloc_hook(void)
{
}

void ucm_malloc_state_reset(int default_mmap_thresh, int default_trim_thresh)
{
    (void)default_mmap_thresh;
    (void)default_trim_thresh;
}

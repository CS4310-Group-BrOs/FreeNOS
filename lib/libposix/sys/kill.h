#ifndef __LIBPOSIX_KILL_H
#define __LIBPOSIX_KILL_H

#include <Macros.h>
#include "types.h"

/**
 * @brief 
 * 
 * @param pid Process ID of child to send signal to.
 * @param stat_loc Points to an integer for storing the exit status.
 * @param options Optional flags.
 * @return C 
 */
extern C pid_t killpid(pid_t pid, int *stat_loc, int options);

/**
 * @}
 * @}
 */

#endif /* __LIBPOSIX_KILL_H */
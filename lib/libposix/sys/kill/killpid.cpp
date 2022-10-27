#include <FreeNOS/User.h>
#include "sys/kill.h"
#include "sys/types.h"
#include <errno.h>

pid_t killpid(pid_t pid, int *stat_loc, int options)
{
    const ulong result = (ulong) ProcessCtl(pid, KillPID, priority);

    switch ((const API::Result) (result & 0xffff))
    {
        case API::NotFound:
            errno = ESRCH;
            return (pid_t) -1;

        case API::Success:
            if (stat_loc)
            {
                *stat_loc = result >> 16;
            }
            return pid;

        default:
            errno = EIO;
            return (pid_t) -1;
    }
}
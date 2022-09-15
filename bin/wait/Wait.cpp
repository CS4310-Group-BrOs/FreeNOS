#include <stdio.h>
#include <unistd.h>
#include "Wait.h"

Wait::Wait(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Suspend the execution of the calling thread until a child specified by pid argument has changed state");
    parser().registerPositional("PROCESS_ID", "Suspend execution until the given pid argument changes state");
}

Wait::~Wait()
{
}

Wait::Result Wait::exec()
{

}

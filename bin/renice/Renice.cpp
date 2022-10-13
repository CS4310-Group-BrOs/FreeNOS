#include "sys/renice.h"
#include <Macros.h>
#include <stdio.h>
#include <unistd.h>
#include "Renice.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ProcessClient.h>

Renice::Renice(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Alters the scheduling priority of a running process.");
    parser().registerPositional("PRIORITY", "change the scheduling priority to this level")
    parser().registerPositional("PROCESS_ID", "change the sceduling priority of this process");
    parser().registerFlag('n', "level", "changes current priority level to the specified")
}

Renice::~Renice()
{
}

Renice::Result Renice::exec()
{
    
}
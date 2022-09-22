#include <Types.h>
#include <Macros.h>
#include <stdio.h>
#include <unistd.h>
#include "Wait.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ProcessClient.h>

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
    const ProcessClient process;
    String out;
    ProcessID pid = (atoi(arguments().get("PROCESS_ID")));
    
    ProcessClient::Info info;
    const ProcessClient::Result result = process.processInfo(pid, info);
    
    if (result == ProcessClient::Success) {
        waitpid(pid);        
    }
    
    else {
        char line[28];
            snprintf(line, sizeof(line),
                    "No %3d process ID is found",
                     pid);
            out << line;
        
        write(1, *out, out.length());
        
    }
    
    // Done
    return Success;
        

}

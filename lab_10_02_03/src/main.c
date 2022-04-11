#include "defines.h"
#include "process.h"
#include <stdio.h>
#include <string.h>


int main(void)
{
    char command[COMMAND_MAX_LEN + 2];
    int rc;

    fgets(command, COMMAND_MAX_LEN + 2, stdin);
    if (command[COMMAND_MAX_LEN] != '\n')
        return COMMAND_ERROR;

    if (strcmp(command, "out\n") == 0)
    {
        rc = out();
    }
    else if (strcmp(command, "mul\n") == 0)
    {
        rc = mul();
    }
    else if (strcmp(command, "sqr\n") == 0)
    {
        rc = sqr();
    }
    else if (strcmp(command, "div\n") == 0)
    {
        rc = mydiv();
    }
    else
    {
        rc = COMMAND_ERROR;
    }

    return rc;
}
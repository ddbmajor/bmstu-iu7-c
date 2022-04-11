#include <stdio.h>
#include <string.h>
#include "defines.h"
#include "process.h"

// В файле записаны новостные сайты в формате:

// название
// тематика
// число пользователей в день

// Необходимо создать список самых популярных сайтов по одному из каждой категории по возрастанию
// Формат вызова: ./app.exe infile outfile


int main(int argc, char **argv)
{
    FILE *infile, *outfile;
    int rc = 0;
    if (argc != 3)
        rc = ARG_ERROR;
    else
    {
        infile = fopen(argv[1], "r");
        if (infile)
        {
            outfile = fopen(argv[2], "w");
            if (outfile)
            {
                rc = process(infile, outfile);
                
                fclose(infile);
                fclose(outfile);
            }
            else
            {
                rc = FILE_ERROR;
                fclose(infile);
            }
        }
        else
        {
            rc = FILE_ERROR;
        }
    }
    return rc;
}
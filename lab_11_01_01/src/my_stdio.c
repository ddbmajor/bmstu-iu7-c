#include "my_stdio.h"


static char digit(int num)
{
    switch (num)
    {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        case 10:
            return 'a';
        case 11:
            return 'b';
        case 12:
            return 'c';
        case 13:
            return 'd';
        case 14:
            return 'e';
        case 15:
            return 'f';
    }
    return '-';
}


int my_snprintf(char *s, size_t n, const char *format, ...)
{
    if (format == NULL)
        return -1;
    

    va_list vl;
    va_start(vl, format);
    
    int curr_len = 0;
    int return_len = 0;
    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == 's')
            {
                i++;
                char *str = va_arg(vl, char *);
                for (int j = 0; str[j] != '\0'; j++)
                {
                    if (return_len < (int)n - 1)
                    {
                        if (s)
                            s[curr_len] = str[j];
                        curr_len++;
                        return_len++;
                    }
                    else if (return_len == (int)n - 1)
                    {
                        if (s)
                            s[curr_len] = '\0';
                        return_len++;
                    }
                    else if (return_len > (int)n - 1)
                    {
                        return_len++;
                    }
                }
            }
            else if (format[i + 1] == 'l' && format[i + 2] == 'l' && format[i + 3] == 'x')
            {
                i += 3;
                long long unsigned int num = va_arg(vl, long long unsigned int);
                if (num == 0)
                {
                    if (return_len < (int)n - 1)
                    {
                        if (s)
                            s[curr_len] = '0';
                        curr_len++;
                        return_len++;
                    }
                    else if (return_len == (int)n - 1)
                    {
                        if (s)
                            s[curr_len] = '\0';
                        return_len++;
                    }
                    else if (return_len > (int)n - 1)
                    {
                        return_len++;
                    }
                }
                short int div = 0;
                char ret_num[17] = "\0";
                int j = 0;
                while (num > 0)
                {
                    div = num % 16;
                    ret_num[j++] = digit(div);
                    num /= 16;
                }
                ret_num[j] = '\0';
                j--;
                while (j != -1)
                {
                    if (return_len < (int)n - 1)
                    {
                        if (s)
                            s[curr_len] = ret_num[j];
                        curr_len++;
                        return_len++;
                    }
                    else if (return_len == (int)n - 1)
                    {
                        if (s)
                            s[curr_len] = '\0';
                        return_len++;
                    }
                    else if (return_len > (int)n - 1)
                    {
                        return_len++;
                    }         
                    j--;
                }
            }
        }
        else
        {
            if (return_len < (int)n - 1)
            {
                if (s)
                    s[curr_len] = format[i];
                curr_len++;
                return_len++;
            }
            else if (return_len == (int)n - 1)
            {
                if (s)
                    s[curr_len] = '\0';
                return_len++;
            }
            else if (return_len > (int)n - 1)
            {
                return_len++;
            }
        }
    }
    if (s)
        s[curr_len] = '\0';
    
    va_end(vl);
    return return_len;
}

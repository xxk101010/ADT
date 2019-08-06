
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stackar.h"


char test[]= "231*+9-";

int stack_postFix_process(char *str);


int main(int argc, char * argv[])
{
    printf("%d\n", stack_postFix_process(test));
}


int stack_postFix_process(char *str)
{
    int str_len;
    int i;
    int ret  = 0;
    int val1 = 0;
    int val2 = 0;
    Stack stack_tmp = NULL;

    stack_tmp = CreateStack(100);
    str_len   = strlen(str);

    for(i = 0; i < str_len;i++)
    {
        if(isdigit(str[i]))
        {
            Push(str[i] - '0', stack_tmp);
            continue;
        }

        val1 = Top(stack_tmp);
        Pop(stack_tmp);
        val2 = Top(stack_tmp);
        Pop(stack_tmp);
        if(str[i] == '+')
        {
            ret = val2 + val1;
            Push(ret, stack_tmp);
        }
        else if(str[i] == '-')
        {
            ret = val2 - val1;
            Push(ret, stack_tmp);    
        }
        else if(str[i] == '*')
        {
            ret = val2 * val1;
            Push(ret, stack_tmp);   
        }       
        else if(str[i] == '/')
        {
            ret = val2 / val1;
            Push(ret, stack_tmp);
        }
    }
    return Top(stack_tmp);
}




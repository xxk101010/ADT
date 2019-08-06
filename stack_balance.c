

#include <string.h>
#include <stdio.h>
#include "stackar.h"



char test_str[] = "([{}])";


int stack_postfix_pro(char *str);

int main(int argc, char *argv[])
{
    int ret = 0;

    ret = stack_postfix_pro(test_str);
    if(ret < 0)
    {
        printf("no\n");
    }
    else
    {
        printf("yes\n");
    }
    
}


int stack_postfix_pro(char *str)
{
    int  i;
    int  flag = 0;
    ElementType tmp;
    Stack test_stack = NULL;

    test_stack       = CreateStack(100);
    for(i = 0; i < strlen(str); i++)
    {

        if(str[i] == '[' || str[i] == '(' || str[i] == '{' )
        {
            Push( test_str[i], test_stack );
            continue;
        }

        if(IsEmpty(test_stack))
        {
            return -1;
        }
        else if(str[i] == ']')
        {
            tmp = Top(test_stack);
            if(tmp != '[')
            {
                return -1;
            }
            Pop(test_stack);
        }
        else if(str[i] == '}')
        {
            tmp = Top(test_stack);
            if(tmp != '{')
            {
                 return -1;
            }
            Pop(test_stack);
        }
        else if(str[i] == ')')
        {
            tmp = Top(test_stack);
            if(tmp != '(')
            {
                return -1;
            }
            Pop(test_stack);
        }
    }

    return flag;
}
















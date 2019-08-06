

#include <stdio.h>
#include <string.h>
#include "stackar.h"


int test_str[] = {1, 2, 8, 9, 7, 6 , 5 , 4}; 

Stack stack_sort(int *str, int str_len);



int main(int argc, char * argv [ ])
{      
   int i;
   Stack test_stack = NULL;
   test_stack = stack_sort(test_str, 8);

   while(!IsEmpty(test_stack))
   {
       printf("%d", Top(test_stack));
       Pop(test_stack);
   }
   printf("\n");
    
}


Stack stack_sort(int *str, int str_len)
{
    int  i;
    int  flag = 0;
    //int  str_len;
    ElementType tmp;
    Stack test_stack = NULL;
    Stack stack_tmp  = NULL;

    test_stack       = CreateStack(100);
    stack_tmp        = CreateStack(100);

    if(str_len > 100)
    {
        printf("too much\n");
        return NULL;
    }
    for(i = 0; i < str_len;i++)
    {
        Push(str[i], test_stack);  
    }

    while(!IsEmpty(test_stack))
    {
       tmp = Top(test_stack);
       Pop(test_stack);

       while(!IsEmpty(stack_tmp) && Top(stack_tmp) > tmp)
       {
           Push(Top(stack_tmp), test_stack);
           Pop(stack_tmp);
       }
       Push(tmp, stack_tmp);
    }
    return stack_tmp;
}





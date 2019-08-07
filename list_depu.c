
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List list_push(List list_in, ElementType data);


int main(int argc, char *argv[])
{
     
     List list_test;
     PtrToNode Ptr;
     PtrToNode Ptr1;
     PtrToNode tmp;

     list_test = MakeEmpty( NULL);
     Ptr       = list_test;    

     list_test = list_push(list_test, 0);
     list_test = list_push(list_test, 1);
     list_test = list_push(list_test, 2);
     list_test = list_push(list_test, 1);
     list_test = list_push(list_test, 3);

     Ptr = list_test;
     while(Ptr->Next != NULL)
     {
         printf("1 %d\n", Ptr->Element);
         Ptr       = Ptr->Next;
     }

     Ptr = list_test;
     while(Ptr != NULL && Ptr->Next != NULL)
     {
         Ptr1 = list_test;
         while(Ptr1 != NULL && Ptr1->Next != NULL)
         {
            if(Ptr1->Next->Element == Ptr->Element && Ptr1->Next != Ptr)
            {
                tmp = Ptr1->Next;
                Ptr1->Next = tmp->Next;
                free(tmp);
            }  
            Ptr1 = Ptr1->Next;
         }
         Ptr = Ptr->Next;
     }

     Ptr = list_test;
     while(Ptr->Next != NULL)
     {
         printf("2 %d\n", Ptr->Element);
         Ptr       = Ptr->Next;
     }
}



List list_push(List list_in, ElementType data)
{

    PtrToNode node_new = NULL;

    node_new = (PtrToNode)calloc(1, sizeof(struct Node));
    node_new->Element = data;
    node_new->Next    = list_in;

    return node_new;
}



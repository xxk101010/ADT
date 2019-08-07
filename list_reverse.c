#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List list_reverse(List list_in);
List list_push(List list_in, ElementType data);


int main(int argc, char *argv[])
{
     List list_test;
     PtrToNode Ptr;

     list_test = MakeEmpty( NULL);
     Ptr       = list_test;


     //list_test = list_reverse(list_test);

     //Insert( 1, list_test, list_test);
     //Insert( 2, list_test, list_test);
     //Insert( 3, list_test, list_test);

     list_test =  list_push(list_test, 1);
     list_test =  list_push(list_test, 2);
     list_test =  list_push(list_test, 3);

     Ptr = list_test;
     while(Ptr->Next != NULL)
     {
         printf("1 %d\n", Ptr->Element);
         Ptr       = Ptr->Next;
     }
     list_test = list_reverse(list_test);
     
     Ptr = list_test;
     while(Ptr->Next != NULL)
     {
         printf("2 %d\n", Ptr->Element);
         Ptr       = Ptr->Next;
     }
}


List list_reverse(List list_in)
{

    PtrToNode current = list_in;
    PtrToNode prev    = NULL;
    PtrToNode next    = NULL;
    PtrToNode head    = current;


    prev = (PtrToNode)calloc(1, sizeof(struct Node));
    prev->Element = 0;
    prev->Next    = NULL;
    while(current->Next != NULL)
    {
       next          = current->Next;
       current->Next = prev; 
       prev          = current;    
       current       = next;
    }
    return prev;
}


List list_push(List list_in, ElementType data)
{

    PtrToNode node_new = NULL;

    node_new = (PtrToNode)calloc(1, sizeof(struct Node));
    node_new->Element = data;
    node_new->Next    = list_in;

    return node_new;
}






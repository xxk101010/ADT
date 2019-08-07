


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


void kmax(SearchTree node, int k, int *c);


int main(int argc, char *argv[])
{
    SearchTree tree_ptr = NULL;
    int index;
    tree_ptr = MakeEmpty(NULL);

    
     tree_ptr = Insert( 0, tree_ptr);
    
     tree_ptr = Insert( 1, tree_ptr);
        
     tree_ptr = Insert( 2, tree_ptr);

     tree_ptr = Insert( 7, tree_ptr);

     tree_ptr = Insert( 5, tree_ptr);

     tree_ptr = Insert( 15, tree_ptr);

     kmax(tree_ptr, 2, &index);
}


void kdis(SearchTree node, int k)
{

    if(node == NULL || k == 0)
    {
        return;
    }

    kmax(node->Right, k, c);

    *c = *c + 1;

    if(*c == k)
    {
        printf("%d \n" ,node->Element);
        return;
    }

    kmax(node->Left, k, c);
}



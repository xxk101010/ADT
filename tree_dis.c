


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


void kdis(SearchTree node, int k);



int main(int argc, char *argv[])
{
    SearchTree tree_ptr = NULL;
    int index;
    tree_ptr = MakeEmpty(NULL);

    
     tree_ptr = Insert( 8, tree_ptr);
    
     tree_ptr = Insert( 10, tree_ptr);
        
     tree_ptr = Insert( 6, tree_ptr);

     tree_ptr = Insert( 7, tree_ptr);

     tree_ptr = Insert( 11, tree_ptr);

     tree_ptr = Insert( 4, tree_ptr);

     tree_ptr = Insert( 8, tree_ptr);
     
     tree_ptr = Insert( 2, tree_ptr);

     kdis(tree_ptr, 2);
}


void kdis(SearchTree node, int k)
{

    if(node == NULL)
    {
        return;
    }
    //printf("%d\n" , node->Element);
    if(k == 0)
    {
        printf("%d\n" , node->Element);
        return;
    }
    else
    {
         kdis(node->Left,  k - 1);
         kdis(node->Right, k - 1);
    }
}




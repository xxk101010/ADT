




#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


int tree_anc(SearchTree node, int k);




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

     tree_anc(tree_ptr, 11);
}


int tree_anc(SearchTree node, int k)
{

    if(node == NULL)
    {
        return  -1;
    }
    //printf("%d\n" , node->Element);
    if(node->Element == k)
    {
        printf("%d\n", node->Element);
        return 0;
    }

    if(!tree_anc(node->Left,k)||!tree_anc(node->Right,k))
    {
        printf("%d\n", node->Element);
        return 0;
    }

}




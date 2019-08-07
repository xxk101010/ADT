

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


int maxDepth(SearchTree node);


int main(int argc, char *argv[])
{
    SearchTree tree_ptr = NULL;

    tree_ptr = MakeEmpty(NULL);

    
     tree_ptr = Insert( 0, tree_ptr);
    
     tree_ptr = Insert( 1, tree_ptr);
        
     tree_ptr = Insert( 2, tree_ptr);

     tree_ptr = Insert( 7, tree_ptr);

     tree_ptr = Insert( 5, tree_ptr);

     printf("%d\n", maxDepth(tree_ptr));
}


int maxDepth(SearchTree node)
{
   if(node == NULL)    
   {
       return 0;
   }
   else
   {
       int l_val = 0;
       int r_val = 0;

       l_val = maxDepth(node->Left);
       r_val = maxDepth(node->Right);

       if(r_val > l_val)
       {
           return r_val + 1;
       }
       else
       {
          return l_val + 1;
       }
   }
}



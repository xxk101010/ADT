
#include <stdio.h>
#include <math.h>


void shell_sort(int *data, int N);

int test[5] = {3,4,2,1,5};

int main(int argc, char *argv[])
{
	  int i;
    printf("ni hao tian mao");       
    shell_sort(test, 5);
		for(i =0; i < 5;i++)
		{
		   printf(" %d", test[i]);
		}
		printf("\n");
}



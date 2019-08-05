
#include <stdio.h>
#include <math.h>




void shell_sort(int *data, int N)
{
   int inc,i,j;
	 int tmp;

	 for(inc = N/2; inc > 0;inc/=2)
	 {
       for(i =inc; i < N; i++)
			 {
				  tmp = data[i];
			    for(j = i; j >= inc; j = j - inc)
					{
					   if(data[j] < data[j - inc])
						 {
						     data[j] = data[j - inc]; 
						 }
						 else
						 {	
						     break;	
						 }
					}
					data[j] = tmp;
			 }
	 }
}



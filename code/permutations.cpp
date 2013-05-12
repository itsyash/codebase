#include <stdio.h>
#include <iostream>
#include <string.h>


using namespace  std;
/* Function to swap values at two pointers */
void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n) 
{
   printf("for a=%s, i=%d and n=%d\n",a,i,n);
   int j; 
   if (i == n){
	 cout<<"i==j\n";
     printf("%s\n", a);
   }
   else
   {
       for (j = i; j <= n; j++)
       {
		  cout<<"swapping "<<*(a+i)<<" and "<<*(a+j)<<endl;
          swap((a+i), (a+j));
          cout<<"calling permute with "<<i+1<<" and "<<n<<endl;
          permute(a, i+1, n);
          cout<<"returning from permute"<<", swapping again "<<*(a+i)<<" and "<<*(a+j)<<endl;
          swap((a+i), (a+j)); //backtrack
       }
   }
} 

/* Driver program to test above functions */
int main()
{
   char a[] = "ABC";  
   permute(a, 0, 2);
   //getchar();
   return 0;
}

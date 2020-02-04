int reza=2;
#include "ali.h"

int x(a,b)
{
    return a-b;
}

int main()
{
//
   // int b=7;
   // b=b+1;
   // int a = b;
    //return b/(4-3);
   //int a=18/x(2,-2);
   //int a=scan();
   //int a=scan();
   //print(a);
   /*for(int i=10;i>1;i=i-2)
   {
     print(i);
   }*/
   int n=scan();
   int ar[10];
   for(int i=1;i<=n;i++)
   {
     ar[i] = (x(fib(i),1));
     print(ar[i]);

   }
   print(99);
   while(n>=1)
   {
    print(ar[n--]);
   }
   
   
  
   
   //x();
   
   
   /*if(b<5)
    return 1;
   else
    return -1;
  */

}

#include<stdio.h>
int main()
{
   struct fun
   {
    unsigned int lo :8;
    unsigned int maga :16;

   }funnuu;
   funnuu.lo=0;
   funnuu.maga=3;
   printf("%d,%d\n",sizeof(funnuu.lo),sizeof(funnuu.maga));
   return 0;

}
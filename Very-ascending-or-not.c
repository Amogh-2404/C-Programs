#include<stdio.h>
int main()
{
    int sequencesize;
    int previousvalue=0 , currentvalue=0;//Assuming sequence of positive values.
    int veryacendingflag=1;//Intial assumptiion :- sequence is very ascending.

    printf("Insert size (total size of the seqence):\n");
    scanf("%d",&sequencesize);

    if(sequencesize<=0)
       printf("Wait a minute..Try again please!\n");
       else
       {
            do
            {
                printf("Insert Value: \n");
                scanf("%d",&currentvalue);

                if(currentvalue<0)
                printf("Number isn't positive\n");
                else
                {
                    if(currentvalue<=previousvalue)
                       veryacendingflag=0;
                       previousvalue=currentvalue;
                       sequencesize--;

                }
            } while (sequencesize>0);
            if(veryacendingflag==1)
            printf("This sequence is very acending!\n");
            else
              printf("This seqence is not very ascending!\n");

            
       }

 return 0;
}
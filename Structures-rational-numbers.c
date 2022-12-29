/*
***Exercise - Rational Numbers!***
* Design and develop a rational number struct, called Rational.
* A rational number consists of two parts :
* 1. numerator.
* 2. denominator
* For example: 1/3, 2/5, 7/3, ...
* Provide increment, decrement, addition, subtraction, multiplication,
* division, smaller, bigger, equal and not equal functions to make
* relational / mathematical operations on variables of a rational type.
*
write a "main function" to check out the coprectness of your functions
* Print the results before and after any operation that you do.
*
* Enjoy!
*/

#include <stdio.h>
typedef struct rational
{
    int numerator;
    int denominator;
}Rational;

Rational increment(Rational inc)
{
    inc.numerator+=inc.denominator;
    return inc;
}

Rational decrement(Rational dec)
{
    dec.numerator-=dec.denominator;
    return dec;
}

Rational multiplication(Rational mul,Rational mul2)
{
    Rational product;
    product.numerator=mul.numerator*mul2.numerator;
    product.denominator=mul.denominator*mul2.denominator;

    if(product.numerator%product.denominator==0)
     { product.denominator=1;
      product.numerator=product.numerator/product.denominator;
      return product;}
    else 
    {return product;}
}

Rational division(Rational div,Rational div2)
{
    Rational quotient;
    quotient.numerator=div.numerator*div2.denominator;
    quotient.denominator=div.denominator*div2.numerator;
    
     if(quotient.numerator%quotient.denominator==0)
    {quotient.denominator=1;
      quotient.numerator=quotient.numerator/quotient.denominator;
      return quotient;}
    else 
    {return quotient;}
}

Rational smaller(Rational sm,Rational sm2)
{
    if(sm.numerator*sm2.denominator > sm.denominator*sm2.numerator)
       return sm2;
    if(sm.numerator*sm2.denominator < sm.denominator*sm2.numerator)
       return sm;
}

int equality(Rational eq,Rational eq2)
{
    if((eq.numerator/eq.denominator)==(eq2.numerator/eq2.denominator))
    {  if((eq.numerator%eq.denominator)==(eq2.numerator%eq2.denominator))
      return 1;
      else
      return 0; }
    else 
    {return 0;}
}

int main()
{
    Rational num;
   printf("Enter the numerator of the rational number:\n");
   scanf("%d",&num.numerator);
   printf("Enter the denominator of the rational number (not equal to 0):\n");
   scanf("%d",&num.denominator);
   
   Rational incremented;
   incremented=increment(num);

   printf("The incremented value is %d/%d\n",incremented.numerator,incremented.denominator);

   Rational decremented;
   decremented=decrement(num);

   printf("The decremented value is %d/%d\n",decremented.numerator,decremented.denominator);

    Rational num2;
   printf("Enter the numerator of another rational number:\n");
   scanf("%d",&num2.numerator);
   printf("Enter the denominator of another rational number (not equal to 0):\n");
   scanf("%d",&num2.denominator);

   Rational multiplied;
   multiplied=multiplication(num,num2);
   printf("The product of two numbers is %d/%d\n",multiplied.numerator,multiplied.denominator);

   Rational divided;
   divided=division(num,num2);
   printf("The result of division of two numbers is %d/%d\n",divided.numerator,divided.denominator);

  Rational small;
  small=smaller(num,num2);
  printf("The smallest among the two is %d/%d\n",small.numerator,small.denominator);

  int equalornot;
  equalornot=equality(num,num2);
   if(equalornot==1)
     printf("Both the numbers are equal.\n");
   if(equalornot==0)
     printf("Both the numbers are not equal.\n");

}
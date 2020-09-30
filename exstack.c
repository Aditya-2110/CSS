#include "istack.h"
#include "charstack.h"
void main()
{
   
   int val;
   char *post,infix[20];
   printf("\n Enter any valid infix:");
   scanf("%s", infix);
   post = convert(infix);
   printf("\nPostfix : %s",post);
   val = evaluate(post);
   printf("\n Result = %d", val);
}
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<process.h>
#define	size	10
struct	cstack
{
char	arr[size];
int sp;
};
void cpush(struct cstack *s,char val)
{
   if(s->sp<size)
     {  
        (s->sp)++;
        s->arr[s->sp] = val;
        
     }
   else 
     {  printf("\n Stack Overflow");
        exit(0);
     }
}
char cpop(struct cstack *s)
{
   char temp;
   if(s->sp>=0)
     {  
        temp=   s->arr[s->sp];
         (s->sp)--;return temp; 
     }
   else 
     {  printf("\n Stack underflow");
        exit(0);
     }
     
}
char ctop(struct cstack s)
{
   char temp;
   if(s.sp>=0)
     {  
        temp=   s.arr[s.sp];
        return temp; 
     }
   else 
     {  printf("\n Stack underflow");
        exit(0);
     }
     
}

int prec(char ch)
{
	if(ch=='+'||ch=='-')
	  return 2;
	if(ch=='*'||ch=='/'||ch=='%')
	    return 5;
	return 0;
}
	
	
	

char * convert(char infix[])
{
	
	struct cstack s;int i=0;
	char *temp, next;
	char *post = (char *)malloc(strlen(infix)+1);
	temp = post;
	s.sp =-1;
	cpush(&s, '#');
	next = infix[i];
	while(next!='\0')	
	{
		if(isdigit(next))
		
		{
		 	*post = next;
		 	 post++;
		} 
		else
		{
			while(prec(next)<= prec(ctop(s)))
			{
				 *post = cpop(&s);
				 post++;
			}
			cpush(&s,next);
	  	}
	  	
		next = infix[++i];	
	}
	next = cpop(&s);
	while(next!= '#')
	{
		*post= next;
		post++;
		next= cpop(&s);
    }
	*post = '\0';
  return temp;
}
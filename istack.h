#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<ctype.h>
#define	size	10
struct	stack
{
int	arr[size];
int sp;
};
void push(struct stack *s,int val)
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
int pop(struct stack *s)
{
   int temp;
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

int evaluate(char post[]) 
{
	struct stack s;
	int op1,op2,op3,i;
	char next;
	s.sp=-1;
	i=0;
	while(post[i]!='\0')
	{
		next = post[i];
		if(isdigit(next))
		   push(&s,next-'0');
		else
		 {
		 	op1= pop(&s);
		 	op2 = pop(&s);
		 	switch(next)
		 	{
		 		case '+': op3 = op1+op2; break;
		 		case '-': op3 = op2-op1; break;
		 		case '*': op3 = op1*op2; break;
		 		case '/': op3 = op2/op1; break;
		 		case '%': op3 = op2%op1; break;
		 		default: printf("\n Invalid Operator");
			 }
			 push(&s,op3);
		} 
		i++;  
	}
	return pop(&s);
}
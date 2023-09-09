#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include"from postfix.h"
#define MAX 20
#define SIZE 100

char stack1[SIZE];
int top = -1;

void push(int);
char pop();
void infix_to_prefix();
int precedence (char);
char stack[20],infix[20],prefix[20];

char pop()
{
char ch;
if(top < 0)
{
printf("\nSTACK UNDERFLOW\n");
exit(0);
}
else
{
ch = stack[top];
stack[top] = '\0';
top--;
return(ch);
}
return 0;
}

void push(int pos)
{
if(top == MAX-1)
{
printf("\nSTACK OVERFLOW\n");
}
else {
top++;
stack[top] = infix[pos];
}}


void infix_to_prefix()
{
int i = 0,j = 0;
strrev(infix);
while(infix[i] != '\0')
{

if(infix[i] >= 'a' && infix[i] <= 'z')
{
prefix[j] = infix[i];
j++;
i++;
}

else if(infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
{
push(i);
i++;
}

else if(infix[i] == '(' || infix[i] == '{' || infix[i] == '[')
{
if(infix[i] == '(')
{
while(stack[top] != ')')
{
prefix[j] = pop();
j++;
}
pop();
i++;
}
else if(infix[i] == '[')
{
while(stack[top] != ']')
{
prefix[j] = pop();
j++;
}
pop();
i++;
}
else if(infix[i] == '{')
{
while(stack[top] != '}')
{
prefix[j] = pop();
j++;
}
pop();
i++;
}}
else
{

if(top == -1)
{
push(i);
i++;
}

else if( precedence(infix[i]) < precedence(stack[top]))
{
prefix[j] = pop();
j++;

while(precedence(stack[top]) > precedence(infix[i])){
prefix[j] = pop();
j++;
if(top < 0) {
break;
}}
push(i);
i++;
}

else if(precedence(infix[i]) >= precedence(stack[top]))
{
push(i);
i++;
}}}

while(top != -1)
{
prefix[j] = pop();
j++;
}

strrev(prefix);
prefix[j] = '\0';

}

int precedence(char alpha)
{
if(alpha == '+' || alpha =='-')
{
return(1);
}
if(alpha == '*' || alpha =='/')
{
return(2);
}
return 0;
}

void push1(char item);
char pop1();
int is_operator(char symbol);
int precedence1(char symbol);
void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
	int i, j;
	char item;
	char x;

	push1('(');
	strcat(infix_exp,")");

	i=0;
	j=0;
	item=infix_exp[i];

	while(item != '\0')
	{
		if(item == '(')
		{
			push1(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;
			j++;
		}
		else if(is_operator(item) == 1)
		{
			x=pop1();
			while(is_operator(x) == 1 && precedence1(x)>= precedence1(item))
			{
				postfix_exp[j] = x;
				j++;
				x = pop1();
			}
			push1(x);

			push1(item);
		}
		else if(item == ')')
		{
			x = pop1();
			while(x != '(')
			{
				postfix_exp[j] = x;
				j++;
				x = pop1();
			}
		}
		else
		{

			printf("\nInvalid infix Expression.\n");
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i];
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");
		getchar();
		exit(1);
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");
		getchar();
		exit(1);
	}


	postfix_exp[j] = '\0';
}

typedef struct node {
    char data;
    struct node *left, *right;
} node;




char* add(node** p, char* a)
{


    if (*a == '\0')
        return '\0';

    while (1) {
        char* q = "null";
        if (*p == NULL) {

            node* nn = (node*)malloc(sizeof(node));
            nn->data = *a;
            nn->left = NULL;
            nn->right = NULL;
            *p = nn;
        }
        else {


            if (*a >= 'a' && *a <= 'z') {
                return a;
            }

            q = add(&(*p)->left, a + 1);


            q = add(&(*p)->right, q + 1);

            return q;
        }
    }
}



void inr(node* p)
{
    if (p == NULL) {
        return;
    }
    else {
        inr(p->left);
        printf("%c", p->data);
        inr(p->right);
    }
}


void postr(node* p)
{
    if (p == NULL) {
        return;
    }
    else {
        postr(p->left);
        postr(p->right);
        printf("%c", p->data);
    }
}








int main()
{
	char infix1[SIZE], postfix[SIZE];



	     printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
         printf("\n\t\t\t\tExpression Converter v1.0");
     printf("\n\n");
     printf("\t\t\t\tPress Any key..to start the Converter");
     getch();
     system("cls");
         printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
         printf("\n\t\t\t\tExpression Converter v1.0");

	printf("\nEnter Infix expression : ");
	gets(infix1);
	strcpy(infix,infix1);

	infix_to_prefix();

	printf("Prefix Expression : %s ",prefix);
    InfixToPostfix(infix1,postfix);
	printf("\nPostfix Expression: ");
	puts(postfix);




    node* s = NULL;
    char a[SIZE];

    printf("\nEnter Prefix Expression : ");
    gets(a);
    add(&s, a);
    printf("The Infix expression is: ");
    inr(s);
    printf("\n");
    printf("The Postfix expression is: ");
    postr(s);





char z[100];
  int len,i;
  struct node1 *new_node;


  printf("\n\nEnter Postfix Expression : ");
  gets(z);
  len=strlen(z);
  for(i=len-1 ; i>=0 ; i--)
  {
   new_node=(struct node1 *)malloc(sizeof(struct node1));
   new_node->data=z[i];
   new_node->left=new_node->right=new_node->prev=NULL;
   if(root==NULL)
   {
     root=new_node;
     cur=par=root;
   }
   else
   {
    if(z[i]=='+' ||z[i]=='-' ||z[i]=='*'||z[i]=='/')
    {
     if(par->right==NULL)
     {
      cur=new_node;
      par->right=cur;
      cur->prev=par;
      par=cur;
     }
     else if(par->left==NULL)
     {
      cur=new_node;
      par->left=cur;
      cur->prev=par;
      par=cur;
     }
    else
    {
     while(par->left!=NULL)
     {
      par=par->prev;
     }
     cur=new_node;
     par->left=cur;
     cur->prev=par;
     par=cur;
    }
   }
   else
   {
    if(par->right==NULL)
    {
     cur=new_node;
     par->right=cur;
     cur->prev=par;
    }
    else if(par->left==NULL)
    {
     cur=new_node;
     par->left=cur;
     cur->prev=par;
    }
    else
    {
     while(par->left!=NULL)
     {
      par=par->prev;
     }
     cur=new_node;
     par->left=cur;
     cur->prev=par;
    }
   }
  }
 }
 printf("Infix Expression is : ");
 inorder(root);
 printf("\nPrefix Expression is : ");
 preorder(root);

 getch();






	return 0;
}










void push1(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack1[top] = item;
	}
}


char pop1()
{
	char item ;

	if(top <0)
	{
		printf("stack1 under flow: invalid infix expression");
		getchar();

		exit(1);
	}
	else
	{
		item = stack1[top];
		top = top-1;
		return(item);
	}
}




int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}



int precedence1(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}



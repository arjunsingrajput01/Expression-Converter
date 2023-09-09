#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>

struct node1
{
 struct node1 *right,*left,*prev;
 char data;
}*cur,*par,*root=NULL;
//-------INORDER-------
void inorder(struct node1 *root)
{
 if(root!=NULL)
 {
  inorder(root->left);
  printf("%c",root->data);
  inorder(root->right);
 }
}

//-------PREORDER-------
void preorder(struct node1 *root)
{
 if(root!=NULL)
 {
  printf("%c",root->data);
  preorder(root->left);
  preorder(root->right);
 }
}
//-------POSTORDER-------
void postorder(struct node1 *root)
{
 if(root!=NULL)
 {
  postorder(root->left);
  postorder(root->right);
  printf("%c\t",root->data);
 }
}

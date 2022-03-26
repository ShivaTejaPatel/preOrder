#include<stdio.h>
#include<stdlib.h>
struct node{
	int e;
	struct node *left;
	struct node *right;
};

struct queue{
	struct node *a[10];
	int f;
	int r;
};

void enqueue(struct queue *q,struct node *ele)
{
	q->r++;
	q->a[q->r]=ele;
}

struct node *dequeue(struct queue *q)
{
	if(q->f==q->r)
		return NULL;
	else
	{
		q->f++;
		return q->a[q->f];
	}
}

int isEmpty(struct queue *q)
{
	if(q->f==q->r)
		return 1;
	else
		return 0;
}


struct node * insert(struct node *root,int ele)
{
	if(root==NULL)
	{
		root=(struct node *)malloc(sizeof(struct node));
		root->e=ele;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		struct node *temp,*temp1;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->e=ele;
		temp->left=NULL;
		temp->right=NULL;
		struct queue *q;
		q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
		enqueue(q,root);
		while(!isEmpty(q))
		{
			temp1=dequeue(q);
			if(temp1->left!=NULL)
			{
				enqueue(q,temp1->left);
			}
			else
			{
				temp1->left=temp;
				break;
			}
			if(temp1->right!=NULL)
			{
				enqueue(q,temp1->right);
			}
			else
			{
				temp1->right=temp;
				break;
			}
			
		}
	}
	return root;
}

void preOrder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d",root->e);
		preOrder(root->left);
		preOrder(root->right);
	}
}

			

void main()
{
	int op,ele;
	struct node *root=NULL;
	do{
		printf("Enter your option\t1.Insert\t2.Print\t3.Exit");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("Enter the element you want to insert: ");
				scanf("%d",&ele);
				root=insert(root,ele);
				break;
			case 2:
				preOrder(root);
				break;
			case 3:
				break;
			default:
				printf("\ninvalid option\n");
		}
	}while(op!=3);
}


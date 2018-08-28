#include<time.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
 void timestamp()
{
    time_t ltime;
    ltime=time(NULL);
    printf("%s",asctime( localtime(&ltime) ) );
}
int getLevelUtil(struct node *node, int data, int level)
{
    if (node == NULL)
	return 0;

    if (node->data == data)
	return level;

    int downlevel = getLevelUtil(node->left, data, level+1);
    if (downlevel != 0)
	return downlevel;

    downlevel = getLevelUtil(node->right, data, level+1);
    return downlevel;
}

int getLevel(struct node *node, int data)
{
    return getLevelUtil(node,data,1);
}

 int main()
{
  struct node *root = newNode(1);
   root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
    for (int x = 1; x <=5; x++)
    {
      int level = getLevel(root, x);
      if (level)
	printf(" Level of %d is %d\n", x, getLevel(root, x));
      else
	printf(" %d is not present in tree \n", x);
    }
   getchar();
    return 0;
}



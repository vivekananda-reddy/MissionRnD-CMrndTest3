/*
Given a Binary Tree of N Nodes, which have unique values in the range of 
[0,N](Inclusive)  with one value(Node) missing in that sequence.
Return that missing value .

Example 1 : N=5 
   3
  / \
 4   1
    / \
   5   0
Missing Value is 2 ,Sequence is [0,1,2,3,4,5]

Example 2 : N=8
      2
     / \
    4   5
   / \ / \
  3  1 6  8
 /
0
Missing Value is 7 ,Sequence is [0,1,2,3,4,5,6,7,8]

Constaints : 
-10000<=N<=10000 [N will not be equal to 0]



Input :
Struct node Root Address
Output :
Return Missing Value .
Return -1 for NULL Inputs 

Note:
Dont Create an Extra Array/String ,or else your solution would receive 30% Cut in the Marks you got for this
question .

Difficulty : Easy
*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

long traversethetree(struct node*, long);
int get_missing_value(struct node *root,int n){
	long sum,totalsum,ans;
	if (root==NULL||n==0)
		return -1;
	sum = traversethetree(root,0);
	if (n > 0)
	{
		totalsum = (n*(n + 1)) / 2;
		return(totalsum - sum);
	}
	else
	{
		n = n*-1;
		sum = sum*-1;
		totalsum = (n*(n + 1)) / 2;
		ans=-(totalsum - sum);

	}

}

long traversethetree(struct node*root, long sum)
{
	if (root == NULL)
	{
		return sum;
	}
	sum = sum + root->data;
	sum = traversethetree(root->left,sum);
	sum = traversethetree(root->right, sum);
	return sum;
}
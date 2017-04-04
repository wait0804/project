#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<queue>
using namespace std;

typedef struct BinTreeNode{
	char data;
	struct BinTreeNode *left;
	struct BinTreeNode *right;
}BinTreeNode;


void preMidTree(BinTreeNode **root, char *VLR, char *LVR, int n){
	if(n == 0){
		*root = NULL;
		return;
	}else{
		int k = 0;

		while(VLR[0] != LVR[k]){
			k++;
		}
		(*root) = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		(*root)->data = VLR[0];

		preMidTree(&(*root)->left, VLR+1, LVR, k);
		preMidTree(&(*root)->right, VLR+k+1, LVR+k+1, n-k-1);
	}
}

void lastShow(BinTreeNode *root){
	if(root){
		lastShow(root->left);
		lastShow(root->right);
		printf("%c ", root->data);
	}
}


void levelTree(BinTreeNode *root){
	queue<BinTreeNode *> qu;

	if(root){
		qu.push(root);
		while(!qu.empty()){
			BinTreeNode *p = qu.front();
			qu.pop();
			printf("%c ", p->data);
			if(p->left){
				qu.push(p->left);
			}
			if(p->right){
				qu.push(p->right);
			}
		}
	}
}	


int main(void){
	char *VLR;
	char *LVR;
	int n;

	printf("请输入总结点个数: ");
	scanf("%d", &n);

	VLR = (char *)malloc(sizeof(char) * n);
	LVR = (char *)malloc(sizeof(char) * n);
	printf("请输入前序序列(字符串): ");
	fflush(stdin);
	gets(VLR);
	fflush(stdin);
	printf("请输入中序序列(字符串): ");
	gets(LVR);
	BinTreeNode *root = NULL;

	preMidTree(&root, VLR, LVR, n);

	printf("其层次遍历为: ");
	levelTree(root);
	printf("\n其后序遍历为: ");
	lastShow(root);
	printf("\n");

	return 0;
}

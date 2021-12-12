#include<bits/stdc++.h>
using namespace std;
char a[51], b[51];
typedef struct treeNode* tree;
struct treeNode
{
	char data;
	tree left, right;
};

tree creat()
{
	tree p = (tree)malloc(sizeof(tree));
	p->left = p->right = NULL;
	return p;
}

tree findTree(char in[],char pre[],int length){
    if(length==0) return NULL;
    tree head = creat();
    head->data=pre[0];
    int i=0;
    for(i=0;i<length;i++){
        if(in[i]==pre[0]) break;
    }
    head->left=findTree(in,pre+1,i);
    head->right=findTree(in+i+1,pre+i+1,length-i-1);
    return head;
}

int GetHeight( tree BT){
    int cnt =0;
    if(BT == NULL){
        return cnt;
    }
    else{
        int left,right;
        left = GetHeight(BT->left);
        right = GetHeight(BT->right);
        if(left > right){
            cnt = left +1;
        }
        else{
            cnt = right+1;
        }
        return cnt;
    }
}

int main()
{
	int n;
    cin>>n;
	for (int i = 0; i < n; i++){
		cin>>a[i];
    }
	for (int i = 0; i < n; i++){
		cin>>b[i];
    }
	tree head = findTree(b, a, n);
    int height = GetHeight(head);
    cout<<height;
	return 0;
}
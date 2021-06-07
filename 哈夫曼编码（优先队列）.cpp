#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
	struct TreeNode *left,*right;
	char c;
	int weight;//结点的权值 
	string code;//哈夫曼编码值 
	TreeNode():left(NULL),right(NULL),c('\0'),weight(0),code(""){
	}
};
struct ans{
	char ch;
	string s;
	ans():ch('\0'),s(""){
	}
}; 
struct ans anss[100];
int m=0;
//重写比较函数 
struct func{
	bool operator()(struct TreeNode* x,struct TreeNode* y){
		return x->weight>y->weight;
	}
};

//用优先队列构造最小堆 
priority_queue<struct TreeNode*,vector<struct TreeNode*>,func>pq;

//遍历构建的哈夫曼树 
void TraverseTree(struct TreeNode* root){
	//如果是叶子结点就将字符和编码放入结果结构体 
	if(!(root->left)&&!(root->right)){
		anss[m].ch=root->c;
		anss[m].s=root->code;
		m++; 
	}
	if(root->left){
		root->left->code=root->code+"0";
		TraverseTree(root->left);//递归遍历左子树 
	}
	if(root->right){
		root->right->code=root->code+"1";
		TraverseTree(root->right);//递归遍历右子树 
	}
}
int cnt;
void HUFFMAN(){
	int tmp;
	vector<int>Frequency;
	cin>>cnt;
	for(int i=0;i<cnt;i++){
		cin>>tmp;
		Frequency.push_back(tmp);
	}
	for(int i=0;i<cnt;i++){
		struct TreeNode* PtrToNode=new TreeNode;
		PtrToNode->c='a'+i;
		PtrToNode->weight=Frequency[i];
		pq.push(PtrToNode);//将树结点存入优先队列 
	} 
	while(pq.size()>1){
		struct TreeNode *a,*b;
		a=pq.top();
		pq.pop();
		b=pq.top();
		pq.pop();
		struct TreeNode* tmp=new TreeNode;
		tmp->weight=a->weight+b->weight;
		tmp->left=a;
		tmp->right=b;
		pq.push(tmp);
	}
	TraverseTree(pq.top());
/*
由于采用从优先队列最上层元素作为左子树，后一层作为右子树，所以建好的树如下：
                   100
			 45a            55
					 25              30
				12c     13b     14      16d
							 5f    9e
所以不论采用什么遍历方式去遍历树都没办法顺序输出个字符的编码
所以遍历到叶子结点的时候先将该节点存入结构体中，等遍历完整个树再对结构体进行排序	 
*/ 
}
int main(){
	HUFFMAN();
	//冒泡排序按结构体中的字符ascii码 
	for (int j = 0; j < cnt-1; j++){
  		for (int i = 0; i < cnt -1- j; i++){
   			if (anss[i].ch>anss[i+1].ch){
				swap(anss[i],anss[i+1]);
   			}
  		}
 	}
	for(int i=0;i<cnt;i++){
		cout<<anss[i].ch<<" "<<anss[i].s<<endl;
	}
	return 0;
}
/*
6
45 13 12 16 9 5
*/

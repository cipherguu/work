#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
	struct TreeNode *left,*right;
	char c;
	int weight;//����Ȩֵ 
	string code;//����������ֵ 
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
//��д�ȽϺ��� 
struct func{
	bool operator()(struct TreeNode* x,struct TreeNode* y){
		return x->weight>y->weight;
	}
};

//�����ȶ��й�����С�� 
priority_queue<struct TreeNode*,vector<struct TreeNode*>,func>pq;

//���������Ĺ������� 
void TraverseTree(struct TreeNode* root){
	//�����Ҷ�ӽ��ͽ��ַ��ͱ���������ṹ�� 
	if(!(root->left)&&!(root->right)){
		anss[m].ch=root->c;
		anss[m].s=root->code;
		m++; 
	}
	if(root->left){
		root->left->code=root->code+"0";
		TraverseTree(root->left);//�ݹ���������� 
	}
	if(root->right){
		root->right->code=root->code+"1";
		TraverseTree(root->right);//�ݹ���������� 
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
		pq.push(PtrToNode);//�������������ȶ��� 
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
���ڲ��ô����ȶ������ϲ�Ԫ����Ϊ����������һ����Ϊ�����������Խ��õ������£�
                   100
			 45a            55
					 25              30
				12c     13b     14      16d
							 5f    9e
���Բ��۲���ʲô������ʽȥ��������û�취˳��������ַ��ı���
���Ա�����Ҷ�ӽ���ʱ���Ƚ��ýڵ����ṹ���У��ȱ������������ٶԽṹ���������	 
*/ 
}
int main(){
	HUFFMAN();
	//ð�����򰴽ṹ���е��ַ�ascii�� 
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

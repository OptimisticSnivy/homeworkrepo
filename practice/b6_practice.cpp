#include<iostream>
using namespace std;

class node{
public:
  int data;
  node* right;
  node* left;

  node(int d){
    this->data=d;
    this->left=NULL;
    this->right=NULL;
  }

};

void inorder(node* root){
  if(root!=NULL){
    inorder(root->left);
    cout<<"->"<<root->data;
    inorder(root->right);
  }
}

void mirror(node* root){
  if(root==NULL){
    return;
  }
  else{
    mirror(root->left);
    mirror(root->right);
    swap(root->right,root->left);
  }
}

int minvalueofbst(node* root){
  node* temp=root;
  while(temp->left!=NULL){
    temp=temp->left;
  }
  return temp->data;
}

node* insertintobst(node* root,int d){
    if(root==NULL){
      root=new node(d);
      return root;
    }
    if(d > root->data){
      root->right=insertintobst(root->right,d);
    }
    else{
      root->left=insertintobst(root->left,d);
    }
    return root;
}

int maxDepth(node* node)
{
    if (node == NULL)
        return 0;
    else {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
 
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

bool searchintobst(node* root,int key){
  node* temp=root;
  
  if(root==NULL){
    return false;
  }
  if(root->data==key){
    return true;
  }
  if(root->data > key){
    searchintobst(root->left,key);
  }
  else{
    searchintobst(root->right,key);
  }
}

void takeInput(node* &root){
    int data;
    cin>>data;
    while(data!=-1){
      root=insertintobst(root,data);
      cin>>data;
    }  
}

int main(){
  bool flag;
  int minvalue;
  node* root=NULL;
  cout<<"Enter data to create BST;-"<<endl;
  takeInput(root);
  cout<<maxDepth(root);
  return 0;
}

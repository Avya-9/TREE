#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int d){
        this->data=d;
        this->right=NULL;
        this->left=NULL;

    }

};
node* insertbst(node*root,int d){
    if(root==NULL){
        root=new node(d);
        return root;
    }
    if(d > root->data){
        root->right=insertbst(root->right,d);
    }
    else{
        root->left=insertbst(root->left,d);
    }
    return root;
}
void takeinput(node*&root){
    int data;
    cin>>data;
    while(data != -1){
        root=insertbst(root,data);
        cin>>data;
    }
}
void levelordertraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);//seperator
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }   
        else{
            cout<< temp ->data<<" ";
            if(temp ->left){
                q.push(temp ->left);
            }
            if(temp ->right){
                q.push(temp ->right);
            }
        }
        
    }
}
//recursive search
bool search(node* root,int k){
    if(root==NULL){
        return false;
    }
    if(k==root->data){
        return true;
    }
    else if(k<root->data){
        return search(root->left,k);
    }
    else if(k>root->data){
        return search(root->right,k);
    }
    else{
        return false;
    }
}
//iterative search
bool searchiter(node* root,int k){
    node* temp=root;
    while(temp !=NULL){
        if(k==temp->data){
            return true;
        }
        else if(k<temp->data){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return false;
}
void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root ->left);
    cout<<root ->data<<" ";
    inorder(root ->right);
}
void preorder(node *root){
    if(root==NULL){
        return;
    }
    cout<<root ->data<<" ";
    preorder(root ->left);
    preorder(root ->right);
}
void postorder(node *root){
    if(root==NULL){
        return;
    }
    postorder(root ->left);
    postorder(root ->right);
    cout<<root ->data<<" ";
    
}
node* min(node* root){
    node* temp=root;
    while(temp->left != NULL){
        temp=temp->left;
    }
    return temp;
}
node* max(node* root){
    node* temp=root;
    while(temp->right !=NULL){
        temp=temp->right;
    }
    return temp;
}
node* deletion(node* root,int k){
    if(root==NULL){
        return root;
    }
    if(root->data==k){
        if(root->right==NULL && root->left==NULL){
            delete root;
            return NULL;
        }
        if(root ->right==NULL && root->left!=NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->right!=NULL && root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        if(root->right!=NULL && root->left!=NULL){
            int mini= min(root->right)->data;
            root->data=mini;
            root->right=deletion(root->right,mini) ;
            return root->right;
        }
        else{
            return 0;
        }

    }
    else if(root->data>k){
        root=deletion(root->left,k);
        return root;
    }
    else{
        root=deletion(root->right,k);
        return root;
    }

}
int main(){
    node* root=NULL;
    cout<<"data for bst"<<endl;
    takeinput(root);
    cout<<"bst:"<<endl;
    levelordertraversal(root);
    cout<<"search element";
    int k;
    cin>>k;
    if(searchiter(root,k)){
        cout<<"it is present"<<endl;
    }
    else{
        cout<<"not present"<<endl;
    }
    cout<<"max value"<<max(root)<<endl;
    cout<<"min value"<<min(root)<<endl;
    cout<<"preorder:";
    preorder(root);
    cout<<endl<<"preorder:";
    preorder(root);
    cout<<endl<<"inorder:";
    inorder(root);
    deletion(root,3);
    cout<<"bst after deletion:"<<endl;
    levelordertraversal(root);
}
// 15 6 18 3 7 17 20 2 4 13 9 -1
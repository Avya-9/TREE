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
        this -> data=d;
        this -> left=NULL;
        this ->right=NULL;
    }

};
node* buildtree(node* root){
    cout<<"enter data";
    int data;
    cin>>data;
    root=new node(data);
    if (data==-1){
        return NULL;
    }
    cout<<"enter data for left";
    root ->left=buildtree(root ->left);
    cout<<"enter data for right";
    root ->right=buildtree(root ->right);
    return root;
}
/*node* buildbst(node* root,int data){

    root=new node(data);
    if (data==-1){
        return NULL;
    }
    else{
        cout<<"enter data";
        int data2;
        cin>>data2;
        if(data2<data){
            root->left=buildbst(root->left,data2);
        }
        else{
            root->right=buildbst(root->right,data2);
        }
    }
    return root;
}*/

void levelordertraversal(node* root){
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    q.push(NULL);//seperator
    while(!q.empty()){
        node* temp=q.front();
        
        q.pop();
        s.push(temp);
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
    cout<<"reverse";
    while(!s.empty()){
        node* temp1=s.top();
        s.pop();
        if(temp1!=NULL){
            cout<<temp1 -> data<<" ";
        }
        else{
            cout<<endl;
        }

    }
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
void buildfromlevelorder(node* &root){
    queue<node*> q;
    cout<<"enter root"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<"enter left node for"<<temp ->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata !=-1){
            temp ->left=new node(leftdata);
            q.push(temp ->left);
        }
        cout<<"enter right node for"<<temp ->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata !=-1){
            temp ->right=new node(rightdata);
            q.push(temp ->right);
        }
    }  
}
int height(node* &root){
    if(root == NULL){
        return 0;
    }
    int left=height(root ->left);
    int right=height(root ->right);
    int h=max(left,right)+1;
    return h;
}
pair<int,int> diameterfast(node* root){
    if(root == NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }
    pair<int,int> left=diameterfast(root ->left);
    pair<int,int> right=diameterfast(root -> right);
    int opt1=left.first;
    int opt2=right.first;
    int opt3=left.second + right.second + 1;
    pair<int,int> ans;
    ans.first=max(opt1,max(opt2,opt3));
    ans.second=max(left.second,right.second)+1;
    return ans;
}
int diameter(node* &root){
    /*if(root == NULL){
        return 0;
    }
    int opt1=diameter(root ->left);
    int opt2=diameter(root->right);
    int opt3=height(root->right)+height(root->left)+1;
    int ans=max(opt1,max(opt2,opt3));
    return ans;*/
    return diameterfast(root).first;
}
bool balanced(node* root){
    if(root == NULL){
        return true;
    }
    bool left= balanced(root ->left);
    bool right=balanced(root ->right);
    bool diff= abs(diameterfast(root->right).second - diameterfast(root->left).second) <=1;
    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
    /*if(abs(diameterfast(root->right).second - diameterfast(root->left).second) <=1){
        return 1;
    }
    else{
        return 0;
    }*/
}
bool isidentical(node* r1,node* r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1 != NULL && r2 == NULL){
        return false;
    }
    if(r1 == NULL && r2 != NULL){
        return false;
    }
    bool left=isidentical(r1->left,r2->left);
    bool right=isidentical(r1->right,r2->right);
    bool value=r1->data==r2->data;
    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}
node* search(node* root,int k){
    if(root==NULL || root-> data==k){
        return root;
    }
    if(k<root->data){
        return search(root->left,k);
    }
    else {
        return search(root->right,k);
    }
}
bool sumtree(node* root){
    if(root==NULL){
        return true;
    }
    bool left=sumtree(root->left);
    bool right=sumtree(root->right);
    bool ans= (left +right) + root->data;
    if(left && right && ans){
        return true;
    }
    else{
        return false;
    }

}
int main(){
    node* root=NULL;
    /*cout<<"enter root";
    int data;
    cin>>data;
    root= buildbst(root,data);*/
    root=buildtree(root);
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 15 10 13 5 -1 -1 -1 14 -1 -1 12 16 17 -1 -1 18 -1 19 -1 -1 -1
    cout<<"tree is "<<endl;
    
    /*cout<<endl<<"inorder"<<endl;
    inorder(root);*/
    cout<<endl<<"preorder"<<endl;
    preorder(root);
    cout<<endl;
    /*cout<<endl<<"postorder"<<endl;
    postorder(root);*/
    //cout<<"reverse:"<<endl;
    //reverse(root);
    //buildfromlevelorder(root);
    levelordertraversal(root);
    cout<<endl<<"height is "<<height(root);
    cout<<endl<<"diameter is"<<diameter(root)<<endl;
    cout<<balanced(root);
    int k;
    cout<<"element to be searched";
    cin>>k;
    node* result=search(root,k);
    if(result==NULL){
        cout<<"element not found";
    }
    else{
        cout<<"element found";
    }
    
}
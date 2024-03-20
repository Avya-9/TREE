#include<iostream>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return ;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void deletion(){
        if(size==0){
            cout<<"none";
            return;
        }
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size){
            int lefti=2*1;
            int righti=2*i +1;
            if(lefti<size && arr[i]<arr[lefti]){
                swap(arr[i],arr[lefti]);
                i=lefti;
            }
            else if(righti<size && arr[i]<arr[righti]){
                swap(arr[i],arr[righti]);
                i=righti;
            }
            else{
                return;
            }
        }
    }
    void heapify(int arr[],int n,int i){
        int largest=i;
        int lefti=2*1;
        int righti=2*i +1;

    }
    void heapsort(int arr[],int n){
        int size=n;
        while(size==1){
            for(int i=1;i<=size;i++){
                swap(arr[size],arr[1]);
                size--;
                heapify(arr,size,1);

            }
        }
    }
};

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletion();
    h.print();
}
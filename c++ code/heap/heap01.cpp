#include<iostream>
using namespace std;
class heap{
    public:
    int size;
    int capacity;
    int *arr;
    heap(int capacity){
        this->size=0;
        this->capacity=capacity;
        this->arr=new int[capacity+1];
    }
    void insertHeap(int ele){
        if(size==capacity){
            cout<<"Heap overflow\n";
            return;
        }else{
            size++;
            arr[size]=ele;
            int index=size;
            while(index>1){
                int parentIndex=index/2;
                if(parentIndex>=1&&arr[parentIndex]<arr[index]){
                    swap(arr[parentIndex],arr[index]);
                    index=parentIndex;
                }else{
                    break;
                }
            }
        }
    }
    void printHeap(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int deleteHeap(){
        if(size==0){
            cout<<"heap underflow\n";
            return -1;
        }else{
            int answer=arr[1];
            arr[1]=arr[size];
            size--;
            int index=1;
            while(index<=size){
                int leftindex=2*index;
                int rightindex=2*index+1;
                int largestindex=index;
                if(leftindex<=size&&arr[leftindex]>arr[largestindex]){
                    largestindex=leftindex;
                }
                if(rightindex<=size&&arr[rightindex]>arr[largestindex]){
                    largestindex=rightindex;
                }
                if(largestindex==index)break;
                else{
                    swap(arr[largestindex],arr[index]);
                    index=largestindex;
                }
            }
            return answer;
        }
    }
};
int main(){
    heap h(6);
    h.insertHeap(10);
    h.insertHeap(15);
    h.insertHeap(8);
    h.insertHeap(20);
    h.insertHeap(30);
    h.insertHeap(40);
    h.printHeap();
    return 0;
}
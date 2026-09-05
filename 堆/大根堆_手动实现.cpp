#include<iostream>
#include<algorithm>
#include<vector>
#include<stdexcept>
using namespace std;

class MaxHeap{
private:
    vector<int>heap;
    int pa(int i){
        return i/2;
    }
    int le(int i){
        return i*2;
    }
    int ri(int i){
        return i*2+1;
    }

    void heapify_up(int i){
        while(i>0&&heap[pa(i)]<heap[i]){
            swap(heap[i],heap[pa(i)]);
            i=pa(i);
        }
    }

    void heapify_down(int i){
        int largest=i;
        int left=le(i);
        int right=ri(i);
        if(left<heap.size()&&heap[left]>heap[largest]){
            largest=left;
        }
        if(right<heap.size()&&heap[right]>heap[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(heap[i],heap[largest]);
            heapify_down(largest);
        }
    }

public:
    void push(int val){
        heap.push_back(val);
        heapify_up(heap.size()-1);
    }

    int top(){
        if(heap.empty()){
            throw out_of_range("heap is empty");
        }
        return heap[0];
    }

    void pop(){
        if(heap.empty()){
            throw out_of_range("heap is empty");
        }
        heap[0]=heap.back();
        heap.pop_back();
        heapify_down(0);
    }

    bool empty(){
        return heap.empty();
    }
};

int main(){
    MaxHeap maxheap;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        maxheap.push(x);
    }
    while(!maxheap.empty()){
        cout<<maxheap.top()<<' ';
        maxheap.pop();
    }
    return 0;
}
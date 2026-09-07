#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    priority_queue<int>max_q;             //这个是大根堆，按照从大到小的顺序排列
    priority_queue<int,vector<int>,greater<int>>min_q;          //这个是小根堆，数据是按照从小到大的顺序排列
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        max_q.push(x);
        min_q.push(x);
    }
    for(int i=0;i<n;i++){
        cout<<max_q.top()<<' ';
        max_q.pop();
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<min_q.top()<<' ';
        min_q.pop();
    }
    return 0;
}
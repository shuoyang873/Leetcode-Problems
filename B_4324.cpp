#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int left_node[500005]={0},right_node[500005]={0},value[500005]={0};
int main(){
    int n,m;
    cin>>n>>m;
    right_node[0]=1;
    left_node[1]=0;
    int pos=1;
    for(int i=0;i<m;i++){
        int order;
        cin>>order;
        if(order==1){
            int x,y;
            cin>>x>>y;
            right_node[pos]=x;
            left_node[pos]=left_node[x];
            right_node[left_node[x]]=pos;
            left_node[x]=pos;
            value[pos]=y;
            pos++;
        }
        else if(order==2){
            int x,y;
            cin>>x>>y;
            left_node[pos]=x;
            right_node[pos]=right_node[x];
            left_node[right_node[x]]=pos;
            right_node[x]=pos;
            value[pos]=y;
            pos++;
        }
        else if(order==3){
            int x;
            cin>>x;
            if(right_node[x]==1&&left_node[x]==0)continue;
            left_node[right_node[x]]=left_node[x];
            right_node[left_node[x]]=right_node[x];
            left_node[x]=0;
            right_node[x]=1;
        }
    }
    if(right_node[0]==1){
        cout<<"Empty!"<<endl;
        return 0;
    }
    for(int i=right_node[0];i!=1;i=right_node[i]){
        cout<<value[i]<<' ';
    }
    return 0;
}
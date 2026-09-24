#include<iostream>
#include<algorithm>

using namespace std;
int max_depth;

void count_depth(int tree[][2],int cur,int len){
    if(tree[cur][0]==0&&tree[cur][1]==0){
        return ;
    }
    len++;
    max_depth=max(max_depth,len);
    if(tree[cur][0]!=0){
        count_depth(tree,tree[cur][0],len);
    }
    if(tree[cur][1]!=0){
        count_depth(tree,tree[cur][1],len);
    }
}

int main(){
    int n;
    cin>>n;
    static int tree[1000001][2]={0};
    for(int i=0;i<n;i++){
        cin>>tree[i][0]>>tree[i][1];
    }
    count_depth(tree,0,0);
    cout<<max_depth<<endl;
    return 0;
}
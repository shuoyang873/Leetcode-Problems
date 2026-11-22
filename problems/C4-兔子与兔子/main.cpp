#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
#define distance 131
int main(){
    string s;
    cin>>s;
    int n=s.size();
    vector<unsigned long long>hash(n+1);
    vector<unsigned long long>pave(n+1);
    pave[0]=1;
    hash[0]=0;           //这边的哈希值要设置为0，否则会出错
    for(int i=1;i<=n;i++){
        hash[i]=hash[i-1]*distance+(int)s[i-1];          //这边是i-1，不是i
        pave[i]=pave[i-1]*distance;
    }
    // for(int i=0;i<=n;i++){
    //     cout<<hash[i]<<' ';
    // }
    // cout<<endl;
    // for(int i=0;i<=n;i++){
    //     cout<<pave[i]<<' ';
    // }
    // cout<<endl;
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        long long num1=hash[r1]-hash[l1-1]*pave[r1-l1+1];         //这边是l1-1，后面这个还要就+1
        long long num2=hash[r2]-hash[l2-1]*pave[r2-l2+1];
        if(num1==num2){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
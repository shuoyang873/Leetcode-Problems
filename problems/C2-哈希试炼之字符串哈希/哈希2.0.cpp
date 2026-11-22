#include<iostream>
#include<cstring>
using namespace std;
#define distance 131
int h[1000005];
unsigned long long p[1000005];
int main(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    p[0]=1;
    for(int i=1;i<=n;i++){
        h[i]=h[i-1]*distance+(unsigned char)s[i-1];
        p[i]=p[i-1]*distance;
    }
    for(int i=0;i<m;i++){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        int num_l=h[r1]-h[l1-1]*p[r1-l1+1];
        int num_r=h[r2]-h[l2-1]*p[r2-l2+1];
        if(num_l==num_r){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
/*
题目链接：https://www.lanqiao.cn/problems/97/learning/?page=1&first_category_id=1&second_category_id=3

*/


//我第一次的代码：（采用前缀和的方法，暴力枚举每个区间，进行减法，判断是否是k的倍数，对于较大的输入会超时）

#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int n,k,cnt=0;
  cin>>n>>k;
  int sum[100001]={0};
  for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    sum[i]=sum[i-1]+x;
  }
  for(int i=0;i<=n-1;i++){
    for(int j=i+1;j<=n;j++){
      if((sum[j]-sum[i])%k==0){
        cnt++;
      }
    }
  }
  cout<<cnt<<endl;
  return 0;
}
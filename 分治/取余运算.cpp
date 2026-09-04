/*
1326：【例7.5】 取余运算（mod）

时间限制: 1000 ms         内存限制: 65536 KB
提交数:39705    通过数: 16926
【题目描述】
输入b，p，k
的值，求bpmodk
的值。其中b，p，k×k
为长整型数。

【输入】
输入b，p，k
的值。

【输出】
求bpmodk
的值。

【输入样例】
2 10 9
【输出样例】
2^10 mod 9=7
*/


#include<bits/stdc++.h>
using namespace std;

int b,p,k;

//这个分治操作基于两个数学公式：1、（a*b)%k=(a%k)*(b*k)%k;2、p=2*(p/2)+p%2;
//因此，可以将指数p按照公式2拆解，然后分成几个数的乘积，这样就可以使用公式1，对每个更小的数值部分进行取模运算，最后再将这些结果相乘并取模，得到最终的结果
long long f(int p){

    //递归出口，如果指数为0，那么结果为1，1对任何数取模都是1，所以直接返回1%k
    if(p==0)return 1%k;

    //递归处理更小部分的取模的值
    long long tmp=f(p/2)%k;
    tmp=(tmp*tmp)%k;

    //如果指数是奇数，那么还要乘上一个b的取模值
    if(p%2)tmp=(tmp*b)%k;
    return tmp;
}

int main(){
    cin>>b>>p>>k;

    //因为任何数对1取模都是0，所以提前处理
    if(k==1){
        cout<<0<<endl;
        return 0;
    }

    //这边需要提前对b进行取模，防止b原先的值过大
    b%=k;

    //这边的数据类型要使用long long，防止数据溢出
    long long ans=f(p);
    cout<<ans<<endl;
    return 0;
}
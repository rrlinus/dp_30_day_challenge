#include <bits/stdc++.h>
using namespace std;
int k=16;
int N=100000;
int table[N][k+1];
int arr[N];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // built sparse table
    for(int i=0;i<n;i++){
        table[i][0]=arr[i];
    }
    for(int j=1;j<=k;j++){
        for(int i=0;i<=n-(1<<j);i++){
            // why <=? because if from index i to x length it means that index i to index i+x-1
            table[i][j]=table[i][j-1]+table[i+(1<<(j-1))][j-1];
                    // i to 2^(j-1)-1  + i+2^(j-1) to i+(2^j)-1.
        }
    }
    //query 
    int q,l,r;
    cin>>q;
    for(int i==0;i<q;i++){
        cin>>l>>r;
        int ans=0;
        for(int j=k;j>=-0;j--){
            if(l+(1<<j)-1<=r){
                ans +=table[l][j];
                l+=(1<<j);
            } 
        }
    }
}
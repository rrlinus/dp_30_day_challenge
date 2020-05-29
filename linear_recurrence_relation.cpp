// solving linear recurrence relation in k^3*logN where is the order of linear equation 
// N denotes the nth term.
// in this situation fist we will try to find the transformation matrix 
// let say f(n)=f(n-3)+2*f(n-2)+3*f(n-1);
// where f(0)=1 f(1)=2 f(2) =3;

//  0 1 0      f(0)     f(1)                f(1)
//  0 0 1   *  f(1)  == f(2)           ===  f(2)
//  1 2 3      f(2)     f(0)+2*f(1)+3*f(3)  f(3)
 
//  0 1 0      f(1)     f(2)                f(2)
//  0 0 1   *  f(2)  == f(3)           ===  f(3)
//  1 2 3      f(3)     f(1)+2*f(2)+3*f(3)  f(4)
// ........
// .........so on.please visualise the matrix at least once on paper
// https://www.hackerearth.com/practice/notes/solving-linear-recurrence-relation/

// f(n)=f(n-1)+f(n-2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//multiplication of two matrix
vector<vector<int>> mul(vector<vector<int>> &x,vector<vector<int> >&y){
    vector<vector<int>> ans(2,vector<int>(2,0));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                ans[i][j] +=x[i][k]*y[k][j];
            }
        }
    }
    return ans;
    
    
}
vector<vector<int> > power(vector<vector<int> > x,int n){
    vector<vector<int> > ans(2,vector<int>(2,0));//like when we take power then initally ans=1
    ans[0][0]=ans[1][1]=1;//unit matrix.
    while(n){
        if(n&1){
            ans=mul(ans,x);
        }
        n=n>>1;
        x=mul(x,x);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> x(2,vector<int>(2,1));//transformation matrix
    x[0][0];
    vector<vector<int>>ans=power(x,n-1);
    cout<<ans[1][1];
    
}




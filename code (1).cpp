// Bruteforce approach to solve eular's function.
// defination of eular's function:count all the numbers <=given number(n) such that gcd(i,n)=1
// where 1<=i<=n;
// phi(0)=0;
// phi(1)=1;
#include <bits/stdc++.h>
using namespace std;
bool seive[1000005];
vector<int> p;//it contains all the prime numbers from 1 to 1000005
int Bruteforce_phi(int n){
    int ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans-=ans/i;
        }
        while(n%i==0){
            n/=i;
        }
    }
    if(n>1)
    ans-=ans/n;
    return ans;
}
Time-complexity:0(sqrt(n));
// suppose you have to calculate phi value of more than one number where n is greater than 10^7 so we can't
// use seive method to calculate this.
void calSeive(){
        memset(seive,true,sizeof(seive));
        seive[0]=seive[1]=false;
        for(int i=2;i<1000005;i++){
            if(seive[i]==true){
                p.push_back(i);
                for(int j=2*i;j<1000005;j+=i){
                   seive[j]=false;
                }
            }
        }
}
int phi(int n){
    int ans=n;
    for(int i=0;p[i]*p[i]<=n;i++){
        if(n%p[i]==0){
            ans-=ans/p[i];
        }
        while(n%p[i]==0){
            n/=p[i];
        }
    }
    if(n>1)
    ans-=ans/n;
    return ans;

}
// Time-complexity:0(sqrt(n)/log(n))


int main(){
    
}

#include 

//optimize way to solve eular's funtion in sqrt(n)/log(n)

How can we optimise this in 
#include <bits/stdc++.h>
using namespace std;
int main(){
    calSeive();
    //call Bruteforce_phi
    //call phi
    // ans then comparen time Time-complexity
}
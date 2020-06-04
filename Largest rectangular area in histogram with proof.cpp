/*
Largest rectangular area of histogram.
5|

4|   |

3|   |   |

2|   |   |   |

1|...|...|...|..|
 0   1    2   3  4
 
Approach:
if we consider a rectangle of height x then all the grid which forms the rectangle must be greater
than or equall to x. so lets consider a grid whose height is x.it means that we have to find all
consider all the grids of length greater than or equall to x on the left side as well as on the right side.
or in the other words we have to find the grid on the left side as well as on the right side 
whose height is less than x.

we can efficiently calculate the minimum on both sides using stack data structure.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        stack<ll> s;
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll ans=0,i=0;
        while(i<n){
            if(s.empty() or a[s.top()]<=a[i]){
                s.push(i++);
            }
            else{
                ll temp=s.top();
                s.pop();
                if(s.empty()){
                    ans=max(ans,a[temp]*i);
                }
                else{
                    ans=max(ans,a[temp]*(i-s.top()-1));
                }
            }
        }
        while(!s.empty()){
                ll temp=s.top();
                s.pop();
                if(s.empty()){
                    ans=max(ans,a[temp]*i);
                }
                else{
                    ans=max(ans,a[temp]*(i-s.top()-1));
                }
        }
        cout<<ans<<endl;
    }
}


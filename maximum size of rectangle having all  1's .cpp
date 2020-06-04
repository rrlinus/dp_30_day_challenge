/*Given a binary matrix, Your task is to complete the function maxArea which the maximum size rectangle area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and the next two are two  integers n and m which denotes the size of the matrix M. Your function should return an integer denoting the area of the maximum rectangle .

Input:
The first line of input is an integer T denoting the no of test cases . Then T test cases follow. The first line of each test case are 2 integers n and m denoting the size of the matrix M . Then in the next line are n*m space separated values of the matrix M.

Output:
For each test case output will be the area of the maximum rectangle .

Constraints:
1<=T<=100
1<=n,m<=1000
0<=M[][]<=1

Expected Time Complexity : O(n*m)
Expected Auixilliary Space : O(m)

Example:
Input
1
4 4 
0 1 1 0 1 1 1 1 1 1 1 1 1 1 0 0

Output
8

Explanation
For the above test case the matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8

Approach:this is same as as histogram problem. think for a time.


*/
typedef long long ll;
int maximumAreaHistogram(int a[],int n){
    stack<int> s;
    int ans=0,i=0;
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
        return ans;
}
int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
    int dp[m];
    for(int i=0;i<m;i++){
        dp[i]=M[0][i];
    }
    int ans=maximumAreaHistogram(dp,m);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j])
            dp[j] +=M[i][j];
            else
            dp[j]=0;
        }
        ans=max(ans,maximumAreaHistogram(dp,m));
    }
    
    return ans;
}

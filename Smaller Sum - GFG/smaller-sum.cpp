//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<int>temp;
        temp=arr;
        sort(temp.begin(),temp.end());
        unordered_map<long long int,long long int>m;
        vector<long long int>v;
        long long int s=0;
        for(int i=0;i<n;i++)
        {
            if(!m.count(temp[i])) m[temp[i]]=s;
            s+=temp[i];
        }
        for(int i=0;i<n;i++)
        {
            v.push_back(m[arr[i]]);
        }
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends
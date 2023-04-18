class Solution {
public:
    #include<bits/stdc++.h>
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int n=word1.size(),m=word2.size();
        if(n==0 && m!=0)return word2;
        if(n!=0 && m==0)return word1;
        if(n==0 && m==0)return ans;
        int i=0,j=0;
        while(i<n && j<m){
            ans+=word1[i];
            ans+=word2[j];
            i++;
            j++;
            }
        if(i<n)
            {ans+=word1.substr(i,n-1);
        }
          if(j<m)
            {ans+=word2.substr(j,m-1);
        }
       
        return ans;   
    }
};
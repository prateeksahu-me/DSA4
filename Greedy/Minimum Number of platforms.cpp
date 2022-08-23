#include <bits/stdc++.h>
using namespace std;

int minimumPlatforms(int n,vector<int> &arr,vector<int> &dep){

    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
 
    int ans=1;
    int count=1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j]) //one more platform needed
        {
            count++;
            i++;
        }
        else //one platform can be reduced
        {
            count--;
            j++;
        }
        ans=max(ans,count); //updating the value with the current maximum
    }
    return ans;

}


int main(){
    int n;
    cin>>n;
    vector<int> arrival(n),departure(n);
    for(int i=0;i<n;i++)
    cin>>arrival[i]>>departure[i];
    cout<<minimumPlatforms(n,arrival,departure);
    return 0;
}
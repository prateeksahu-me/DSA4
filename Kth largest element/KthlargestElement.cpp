
#include <bits/stdc++.h>
using namespace std;





class KthLargestElementInAnArray {
public:
    int findKthLargest(vector<int>& arr, int k) {
      
    
    priority_queue<int> pq;
    
    int n = arr.size();
  
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }

    while (k-1) {
        pq.pop();
        k--;
    }
    int ans = pq.top();
    return ans;
    }
};

int main() {
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for ( int i = 0; i < n; i++) cin >> nums[i];
    cin >> k;
    int result = 
    KthLargestElementInAnArray().findKthLargest(nums, k);
    cout << result;
    return 0;
}

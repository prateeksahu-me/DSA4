int findKthSmallest(vector<int>& arr, int k) {
		int result;

        sort(arr.begin(), arr.end())  ;
        int n = arr.size();
        return arr[k - 1];
    }
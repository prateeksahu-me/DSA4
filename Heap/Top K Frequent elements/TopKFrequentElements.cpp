class Solution {
    
public:
    static bool compare(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.second == p2.second)
            return p1.first > p2.first;

        return p1.second > p2.second;
    }   
    vector<int> topKFrequent(vector<int>& arr, int K) {
        
    vector<int> ans;


    int N = arr.size();
     // table
    unordered_map<int, int> mp;
    for (int i = 0; i < N; i++)
        mp[arr[i]]++;
 
    // store the elements of 'mp' in the vector 'freq_arr'
    vector<pair<int, int> > freq_arr(mp.begin(), mp.end());
 
    // Sort the vector 'freq_arr' on the basis of the
    // 'compare' function
    sort(freq_arr.begin(), freq_arr.end(),compare);
 
    // display the top k numbers
    for (int i = 0; i < K; i++)
        ans.push_back(freq_arr[i].first);
    return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;






class compare {
public:
    bool operator() (vector<int>& a,vector<int>& b) {
        return (a[0] *1l *a[0]*1l + a[1]*1l * a[1]*1l) < (b[0]*1l * b[0]*1l + b[1]*1l * b[1]*1l);
    }
};



vector<vector<int>> kClosestPointsToOrigin(vector<vector<int>> points, int k){
    vector<vector<int>> ans;

    priority_queue<vector<int>,vector<vector<int>>,compare> pq;


    for(int i = 0 ; i< points.size();i++)
    {
        pq.push(points[i]);
        if(pq.size()>k)
        {
            pq.pop();
        }
    }


    for(int i = 0 ; i< k;i++)
    {
        ans.push_back(pq.top());
        pq.pop();
    }


    return ans;
}


int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }

    vector<vector<int>> closestPoints = kClosestPointsToOrigin(points, k);
    for (auto point : closestPoints)
    {
        for (auto value : point)
        {
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
#define rep(start,end,gap) for(int i=start;i<end;i+=gap)
#define repV(start,end,gap) for(int i=end;i>=start;i-=gap)
using namespace std;
// const int MAX = 100500;
vector<vector<int>> tree;

vector<int>& comb(vector<int>& left, vector<int>& right)
{
    vector<int> ans;
    int i = 0, j = 0;
    while(i < left.size() && j < right.size())
    {
        if(left[i] <= right[j])
        {
            ans.emplace_back(left[i]);
            i++;
        }
        else {
            ans.emplace_back(right[j]);
            j++;
        }
    }

    while
            (i < left.size())
        ans.emplace_back(left[i++]);
    while
            (j < right.size())
        ans.emplace_back(right[j++]);
    
    return ans;
}

void build(int treeIndex,int start, int end, vector<int>& arr){

    if(start ==  end)
    {
        // leaf node
        tree[treeIndex].emplace_back(arr[start]);
        return;
    }

    int mid = (start + end)/2;
    build(treeIndex * 2 + 1, start, mid, arr);
    build(treeIndex * 2 + 2, mid + 1, end, arr);

    // combining part
    vector<int> left = tree[treeIndex * 2 + 1];
    vector<int> right = tree[treeIndex * 2 + 2];

    vector<int> comb(left, right);
    tree[treeIndex] = 
}

vector<int> query(int treeIndex, int Tstart, int Tend, int Qstart, int Qend){
    if(Tstart > Qend  || Tend < Qstart)
    {
        vector<int> v;
        return v;
    }
    
    if(Qstart <= Tstart && Tend <= Qend){
        return tree[treeIndex];
    }
    
    int mid = (Tstart + Tend)/2;
    vector<int> left = query(treeIndex * 2 + 1, Tstart, mid, Qstart, Qend);
    vector<int> right = query(treeIndex * 2 + 2, mid+1, Tend, Qstart, Qend);
    
    //combine
    return comb(left, right);
}

initialize_building_tree(...build parameters) {
    tree.resize(cost.size() * 4, vector<int>(0));
    build(...build parameters);
}

void euler(vector<int> &tour, int node, vector<vector<int>> & tree, int &index, map<int, pair<int, int>>& startEnd, bool vis[]){
    tour.emplace_back(node);
    startEnd[node].first = index;
    index++;
    vis[node] = true;
    for(int child: tree[node])
    {
        if(!vis[child])
            euler(tour, child, tree, index, startEnd, vis);
    }
    startEnd[node].second = index-1;
}

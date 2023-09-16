class Solution
{
public:
    const int MAX = 1e4 + 5;
    int id[100005];
    struct Node
    {
        int src, dest, wt;
        bool operator()(Node i, Node j)
        {
            return (i.wt < j.wt);
        }
    } node;
    void initialize()
    {
        for (int i = 0; i < MAX; ++i)
            id[i] = i;
    }
    int root(int x)
    {
        while (id[x] != x)
        {
            id[x] = id[id[x]];
            x = id[x];
        }
        return x;
    }
    void union1(int x, int y)
    {
        int p = root(x);
        int q = root(y);
        id[p] = id[q];
    }
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int total_dist = 0, curr_dist, no_of_points = points.size(), src, dest, wt;
        vector<Node> graph;
        initialize();
        if (no_of_points == 1)
        {
            return 0;
        }
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = 0; j < points.size(); j++)
            {
                if (i != j)
                {
                    curr_dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    graph.push_back({i, j, curr_dist});
                }
            }
        }
        // for(int i=0; i<no_of_points; i++){
        //     cout<<graph[i].src<<" "<<graph[i].dest<<" "<<graph[i].wt<<endl;
        // }
        sort(graph.begin(), graph.end(), node);
        for (int i = 0; i < graph.size(); i++)
        {
            src = graph[i].src;
            dest = graph[i].dest;
            wt = graph[i].wt;
            if (root(src) != root(dest))
            {
                total_dist += wt;
                union1(src, dest);
            }
        }
        return total_dist;
    }
};
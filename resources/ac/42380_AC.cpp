// _Z3Dfsi mL
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int k, n, r;

int sL, sT, mL;

int mem[101][10001];

class Node
{
public:
    int D, L, T;
    Node(int _D, int _L, int _T) :
        D(_D), L(_L), T(_T)
    {}
    ~Node()
    {}
};

int vis[200];

std::vector<Node> v[200];

void Dfs(int p)
{
    if (vis[p])
        return ;
    if (sT > k)
        return ;
    if (sL >= mL)
        return ;
    if (sL >= mem[p][sT])
        return ;
    if (p == n - 1)
    {
        mL = sL;
        return ;
    }
    mem[p][sT] = sL;
    vis[p] = 1;
    for (Node n : v[p])
    {
        sT += n.T;
        sL += n.L;
        Dfs(n.D);
        sT -= n.T;
        sL -= n.L;
    }
    vis[p] = 0;
    return ;
}

int main(int argc, const char* argv[])
{
    std::cin >> k >> n >> r;
    for (int i = 0; i < r; i++)
    {
        int s, d, l, t;
        std::cin >> s >> d >> l >> t;
        v[s-1].push_back(Node(d-1, l, t));
    }
    sL = 0;
    sT = 0;
    mL = INT_MAX >> 1;
    for (int i = 0; i < n; i++)
        vis[i] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++)
            mem[i][j] = INT_MAX >> 1;
    Dfs(0);
    if (mL == INT_MAX >> 1)
        std::cout << -1 << std::endl;
    else
        std::cout << mL << std::endl;
    return 0;
}

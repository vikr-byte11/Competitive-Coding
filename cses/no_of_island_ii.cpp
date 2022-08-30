#include <bits/stdc++.h>
using namespace std;
int p[100000];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
int index(int x, int y, int m)
{
    return x * m + y;
}
vector<int> numIslands2(int n, int m, vector<pair<int, int>> &operators)
{
    if (operators.empty())
        return {};

    vector<int> res;
    int s = operators.size();
    unordered_set<int> current;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int total = 0;
    for (int i = 0; i < s; i++)
    {
        int pos = index(operators[i].first, operators[i].second, m);
        if (current.count(pos))
        {
            res.push_back(total);
            continue;
        }
        total++;
        p[pos] = pos;
        for (int j = 0; j < 4; j++)
        {
            int nx = operators[i].first + dx[j];
            int ny = operators[i].second + dy[j];
            if (!(nx >= 0 && nx < n && ny >= 0 && ny < m))
                continue;
            if (current.count(index(nx, ny, m)))
            {
                int apos = index(operators[i].first, operators[i].second, m);
                int bpos = index(nx, ny, m);
                if (find(apos) != find(bpos))
                {
                    p[find(apos)] = find(bpos);
                    total--;
                }
            }
        }

        current.insert(index(operators[i].first, operators[i].second, m));
        res.push_back(total);
    }

    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for (auto &x : vp)
        cin >> x.first >> x.second;
    auto ans = numIslands2(4, 5, vp);
    for (auto x : ans)
        cout << x << " ";
}
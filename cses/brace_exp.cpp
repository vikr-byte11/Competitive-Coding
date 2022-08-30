#include <bits/stdc++.h>
using namespace std;
vector<string> ff(int &idx, string s, bool f)
{
    if (idx == s.size())
    {
        return {};
    }
    //no nested bracket
    //f=true means there was no op bracket before so no comma
    string tmp = "";
    int n = s.size();
    if (f)
    {
        while (idx < n and s[idx] != '{')
            tmp += s[idx++];
        idx++;
        vector<string> st = ff(idx, s, false);
        vector<string> ans;
        //cout<<tmp<<endl;
        //for(auto x:st)
        // cout<<x<<" ";
        // cout<<endl;
        for (auto x : st)
            ans.push_back(tmp + x);
        //for(auto x:ans)
        // cout<<x<<" ";
        // cout<<endl;
        return ans;
    }
    //there was an openeing bracket before
    //so comma will be here

    vector<string> cc;
    string x;
    while (idx < n and s[idx] != '}')
    {
        if (s[idx] == ',')
        {
            cc.push_back(x);
            x = "";
            idx++;
            continue;
        }
        x += s[idx];
        idx++;
    }
    cc.push_back(x);
    idx++;
    vector<string> no = ff(idx, s, true);
    vector<string> ans;
    if (no.size() == 0)
        return cc;
    for (auto x : cc)
    {
        for (auto y : no)
            ans.push_back(x + y);
    }
    // for(auto x:ans)
    //  cout<<x<<" ";
    //  cout<<endl;

    return ans;
}
void fun(string s, int n)
{
    string tmp = "";
    int idx = 0;
    auto see = ff(idx, s, true);
    for (auto x : see)
        cout << x << " ";
}
int main()
{
    string s;
    cin >> s;
    fun(s, s.size());
}
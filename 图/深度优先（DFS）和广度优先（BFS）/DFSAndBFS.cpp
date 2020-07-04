#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>

using namespace std;

void DFS(map<string, vector<string>> m, string begin)
{
    set<string> save;

    stack<string> arrived;

    if (m.find(begin) == m.end())
    {
        return;
    }

    arrived.push(begin);
    save.insert(begin);

    while (!arrived.empty())
    {
        string pos = arrived.top();
        arrived.pop();

        if (m.find(pos) != m.end())
        {
            cout << pos << " ";
            for (auto i : m[pos])
            {
                if (save.find(i) == save.end())
                {
                    arrived.push(i);
                    save.insert(i);
                }
            }
        }
    }
    cout << endl;

}

void BFS(map<string, vector<string>> m, string begin)
{
    set<string> save;

    queue<string> arrived;

    if (m.find(begin) == m.end())
    {
        return;
    }

    arrived.push(begin);
    save.insert(begin);

    while (!arrived.empty())
    {
        string pos = arrived.front();
        arrived.pop();

        if (m.find(pos) != m.end())
        {
            cout << pos << " ";
            for (auto i : m[pos])
            {
                if (save.find(i) == save.end())
                {
                    arrived.push(i);
                    save.insert(i);
                }
            }
        }
    }
    cout << endl;

}

int main(int argc, char const *argv[])
{
    
    map<string, vector<string>> m;

    m["A"] = {"B", "C", "F"};
    m["B"] = {"A", "D", "E"};
    m["C"] = {"A", "F"};
    m["D"] = {"B", "E", "G"};
    m["E"] = {"B", "D"};
    m["F"] = {"A", "C"};
    m["G"] = {"D"};

    DFS(m, "A");
    BFS(m, "A");

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

class LinkedList 
{
public:
    int value;
    LinkedList *next;

    LinkedList()
    {
        next = nullptr;
    }
};

pair<LinkedList*, LinkedList*> create_linked_list(int n, int h1, int h2, vector<pair<int,int>> &edges)
{
    vector<LinkedList*> a(n, nullptr);
    for(int i=0; i<n; i++)
    {
        a[i] = new LinkedList();
        a[i] -> value = i;
    }
    
    for(auto &p: edges)
    {
        a[p.first]->next = a[p.second];
    }

    return {a[h1], a[h2]};
}

int main()
{
    int n, m, h1, h2;
    cin >> n >> m >> h1 >> h2;
    
    vector<pair<int,int>> edges;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    pair<LinkedList*, LinkedList*> heads = create_linked_list(n, h1,h2, edges);

    LinkedList* head_1 = heads.first;
    LinkedList* head_2 = heads.second;

    // DONT CHANGE ABOVE THIS use head_1 and head_2 as two linkedlist heads

    vector<int>arr;
    LinkedList *a = head_1;
    LinkedList *b = head_2;
    while(a != b)
    {
        if (a) a = a->next;
        else a = head_2;
        if (b) b = b->next;
        else b = head_1; 
    }
    if (a != NULL) cout << a->value << endl;
    else cout << -1 << endl;;
    return 0;
}

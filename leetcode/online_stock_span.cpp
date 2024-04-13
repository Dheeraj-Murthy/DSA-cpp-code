#include<bits/stdc++.h>
using namespace std;

using namespace std;
class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int, int>>stk;
    int next(int price) {
        int span = 1;
        while(!stk.empty() && stk.top().second <= price)
        {
            span += stk.top().first;
            stk.pop();
        }
        stk.push({span, price});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
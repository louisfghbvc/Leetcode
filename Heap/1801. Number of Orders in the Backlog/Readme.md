# [1801. Number of Orders in the Backlog](https://leetcode.com/problems/number-of-orders-in-the-backlog/)

###### tags: `leetcode` `medium` `heap` `simulate`

[TOC]

## Description
You are given a 2D integer array orders, where each orders[i] = [pricei, amounti, orderTypei] denotes that amounti orders have been placed of type orderTypei at the price pricei. The orderTypei is:

0 if it is a batch of buy orders, or
1 if it is a batch of sell orders.
Note that orders[i] represents a batch of amounti independent orders with the same price and order type. All orders represented by orders[i] will be placed before all orders represented by orders[i+1] for all valid i.

There is a backlog that consists of orders that have not been executed. The backlog is initially empty. When an order is placed, the following happens:

If the order is a buy order, you look at the sell order with the smallest price in the backlog. If that sell order's price is smaller than or equal to the current buy order's price, they will match and be executed, and that sell order will be removed from the backlog. Else, the buy order is added to the backlog.
Vice versa, if the order is a sell order, you look at the buy order with the largest price in the backlog. If that buy order's price is larger than or equal to the current sell order's price, they will match and be executed, and that buy order will be removed from the backlog. Else, the sell order is added to the backlog.
Return the total amount of orders in the backlog after placing all the orders from the input. Since this number can be large, return it modulo 109 + 7.



## Way1 - Two Heap

```cpp
class Solution {
public:
    
    typedef pair<int, int> ii;
    
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        // goal: find the total number of backlog orders
        // idea: simulate
        // maintain minheap, and maxheap
        
        priority_queue<ii, vector<ii>, greater<>> sell; // {price, amount}
        priority_queue<ii> buy; // {price, amount}
        
        for (auto &it: orders) {
            int price = it[0], num = it[1];
            int t = it[2];
            if (t == 0) { // buy
                while (sell.size() && sell.top().first <= price && num) {
                    auto [sell_price, amount] = sell.top(); sell.pop();
                    int take = min(amount, num);
                    num -= take;
                    amount -= take;
                    if (amount)
                        sell.push({sell_price, amount});
                }
                if (num)
                    buy.push({price, num});
            }
            else {
                while (buy.size() && buy.top().first >= price && num) {
                    auto [buy_price, amount] = buy.top(); buy.pop();
                    int take = min(amount, num);
                    num -= take;
                    amount -= take;
                    if (amount)
                        buy.push({buy_price, amount});
                }
                if (num)
                    sell.push({price, num});
            }
        }
        
        int mod = 1e9+7;
        int total = 0;
        while (sell.size()) {
            total = (total + sell.top().second) % mod;
            sell.pop();
        }
        while (buy.size()) {
            total = (total + buy.top().second) % mod;
            buy.pop();
        }
        return total;
    }
};
```

## Way2 - use Marco (C style)

```cpp
class Solution {
public:
    
    typedef pair<int, int> ii;
    
    #define operations(pq, price, num, ops) \
    while (pq.size() && pq.top().first ops price && num) { \
        auto [_price, amount] = pq.top(); pq.pop(); \
        int take = min(amount, num); \
        num -= take; \
        amount -= take; \
        if (amount) \
            pq.push({_price, amount}); \
     } \
    
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        // goal: find the total number of backlog orders
        // idea: simulate
        // maintain minheap, and maxheap
        
        priority_queue<ii, vector<ii>, greater<>> sell; // {price, amount}
        priority_queue<ii> buy; // {price, amount}
        
        for (auto &it: orders) {
            int price = it[0], num = it[1];
            int t = it[2];
            if (t == 0) { // buy
                operations(sell, price, num, <=);
                if (num)
                    buy.push({price, num});
            }
            else {
                operations(buy, price, num, >=);
                if (num)
                    sell.push({price, num});
            }
        }
        
        int mod = 1e9+7;
        int total = 0;
        while (sell.size()) {
            total = (total + sell.top().second) % mod;
            sell.pop();
        }
        while (buy.size()) {
            total = (total + buy.top().second) % mod;
            buy.pop();
        }
        return total;
    }
};
```

## Way3 - Template

```cpp
class Solution {
public:
    
    typedef pair<int, int> ii;
     
    template<typename T, typename F>
    void operations(T &pq, int &price, int &num, F &&compartor) {
        while (pq.size() && compartor(pq.top().first, price) && num) { 
            auto [_price, amount] = pq.top(); pq.pop(); 
            int take = min(amount, num); 
            num -= take; 
            amount -= take; 
            if (amount) 
                pq.push({_price, amount}); 
        }
    }
    
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        // goal: find the total number of backlog orders
        // idea: simulate
        // maintain minheap, and maxheap
        
        priority_queue<ii, vector<ii>, greater<>> sell; // {price, amount}
        priority_queue<ii> buy; // {price, amount}
        
        for (auto &it: orders) {
            int price = it[0], num = it[1];
            int t = it[2];
            if (t == 0) { // buy
                operations(sell, price, num, less_equal<int>());
                if (num)
                    buy.push({price, num});
            }
            else {
                operations(buy, price, num, greater_equal<int>());
                if (num)
                    sell.push({price, num});
            }
        }
        
        int mod = 1e9+7;
        int total = 0;
        while (sell.size()) {
            total = (total + sell.top().second) % mod;
            sell.pop();
        }
        while (buy.size()) {
            total = (total + buy.top().second) % mod;
            buy.pop();
        }
        return total;
    }
};
```

## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(nlogn) | O(n) |
| Way2 | O(nlogn) | O(n) |
| Way3 | O(nlogn) | O(n) |



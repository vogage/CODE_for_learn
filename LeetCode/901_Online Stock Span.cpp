//
//  901_Online Stock Span.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/23.
//

#include <stdio.h>
#include <vector>

using namespace std;

class StockSpanner {
public:
    StockSpanner() {
       
    }
    
    int next(int price) {
        int index=stocks.size();
        int span=1;
        while(span<=index&&stocks[index-span].first<price){
            span+=stocks[index-span].second;
        }
        stocks.push_back({price,span});
        return stocks.back().second;
    }
private:
    vector<pair<int,int>> stocks;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main(){
//    Input
//    ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
//    [[], [100], [80], [60], [70], [60], [75], [85]]
//    Output
//    [null, 1, 1, 1, 2, 1, 4, 6]
    StockSpanner *obj=new StockSpanner();
    int res1=obj->next(100);
    int res2=obj->next(80);
    int res3=obj->next(60);
    int res4=obj->next(70);
    int res5=obj->next(60);
    int res6=obj->next(75);
    int res7=obj->next(85);
    return 0;
}

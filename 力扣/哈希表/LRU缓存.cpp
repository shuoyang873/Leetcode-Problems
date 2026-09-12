/*
146. LRU 缓存
已解答
中等
相关标签
premium lock icon
相关企业
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

 

示例：

输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4
 

提示：

1 <= capacity <= 3000
0 <= key <= 10000
0 <= value <= 105
最多调用 2 * 105 次 get 和 put
*/


#include<bits/stdc++.h>
using namespace std;

struct DLink{
    int key,val;
    DLink*prev;
    DLink*next;
    DLink():key(0),val(0),prev(nullptr),next(nullptr){}
    DLink(int _key,int _val):key(_key),val(_val),prev(nullptr),next(nullptr){}
};


class LRUCache {
private:
    int size,cap;
    DLink*head;
    DLink*tail;
    unordered_map<int,DLink*>lru;
public:
    LRUCache(int capacity) {
        size=0;
        cap=capacity;
        head=new DLink;
        tail=new DLink;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(!lru.count(key)){
            return -1;
        }
        DLink*node=lru[key];
        move_to_head(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(lru.count(key)){
            lru[key]->val=value;
            move_to_head(lru[key]);
        }
        else{
            DLink*node=new DLink(key,value);
            add_to_head(node);
            lru[key]=node;
            size++;
            if(size>cap){
                DLink*remove_node=delete_tail();
                lru.erase(remove_node->key);
                delete remove_node;
                size--;
            }
        }
    }

    void add_to_head(DLink*node){
        head->next->prev=node;
        node->prev=head;
        node->next=head->next;
        head->next=node;
    }

    DLink* delete_tail(){
        DLink*node=tail->prev;
        node->prev->next=tail;
        tail->prev=node->prev;
        return node;
    }

    void delete_node(DLink*node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    void move_to_head(DLink*node){
        delete_node(node);
        add_to_head(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
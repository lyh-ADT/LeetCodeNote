#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct UFSNode{
    int data;
    int rank;
    int parent;
};

void init_set(vector<UFSNode>& ufs){
    for(int i=0; i < ufs.size(); ++i){
        ufs[i].data = i;   // 该题可以直接用下标表示节点编号
        ufs[i].parent = i; // 所有节点初始化为独立的，自己是自己的parent
        ufs[i].rank = 1;   // 只有1层
    }
}

int find_set(vector<UFSNode> const&  ufs, int curNode){
    // 找出该节点所处的集合的parent
    if (ufs[curNode].parent == curNode){
        return curNode;
    } else {
        return find_set(ufs, ufs[curNode].parent);
    }
}

int union_set(vector<UFSNode> & ufs, int node1, int node2){
    // 将两个节点所处的集合合并，返回合并后的集合
    int x = find_set(ufs, node1); // node1所属的集合
    int y = find_set(ufs, node2); // node2所属的集合
    if(ufs[x].rank > ufs[y].rank){
        ufs[y].parent = x;
    } else {
        ufs[x].parent = y;
        if(ufs[x].rank == ufs[y].rank){
            ufs[y].rank++;
        }
    }
    return ufs[x].parent;
}

map<int, vector<int>> log_set(vector<UFSNode> const& ufs){
    map<int, vector<int>> m;
    for(UFSNode const& i : ufs){
        int x = find_set(ufs, i.data);
        m[x].push_back(i.data);
    }
    return m;
}


int main(){
    /* 
    输入一个正整数N，表示有多少个节点
    接下来每行两个编号，表示他们之间有关系
    生成并查集 
    */
    int N = 10;
    vector<vector<int>> relations = {
        {2,4},
        {5,7},
        {1,3},
        {8,9},
        {1,2},
        {5,6},
        {2,3}
    };

    vector<UFSNode> ufs(N+1);
    init_set(ufs);

    for(vector<int>& i : relations){
        union_set(ufs, i[0], i[1]);
    }

    for(auto& i : log_set(ufs)){
        cout << i.first << ":" << endl;
        for(int& j : i.second){
            cout << "   " << j;
        }
        cout << endl;
    }

    return 0;
}
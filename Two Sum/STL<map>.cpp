#include<iostream>
#include<map>

using namespace std;

int main(){
    //声明
    map<char, int> m;

    //使用insert赋值
    m.insert(pair<char, int>('c', 18));

    //直接赋值
    m['a'] = 13;

    //访问
    cout << "m['c']=" << m['c'] << endl;

    //遍历
    map<char, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); ++iter){
        cout << "m['" << iter->first << "']=" << iter->second << endl;
    }

    return 0;
}

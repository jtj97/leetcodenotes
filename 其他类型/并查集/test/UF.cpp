#include<iostream>
#include<vector>
using namespace std;




//并查集
class UF{
private:
    vector<int> parent; //父节点
    int provinceNum;
public:
    //构造函数
    UF() = default;
    UF(int n){
        parent = vector<int>(n);
        for(int i=0; i<n; ++i){
            parent[i] = i;
        }
        provinceNum = n;
        cout<<"init correct"<<endl;
    }
    //查(父节点)
    int find(int x){
        //路径优化
        while(x!=parent[x]){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    // 并
    void unionParent(int x, int y){
        int f1 = find(x);
        int f2 = find(y);
        if(f1!=f2){
            parent[f1] = f2;
            --provinceNum;
        }
        return;
    }
    // 查询省份数量
    int findProvinceNum(){
        return provinceNum;
    }
};

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    UF uf1(n);
    for(int i=n-1; i>=0; --i){
        for(int j=i; j<n; ++j){
            if(isConnected[i][j]==1){
                uf1.unionParent(i, j);
            }
        }
    }
    return uf1.findProvinceNum();
}

int main(){
    vector<vector<int>> test1 = {{1,1,0},{1,1,0},{0,0,1}};
    int result = findCircleNum(test1);
    cout<<result<<endl;
    return 0;
}
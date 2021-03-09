#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void buildGraph(map<string,map<string,int>>& Graph,const vector<string>& p1,const vector<string>& p2,const vector<int>& dist){
    if(p1.size()!=p2.size()&&p1.size()!=dist.size()){
        cout<<"building error, edge is incorrect"<<endl;
        return;
    }
    if(p1.empty()){
        cout<<"no edges input"<<endl;
    }
    int num = p1.size();
    while(num--){
        Graph[p1[num]].insert({p2[num],dist[num]});
    }
}
void printGraph(map<string,map<string,int>>& Graph){
    cout<<"**********Graph**********"<<endl;
    for(auto iter = Graph.begin(); iter!=Graph.end(); iter++){
        cout<<"edge: "<<iter->first<<" -> ";
        for(auto ele : iter->second){
            cout<<ele.first<<':'<<ele.second<<' ';
        }
        cout<<endl;
    }
    cout<<"**********Graph**********"<<endl;
}
map<string,string> BFS(map<string,map<string,int>>& Graph,string vertex){
//    判断顶点是否合法
    if(!Graph.count(vertex)){
        cout<<"Start vertex not exist"<<endl;
        return map<string,string>();
    }
    set<string> visited;
    map<string, string> path;
    queue<string> q;
//    插入起始路径
    path.insert({vertex,"null"});
//    起始节点入队
    q.push(vertex);
    visited.insert(vertex);
    while(!q.empty()){
//        出队
        string p = q.front();
        q.pop();
//        访问
        cout<<"pop："<<p<<endl;
//        bfs继续插入未访问的节点
        for(auto ele:Graph[p]){
//            查看是否访问过
            if(visited.count(ele.first)) continue;
//            添加访问节点
            visited.insert(ele.first);
//            添加路径
            path.insert({ele.first,p});
//            当前vertex入队
            q.push(ele.first);
        }
    }
    cout<<endl;
    return path;
}
map<string,string> DFS(map<string,map<string,int>>& Graph,string vertex){
//    判断顶点是否合法
    if(!Graph.count(vertex)){
        cout<<"Start vertex not exist"<<endl;
        return map<string,string>();
    }
    set<string> visited;
    map<string, string> path;
    stack<string> q;
//    插入起始路径
    path.insert({vertex,"null"});
//    起始节点入栈
    q.push(vertex);
    visited.insert(vertex);
    while(!q.empty()){
//        出栈
        string p = q.top();
        q.pop();
//        访问
        cout<<"pop："<<p<<endl;
//        dfs继续插入未访问的节点
        for(auto ele:Graph[p]){
//            查看是否访问过
            if(visited.count(ele.first)) continue;
//            添加访问节点
            visited.insert(ele.first);
//            添加路径
            path.insert({ele.first,p});
//            当前vertex入栈
            q.push(ele.first);
        }
    }
    cout<<endl;
    return path;
}
map<string,int> dijkstra(map<string,map<string,int>>& Graph,string vertex){
//    判断顶点是否合法
    if(!Graph.count(vertex)){
        cout<<"Start vertex not exist"<<endl;
        return map<string,int>();
    }
    set<string> visited;
    map<string, int> dist;
    auto cmp = [](pair<string, int> a,pair<string, int> b){
        return a.second>b.second;
    };
    priority_queue<pair<string,int>,vector<pair<string,int>>,decltype(cmp)> pqueue(cmp);
//    插入起始路径
    dist.insert({vertex,0});
//    起始节点入队
    pqueue.push({vertex,0});
    while(!pqueue.empty()){
//        出队
        pair<string,int> p = pqueue.top();
        pqueue.pop();
//        出队时标记当前节点已访问
        cout<<"pop: "<<p.first<<' ';
        visited.insert(p.first);
//        bfs继续插入未访问的节点
        for(auto ele:Graph[p.first]){
            if(visited.count(ele.first))continue;
//            若存在则更新距离否则插入
            if(dist.count(ele.first)){
//                当原本路径更长时更新路径
                if(dist[ele.first] > ele.second+p.second){
                    dist[ele.first] = ele.second+p.second;
                }

            }else{
                dist.insert({ele.first,ele.second+p.second});
            }
            pqueue.push({ele.first,dist[ele.first]});
        }
    }
    cout<<endl;
    return dist;
}
template<typename T>
void printPath(map<string,T> path){
    for(pair<string,T> kv:path){
        cout<<kv.first<<'\t';
    }
    cout<<endl;
    for(pair<string,T> kv:path){
        cout<<kv.second<<'\t';
    }
    cout<<endl;
}
int main(){
    map<string,map<string,int>> Graph;
    buildGraph(Graph
               ,{"a","a","b","b","b","c","c","c","c","d","d","d","d","e","e","f"}
               ,{"b","c","a","c","d","a","b","d","e","b","c","e","f","c","d","d"}
               ,{5  ,1  ,5  ,2  ,1  ,1  ,2  ,4  ,8  ,1  ,4  ,3  ,6  ,8  ,3  ,6});
    printGraph(Graph);
    printPath(dijkstra(Graph,"b"));
    return 0;
}

//map<string,map<string,int>>& Graph

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
//    �ж϶����Ƿ�Ϸ�
    if(!Graph.count(vertex)){
        cout<<"Start vertex not exist"<<endl;
        return map<string,string>();
    }
    set<string> visited;
    map<string, string> path;
    queue<string> q;
//    ������ʼ·��
    path.insert({vertex,"null"});
//    ��ʼ�ڵ����
    q.push(vertex);
    visited.insert(vertex);
    while(!q.empty()){
//        ����
        string p = q.front();
        q.pop();
//        ����
        cout<<"pop��"<<p<<endl;
//        bfs��������δ���ʵĽڵ�
        for(auto ele:Graph[p]){
//            �鿴�Ƿ���ʹ�
            if(visited.count(ele.first)) continue;
//            ��ӷ��ʽڵ�
            visited.insert(ele.first);
//            ���·��
            path.insert({ele.first,p});
//            ��ǰvertex���
            q.push(ele.first);
        }
    }
    cout<<endl;
    return path;
}
map<string,string> DFS(map<string,map<string,int>>& Graph,string vertex){
//    �ж϶����Ƿ�Ϸ�
    if(!Graph.count(vertex)){
        cout<<"Start vertex not exist"<<endl;
        return map<string,string>();
    }
    set<string> visited;
    map<string, string> path;
    stack<string> q;
//    ������ʼ·��
    path.insert({vertex,"null"});
//    ��ʼ�ڵ���ջ
    q.push(vertex);
    visited.insert(vertex);
    while(!q.empty()){
//        ��ջ
        string p = q.top();
        q.pop();
//        ����
        cout<<"pop��"<<p<<endl;
//        dfs��������δ���ʵĽڵ�
        for(auto ele:Graph[p]){
//            �鿴�Ƿ���ʹ�
            if(visited.count(ele.first)) continue;
//            ��ӷ��ʽڵ�
            visited.insert(ele.first);
//            ���·��
            path.insert({ele.first,p});
//            ��ǰvertex��ջ
            q.push(ele.first);
        }
    }
    cout<<endl;
    return path;
}
map<string,int> dijkstra(map<string,map<string,int>>& Graph,string vertex){
//    �ж϶����Ƿ�Ϸ�
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
//    ������ʼ·��
    dist.insert({vertex,0});
//    ��ʼ�ڵ����
    pqueue.push({vertex,0});
    while(!pqueue.empty()){
//        ����
        pair<string,int> p = pqueue.top();
        pqueue.pop();
//        ����ʱ��ǵ�ǰ�ڵ��ѷ���
        cout<<"pop: "<<p.first<<' ';
        visited.insert(p.first);
//        bfs��������δ���ʵĽڵ�
        for(auto ele:Graph[p.first]){
            if(visited.count(ele.first))continue;
//            ����������¾���������
            if(dist.count(ele.first)){
//                ��ԭ��·������ʱ����·��
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

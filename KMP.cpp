#include <bits/stdc++.h>
using namespace std;
vector<int> getNext(string & needle) {
    if (!needle.size()) return {};
    vector<int> next(needle.size(), 0);
    next.shrink_to_fit();
    for(int i = 1, j = 0; i < needle.size() - 1; i++) {
        // 匹配不上j往前回退
        while (j > 0 && needle[i] != needle[j]) {
            j = next[j - 1]; // KMP式回退，思想就是KMP的匹配思想。好家伙求next数组也用上KMP的回退思想了。
        }
        // 和当前下标匹配上了，需要j+1,表示在i时匹配不上需要去j+1的地方重新匹配。
        // 当needle[i] != needle[j]时其实j就是0了，表示需要重头匹配。
        if (needle[i] == needle[j]) {
            j++;
        }
        next[i] = j;
    }
    return next;
}
template<typename T>
void printArr(T next) {
    for (auto a: next) {
        cout << a << ' ';
    }
    cout << endl;
}
int KMPSearch(string & s, string & p, vector<int> & next){
    int ls = s.size();
    int lp = p.size();
    if (lp > ls) return -1;
    if (!lp) return 0;
    for (int i = 0, j = 0; i < ls; i++) {
        if (ls - i < lp -j) { // 剩余的匹配串不够长
            break;
        }
        while (j > 0 && s[i] != p[j]) {
            j = next[j - 1];
        }
        if (s[i] == p[j]) {
            j++;
        }
        if (j == lp) {
            return i - lp + 1;
        }
    }
    return -1;
}
int strStr(string haystack, string needle) {
    vector<int> next = getNext(needle);
    next.shrink_to_fit();
    // printArr(next);
    return KMPSearch(haystack, needle, next);
}
int main(){
    cout << strStr("hello","ll");
    return 0;
}
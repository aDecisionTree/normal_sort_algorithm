#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
vector<string> letterCombinations(string digits) {
    vector<string> results;
    for(int i=0 ; i<digits.size() ; i++){
        digits[i]-=2;
    }
    char ch[8][4]={
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'}
        };
    int total=1;
    for(int i=0 ; i<digits.size() ; i++){
        switch(digits[i]){
            case'5':
            case'7':
                total*=4;
                break;
            default:
                total*=3;
        }
    }
//    cout<<total<<endl;

    int times=1;
    for(int i=0 ; i<digits.size() ; i++){ // 每次循环加一列
        int len=0;
        if(digits[i]-'0'!=5&&digits[i]-'0'!=7)
            len=3;
        else
            len=4;

        if(i!=0){
            switch(digits[i-1]){
                case'5':
                case'7':
                    times*=4;
                    break;
                default:
                    times*=3;
            }
        }
        int call = total/len/times;
//        cout<<"i : "<<i<<endl;
//        cout<<digits[i]<<' '<<len<<' '<<times<<' '<<call<<endl;
        for(int j=0 ; j<call ; j++){
            for(int l=0 ; l<len ; l++)
                for(int k=0 ; k<times ; k++){
                    if(i==0){
                        string s = "";
                        results.push_back(s+ch[digits[i]-'0'][l]);
                    }else{
//                        cout<<j*(len*times)+l*times+k<<endl;
                        results[j*(len*times)+l*times+k]+=ch[digits[i]-'0'][l];
                    }
                }
        }
//        for(auto result:results){
//            cout<<result<<endl;
//        }
//        cout<<"result size :"<<results.size()<<endl;
    }

    return results;
}
int main(){
    string digits = "5678";
    auto results = letterCombinations(digits);

    for(auto result:results){
        cout<<result<<endl;
    }

    return 0;
}

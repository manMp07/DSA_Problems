#include<bits/stdc++.h>
using namespace std;

//Que.- https://parikh.club/parikh_sliding4

/***Using Map***/
//Time : O(N) --> This is average complexity as (strMap == ptrMap) has avg = O(1),
//                so in some case it gets O(N*N)
//Space : O(1); at max map.size()=26

vector<int> findAnagramsIndices(string str, string ptr, int n, int m){
    unordered_map<char, int> strMap; //<char, count>
    unordered_map<char, int> ptrMap;

    for(int i = 0; i < ptr.length(); i++){
        strMap[str[i]]++;
        ptrMap[ptr[i]]++;
    }

    int i = 0, j = ptr.length();
    vector<int> ans;

    while(j < str.length()) {
        if(strMap == ptrMap)
            ans.push_back(i);

        strMap[str[j]]++;
        j++;

        if(strMap[str[i]] == 1)
            strMap.erase(str[i]);
        else
            strMap[str[i]]--;
        i++;
    }
    if(strMap == ptrMap)
        ans.push_back(i);

    return ans;
}

/***Using Vector***/
//Time : O(N)
//Space : O(1)

vector<int> findAnagramsIndices(string str, string ptr, int n, int m){

    vector<int> strMap(26, 0);
    vector<int> ptrMap(26, 0);

    for(int i = 0; i < ptr.length(); i++){
        strMap[str[i] - 'A']++;
        ptrMap[ptr[i] - 'A']++;
    }

    int i = 0, j = ptr.length();
    vector<int> ans;

    while(j < str.length()) {
        if(strMap == ptrMap)
            ans.push_back(i);

        strMap[str[j] - 'A']++;
        j++;

        strMap[str[i] - 'A']--;
        i++;
    }
    if(strMap == ptrMap)
        ans.push_back(i);

    return ans;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout); 
    int T,N,M,store=0;    cin >> T >> N >> M;
    vector<pair<int,int>> limit;    vector<pair<int,int>> achieve;

    for(int i=0;i<N;i++){
        int temp,temp1;       cin >> temp >> temp1;    
        limit.push_back(make_pair(store+temp,temp1));    
        store=store+temp;
    }
    //PRINT THE LIMIT
    //cout << "LIMIT\n";
    //for(auto i:limit){cout << i.first << " " << i.second << "\n";}

    store=0;
    for(int i=0;i<M;i++){
        int temp,temp1;    
        cin >> temp >> temp1;    
        achieve.push_back(make_pair(store+temp,temp1));        
        store=store+temp;
    }
    //PRINT THE ACHIEVE
    //cout << "\nACHIEVE\n";
    //for(auto i:achieve){cout << i.first << " " << i.second << "\n";}

    int max=0;
    
    //Time Complexity O(T*(N+M))
    //Start counting from 1 to T.
    for(int ans=1;ans<T;ans++){
        int tmp=0;
        for(int i=0;i<N;i++){
            if(ans>0 && ans <=limit[0].first){tmp=limit[0].second;}
            else if(ans>limit[i-1].first && ans <= limit[i].first){tmp=limit[i].second;}
        }

        int tmp1=0;
        for(int i=0;i<M;i++){
            if(ans>0 && ans <=achieve[0].first){tmp1=achieve[0].second; }
            else if(ans>achieve[i-1].first && ans <= achieve[i].first){tmp1=achieve[i].second; }
        }

        int diff=tmp1-tmp;
        //find the maximum difference
        if(max < diff){
            max=diff;
        }
    }

    cout <<  max;
    return 0;
} 
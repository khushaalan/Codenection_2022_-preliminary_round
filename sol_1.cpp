#include<bits/stdc++.h>
using namespace std;   

 
int main(){
    //freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout); 
   
    int n, q; cin >> n >> q;
    int v[n];

    
    for(int i = 0; i < n; i++){
         cin >> v[i];
    
    }
    int sz= sizeof(v)/sizeof(v[0]);
    sort(v, v+sz);

    for(int i = 0; i < q; i++){
       int test; cin >> test;
        if(binary_search(v, v + n, test)){
           cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }

    return 0;
}
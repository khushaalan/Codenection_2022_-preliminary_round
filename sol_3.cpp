#include<bits/stdc++.h>
using namespace std;


bool sortbysec(const pair<int,int> &tmp,const pair<int,int> &tmp1){
       return tmp.second>tmp1.second;
}

int main(){
    //freopen("in.txt", "r", stdin);   freopen("output.txt", "w", stdout);

    int n=0; cin >> n;
    int temp=n;
    vector<pair <int,int> >a;
    vector<pair <int,int> >b;
    while(n-->0){
        int x, y; cin >> x >> y;
        a.push_back(make_pair(x,y));
        b.push_back(make_pair(x,y));
    }

    sort(a.rbegin(), a.rend());
    /*
    cout << "A\n";
    for(auto c: a){
      cout << c.first << " " << c.second << endl;
   }
    */

    sort(b.begin(), b.end(), sortbysec);
    /*
    cout << "B\n"; 
    for(auto c: b){
        cout << c.first << " " << c.second << endl;
    }
  */  


    int diff_x,diff_y,ans;
    int diff1_x,diff1_y,ans_1;
    int diff2_x,diff2_y,ans_2;
    int diff3_x,diff3_y,ans_3;
    int ans_final;

    if(a[0].first==b[0].first && a[0].second==b[0].second){
        diff_x=a[1].first-a[temp-1].first;
        diff1_y=b[1].second-b[temp-1].second;
        ans_final=diff_x*diff1_y;
        //cout << "debug_a\n";
    }
    else if(a[temp-1].first==b[temp-1].first && a[temp-1].second==b[temp-1].second){
        diff_x=a[0].first-a[temp-2].first;
        diff1_y=b[0].second-b[temp-2].second;
        ans_final=diff_x*diff1_y;
        //cout << "debug_b\n";
    }
    else{
        diff_x = a[1].first-a[temp-1].first;
        diff_y = b[0].second-b[temp-1].second;
        ans=diff_x*diff_y;
        
        diff1_x = a[0].first-a[temp-1].first;
        diff1_y = b[1].second-b[temp-1].second;
        ans_1=diff1_x*diff1_y;

        diff2_x = a[0].first-a[temp-2].first;
        diff2_y = b[0].second-b[temp-1].second;
        ans_2=diff2_x*diff2_y;

        diff3_x = a[0].first-a[temp-1].first;
        diff3_y = b[0].second-b[temp-2].second;
        ans_3=diff3_x*diff3_y;

        ans_final = min(min(min(ans,ans_1),min(ans_1,ans_2)),min(min(ans_1,ans_2),min(ans_2,ans_3)));
        //cout << "debug_c\n";
        
    }
    cout << ans_final;
    return 0;
}
// https://codeforces.com/contest/1689/problem/A

#include <iostream>
#include <vector>
#include <algorithm>
// #include <map>
// #include <numeric> // for partial_sum
// #include <stack>
// #include <queue>
// #include <set>
// #include <unordered_set>

const int MOD = 1e9 + 7;
const int BUF_SZ = 1 << 15;

using namespace std;

using ll = long long;

template<typename U>
void print(U arr) {
	for(auto element: arr) {
		cout << element << " ";
	}
	cout << endl;
}

string solve(){
    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a;
    cin >> b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int l1 = 0, l2 = 0, count=0;
    string ans = "";
    
    while(l1 < n && l2 < m){
        for(; count<k && l1<n; l1++, count++){
            if(l1==0 && l2==0){
                if(a[l1]<b[l2])
                    ans += a[l1];
                else
                    break;
            }
            else if(count == 0) ans += a[l1];
            else if(a[l1] < b[l2]) ans += a[l1];
            else break;
        }
        count = 0;
        if(l1 == n) return ans;
        for(; count<k && l2<m; l2++, count++){
            if(l1==0 && l2==0){
                if(a[l1]>b[l2])
                    ans += b[l2];
                else
                    break;
            }
            else if(count == 0) ans += b[l2];
            else if(b[l2] < a[l1]) ans += b[l2];
            else break;
        }
        count = 0;
        if(l2 == m) return ans;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll t=1;
    cin >> t;

    for(ll i=1; i<=t; i++){
        cout << solve() << endl;
    }
}
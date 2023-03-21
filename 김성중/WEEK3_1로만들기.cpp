#include <iostream>
using namespace std;

int main() {
    int N;
    cin>>N;

    int cnt[N+1];
    cnt[1]=0;
    for (int i=2;i<=N;i++) {
        cnt[i]=cnt[i-1]+1;
        if (i%3==0) {
            cnt[i]=min(cnt[i/3]+1,cnt[i]);
        }
        if (i%2==0) {
            cnt[i]=min(cnt[i/2]+1,cnt[i]);
        }
    }

    cout<<cnt[N];
    return 0;
}

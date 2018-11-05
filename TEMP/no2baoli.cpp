#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <ctime>
#include <map>
#include <set>
#define eps 1e-9
///#define M 1000100
///#define LL __int64
#define LL long long
///#define INF 0x7ffffff
#define INF 0x3f3f3f3f
#define PI 3.1415926535898
#define zero(x) ((fabs(x) < eps) ? 0 : x)
#define mod 1000000007

#define Read() freopen("autocomplete.in", "r", stdin)
#define Write() freopen("C1.out", "w", stdout)
#define Cin() ios::sync_with_stdio(false)

using namespace std;

const int maxn = 500010;

struct node
{
    int a, b, c;
} f[maxn];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> f[i].a >> f[i].b >> f[i].c;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int flag = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if ((f[i].a < f[j].a) && (f[i].b < f[j].b) && (f[i].c < f[j].c))
                    flag = 1;
            }
            ans += flag;
        }
        cout << ans << endl;
    }
}
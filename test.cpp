#include <bits/stdc++.h>
using namespace std;
#define EPSILON 1e-13
#define ll long long
const int INF = 1e9 + 1;
#define MAX 100100
#define endl '\n'

void solve();

int dp[21][301];
int profit[330][22];
int trace[21][301];

int main(void)
{
    freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	T = 1;
	//cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		int N, W;
		cin >> W >> N;

		for (int i = 1; i <= W; i++) {
			int n; cin >> n;
			for (int j = 1; j <= N; j++) {
				cin >> profit[n][j];
			}
		}


		memset(trace, 0, sizeof(trace));

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= W; j++) {
				for (int k = 1; k <= j; k++) {
					if (dp[i - 1][j] < dp[i - 1][j - k] + profit[k][i]) {
						if (dp[i][j] < dp[i - 1][j - k] + profit[k][i]) {
							dp[i][j] = dp[i - 1][j - k] + profit[k][i];
							trace[i][j] = k;
						}
					}
					else {
						dp[i][j] = max(dp[i][j], dp[i - 1][j]);
					}
				}
			}
		}

		stack<int> tr;


		int i = N, j = W;
		for (int x = 1; x <= N; x++) {
			int cur = trace[i][j];

			tr.push(cur);
			i--;
			j -= cur;

		}

		cout << dp[N][W] << endl;

		while (!tr.empty()) {
			cout << tr.top() << " ";
			tr.pop();
		}cout << endl;


	}

}

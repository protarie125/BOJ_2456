#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	auto pts = vvi(n, vi(3));
	auto ptsc = vvi(3, vi(3, 0));
	auto psum = vi(n, 0);
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < 3; ++j) {
			cin >> pts[i][j];
			psum[j] += pts[i][j];
			ptsc[j][pts[i][j] - 1] += 1;
		}
	}

	auto ansidx = int{ 0 };
	auto ansmx = int{ -1 };
	for (auto i = 0; i < 3; ++i) {
		if (ansmx < psum[i]) {
			ansidx = i + 1;
			ansmx = psum[i];
		}
		else if (ansmx == psum[i]) {
			if (0 != ansidx) {
				if (ptsc[ansidx - 1][2] < ptsc[i][2]) {
					ansidx = i + 1;
				}
				else if (ptsc[ansidx - 1][2] == ptsc[i][2]) {
					if (ptsc[ansidx - 1][1] < ptsc[i][1]) {
						ansidx = i + 1;
					}
					else if (ptsc[ansidx - 1][1] == ptsc[i][1]) {
						ansidx = 0;
					}
				}
			}
			else {
				if (ptsc[0][2] < ptsc[i][2]) {
					ansidx = i + 1;
				}
				else if (ptsc[0][2] == ptsc[i][2]) {
					if (ptsc[0][1] < ptsc[i][1]) {
						ansidx = i + 1;
					}
					else if (ptsc[0][1] == ptsc[i][1]) {
						ansidx = 0;
					}
				}
			}
		}
	}

	cout << ansidx << ' ' << ansmx;

	return 0;
}
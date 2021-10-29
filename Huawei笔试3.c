#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int idx = 1;

void bfs(vector<vector<int>>& data, queue<pair<int, int>>& q, vector<vector<int>>& visit) {
	while (!q.empty()) {
		int s = q.size();
		//cout << q.size() << endl;
		for (int i = 0; i < s; i++) {
			//cout << "k" << endl;
			pair<int, int>a = q.front();
			q.pop();
			int b = a.first, c = a.second;
			int d = a.first, e = a.second;
			int flag = 0;
			while ((b-1) >= 0) {
				if (data[b-1][a.second] == 0 && visit[b - 1][a.second] == 0) {
					if (visit[b-1][a.second] == 0) {
						visit[b-1][a.second] = idx;
						q.push(make_pair(b-1, a.second));
						b--;
						flag = 1;
						//cout << "q" << endl;
						
					}
				}
				else {
					break;
				}
			}
			while ((c-1) >= 0) {
				if (data[a.first][c-1] == 0 && visit[a.first][c - 1] == 0) {
					if (visit[a.first][c-1] == 0) {
						visit[a.first][c-1] = idx;
						q.push(make_pair(a.first, c-1));
						c--;
						//cout << "w" << endl;
						flag = 1;
					}
				}
				else {
					break;
				}
			}
			while ((d+1) < data.size()) {
				if (data[d+1][a.second] == 0 && visit[d + 1][a.second] == 0) {
					if (visit[d+1][a.second] == 0) {
						visit[d+1][a.second] = idx;
						q.push(make_pair(d+1, a.second));
						d++;
						//cout << "e" << endl;
						flag = 1;
					}
				}
				else {
					break;
				}
			}
			while ((e+1) < data[0].size()) {
				if (data[a.first][e+1] == 0 && visit[a.first][e + 1] == 0) {
					if (visit[a.first][e+1] == 0) {
						visit[a.first][e+1] = idx;
						q.push(make_pair(a.first, e+1));
						e++;
						//cout << "r" << endl;
						flag = 1;
					}
				}
				else {
					break;
				}
			}
		
		}
		idx++;

	}
	return;
}

int main() {
	int r = 0, c = 0,d = 0;
	cin >> r >> c;
	vector<vector<int>>data(r,vector<int>(c, 0));
	vector<vector<int>>visit(r, vector<int>(c, 0));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> d;
			data[i][j] = d;
		}
	}
	int start_x = 0, start_y = 0, end_x = 0, end_y = 0;
	cin >> start_x >> start_y >> end_x >> end_y;
	queue<pair<int, int>>q;
	data[end_x][end_y] = 0;
	q.push(make_pair(start_x, start_y));
	bfs(data, q, visit);
	cout << visit[end_x][end_y];
	return 0;
}

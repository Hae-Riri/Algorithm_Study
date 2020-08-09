#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

int map[8][8];
int origin[8][8];//�ٲ��� ��
bool visit[8][8];//�湮üũ
vector<pair<int,int>>zeros;//
vector<int>temp;//������ ����,��ü���� 3���� 1�θ����
int m, n;
int spread(vector<int>temp);
void bfs(int i, int j);
int ans;
int dx[4] = { -1,+1,0,0 };
int dy[4] = { 0,0,-1,+1 };

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >>origin[i][j];
			map[i][j] = origin[i][j];
			if (origin[i][j] == 0) {
				zeros.push_back(make_pair(i, j));//0�ξ� ��ġ����
			}
		}
	}

	/*for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j]<<" ";
		}
		cout << endl;
	}
	*/

	for (int i = 0; i < zeros.size()-3; i++)
		temp.push_back(0);
	for (int i = 0; i < 3; i++)
		temp.push_back(1);

	do {
		int result = spread(temp);
		//�۶߸� ����� �� ����
		ans = max(result, ans);
		//�ǵ�����(�湮üũ�� map��ġ��)
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = origin[i][j];
				visit[i][j] = false;
			}
		}
	} while (next_permutation(temp.begin(), temp.end()));

	cout << ans;
	return 0;
}

int spread(vector<int>temp) {
	int result=0;

	//3���� �� �����
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == 1) {
			int x = zeros[i].first; int y = zeros[i].second;
			//cout << x << "��" << y << "��" << " ";
			map[x][y] = 1;
		}
	}
	//cout << "----�Ʒ��� ���� ����"<<endl;
	/*for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}*/

	//���̷��� �۶߸��� �ڵ�
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 2 && !visit[i][j]) {
				bfs(i, j);
			}
		}
	}
	//�������� ���� �����ϴ� �ڵ�(�۶߸� �� 0�� ����)
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0)
				result++;
		}
	}

	

	
	return result;
}

void bfs(int i, int j) {
	queue<pair<int, int>>q;
	q.push(make_pair(i, j));
	visit[i][j] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (-1 < nx && nx < m && -1 < ny && ny < n && !visit[nx][ny] && map[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				map[nx][ny] = 2;
				visit[nx][ny] = true;
			}
		}
	}
	return;
}
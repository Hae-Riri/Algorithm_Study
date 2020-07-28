#include <vector>

using namespace std;

int dfs(int x, int y, int color, int m, int n, vector<vector<int>> &picture) {
	if(x < 0 || x >= m || y < 0 || y >= n || color != picture[x][y]) return 0;
	
	int count = 1;
	picture[x][y] = 0;
	
	count += dfs(x + 1, y, color, m, n, picture);
	count += dfs(x, y + 1, color, m, n, picture);
	count += dfs(x - 1, y, color, m, n, picture);
	count += dfs(x, y - 1, color, m, n, picture);
	
	return count;
}


// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    

	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(picture[i][j]) {
				number_of_area++;
				max_size_of_one_area = max(max_size_of_one_area, dfs(i, j, picture[i][j], m, n, picture));
			}
		}
	}
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

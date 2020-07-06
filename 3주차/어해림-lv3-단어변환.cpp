#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int ans = 50;
bool check[50];
bool diff(string a, string b) {
	int dif = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i])
			dif++;//�ٸ� ���� ��
		if (dif > 1)
			break;
	}
	if (dif == 1)
		return true;
	else
		return false;
}

void dfs(string begin, string target, vector<string>words, int cnt) {
	if (begin == target) {
		ans = min(ans, cnt);
		return;
	}
	for (int i = 0; i < words.size(); i++) {
		//���ڿ��� �ϳ��� �ٸ� �湮���ѳ��
		if (diff(begin, words[i]) && !check[i]) {
			check[i] = true;
			dfs(words[i], target, words, cnt + 1);
			check[i] = false;
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	dfs(begin, target, words, 0);
	answer = ans;
	if (answer == 50)
		return 0;
	return answer;
}
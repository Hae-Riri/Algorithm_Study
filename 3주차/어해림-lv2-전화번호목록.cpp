#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());//��������(����ũ���x)
	int l;
	for (int i = 0; i < phone_book.size() - 1; i++) {
		string str1 = phone_book[i];
		string str2 = phone_book[i + 1];
		string st;
		if (str1.length() <= str2.length())
			l = str1.length();
		else
			l = str2.length();
		bool same = true;//�ٸ� ���ڰ� �ϳ��� ������ false�ɰž�
		for (int j = 0; j < l; j++) {
			if (str1[j] - '0' != str2[j] - '0') {//�ϳ��� �ٸ���
				same = false;
				break;
			}
		}
		if (same) {//���ξ� �������ڰ� �ִٸ�
			answer = false;
			break;
		}
	}

	return answer;
}
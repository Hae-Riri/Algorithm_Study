#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int>nums(n + 1, 1);//�ε����� �л���ȣ�� ����Ͽ� ü���� ���� ����(1�� �ʱ�ȭ)
	for (int i = 1; i < nums.size(); i++) {//1������ n������ Ȯ��
		for (int j = 0; j < lost.size(); j++) {
			if (lost[j] == i)//i���л��� �������ߴٸ�
				nums[i]--;//i���л��� ü���� �� ����
		}
		for (int j = 0; j < reserve.size(); j++) {
			if (reserve[j] == i) {
				nums[i]++;//�������ߴ� �ֿ����� ���� ���� �ٽ� 1���� �Ǿ���
			}
		}
	}//������ ���� ���ļ� �л� ü������ ������Ʈ �Ϸ�

	//���� 0���� �� �ذ����ֱ�(�ֺ� �ְ� 2������ Ȯ��)
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == 0) {//���� 0���� �� �ֺ� Ȯ��
			if (i - 1 >= 1) {
				if (nums[i - 1] == 2) {//��������
					nums[i - 1]--;
					nums[i]++;
				}
			}
			if (nums[i] == 0 && i + 1 <= n) {//���� �ڱ� ������ �� ���� �޾Ҵٸ� �ڱ� �޹�ȣ Ȯ��
				if (nums[i + 1] == 2) {
					nums[i + 1]--;
					nums[i]++;
				}
			}
		}
	}

	//����
	for (int i = 1; i < nums.size(); i++) {//1������ n������
		if (nums[i] >= 1) {//ü���� 1�� �̻��̸�
			answer++;
		}
	}

	return answer;
}
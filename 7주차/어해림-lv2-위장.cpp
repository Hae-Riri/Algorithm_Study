#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int mix_kind(vector<pair<string, int>>kinds, int i);
int solution(vector<vector<string>> clothes) {
    int answer = 0;
    vector<pair<string, int>>kinds;
    kinds.push_back(make_pair(clothes[0][1], 1));
    for (int i = 1; i < clothes.size(); i++) {
        bool isNew = true;
        for (int j = 0; j < kinds.size(); j++) {
            if (kinds[j].first == clothes[i][1]) {//���������� �ִٸ�
                kinds[j].second++;
                isNew = false;
            }
        }
        if (isNew) {
            kinds.push_back(make_pair(clothes[i][1], 1));
        }
    }
    // answer = answer+clothes.size();
    for (int i = 1; i <= kinds.size(); i++) {//���� ���� �� �ϳ� �̻� �̱�(����)
        answer = answer + mix_kind(kinds, i);
    }
    return answer;
}
int mix_kind(vector<pair<string, int>>kinds, int i) {
    int ans = 0;
    //i�� ������ �̱�
    vector<int>v(kinds.size() - i, 0);
    for (int j = 0; j < i; j++) {
        v.push_back(1);
    }
    do {
        int tmp = 1;
        for (int k = 0; k < v.size(); k++) {
            if (v[k] == 1) {//���õ� �����ϱ�
                tmp = tmp * kinds[k].second;
            }
        }
        ans = ans + tmp;
    } while (next_permutation(v.begin(), v.end()));
    v.clear(); v.resize(0);
    return ans;
}
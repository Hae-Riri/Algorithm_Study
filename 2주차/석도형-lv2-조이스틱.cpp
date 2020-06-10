#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    //������ ���Ʒ��θ� �������� �� �ּڰ� 
    for (auto ch : name) {
        answer += min(ch - 'A', 'Z' - ch + 1);
   }
    
    // ���ʿ��������� �����̴� ���� �ּڰ�. 
   int len = name.size();
    
   int horizontal_move = len - 1;
    
    //i�� ���������� �����̴� Ƚ��
   //i���� ��ġ���� ���������� �����̰� i�������� �ٽ� �������� ������.
   //last_idx�� �������� �������� �� ���������� Ȯ���ؾ��� ��ġ��.
   // �� �߰��� ���ӵ� A�� ���ִ� ��� �� ���ӵ� A�� �����ϰ� ������ ��ġ�鿡���� �����̴� ���̴�.
   // 
    for (int i = 0; i < len; ++i) {
        int last_index = i + 1;
        while (last_index < len && name[last_index] == 'A') {   
            last_index++;
       }
       //last_index�� ���ڿ��� �������� �ᱹ �������� ���� �ʰ� ���������� i������ �����̸� �ȴٴ� �Ҹ�.
      //�װ� �ƴ϶�� i��ŭ ���������� �����̰� �ٽ� i��ŭ �������� �����̰� len-last_index��ŭ ������ last_index���� ��������� �Ѵ�. 
        if(last_index == len) {
            horizontal_move = min(horizontal_move, i);
        } else {
            horizontal_move = min(horizontal_move, (i * 2) + (len - last_index));
        }
       
    }
    answer += horizontal_move;
    
    return answer;
}

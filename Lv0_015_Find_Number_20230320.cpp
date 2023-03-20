#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : ���� ã��
// 
// ���� ����
// ���� num�� k�� �Ű������� �־��� ��, num�� �̷�� ���� �߿� k�� ������ num�� �� ���ڰ� �ִ� �ڸ� ���� return�ϰ� ������ -1�� return �ϵ��� solution �Լ��� �ϼ��غ�����.
// 
// ���ѻ���
// 0 < num < 1,000,000
// 0 �� k < 10
// num�� k�� ���� �� ������ ���� ó�� ��Ÿ���� �ڸ��� return �մϴ�.
// 
// ����� ��
// num	    k	result
// 29183	1	3
// 232443	4	4
// 123456	7 - 1
//
//*************************************************************************************************************************************

int solution(int num, int k) {
    int answer = 0;

    //int�� ���ڿ��� �����Ͽ� �� index�� ���� �� ��
    string temp_num, temp_k;
    temp_num = to_string(num);
    temp_k = to_string(k);
    
    unsigned int i;
    for (i = 0; i < temp_num.size(); i++) {
        if (temp_num[i] == temp_k[0]) {
            answer++;
            break;
        }
        else
            answer++;
    }
    if (i == temp_num.size())
        answer = -1;

    cout << answer << endl;

    return answer;
}

int main() {
    solution(29183, 1);         // 3
    solution(232443, 4);        // 4
    solution(123456, 7);        // -1
    solution(45999, 9);         // 3
    solution(3, 3);             // 1
    return 0;
}
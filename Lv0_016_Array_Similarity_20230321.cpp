#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : �迭�� ���絵
// 
// ���� ����
// �� �迭�� �󸶳� �������� Ȯ���غ����� �մϴ�. ���ڿ� �迭 s1�� s2�� �־��� �� ���� ������ ������ return�ϵ��� solution �Լ��� �ϼ����ּ���.
// 
// ���ѻ���
// 1 �� s1, s2�� ���� �� 100
// 1 �� s1, s2�� ������ ���� �� 10
// s1�� s2�� ���Ҵ� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�
// s1�� s2�� ���� �ߺ��� ���Ҹ� ���� �ʽ��ϴ�.
// 
// ����� ��
// s1	            s2	                            result
// ["a", "b", "c"]  ["com", "b", "d", "p", "c"]	    2
// ["n", "omg"]     ["m", "dot"]                    0
//
//*************************************************************************************************************************************

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    for (const auto& number1 : s1) {
        for (const auto& number2 : s2) {
            if (number1 == number2)
                answer++;
        }
    }
    printf("%d\n", answer);
    return answer;
}

int main() {
    vector<string> input_1 = { "a", "b", "c" };
    vector<string> input_2 = { "com", "b", "d", "p", "c" };
    solution(input_1, input_2);

    return 0;
}
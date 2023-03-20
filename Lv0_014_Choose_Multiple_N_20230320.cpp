#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : n�� ��� ����
// 
// ���� ����
// ���� n�� ���� �迭 numlist�� �Ű������� �־��� ��, numlist���� n�� ����� �ƴ� ������ ������ �迭�� return�ϵ��� solution �Լ��� �ϼ����ּ���.
// 
// ���ѻ���
// 1 �� n �� 10,000
// 1 �� numlist�� ũ�� �� 100
// 1 �� numlist�� ���� �� 100, 000
// 
// ����� ��
// n	numlist	                        result
// 3    [4, 5, 6, 7, 8, 9, 10, 11, 12]  [6, 9, 12]
// 5    [1, 9, 3, 10, 13, 5]            [10, 5]
// 12   [2, 100, 120, 600, 12, 12]      [120, 600, 12, 12]
//
//*************************************************************************************************************************************

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;

    for (const auto& number : numlist) {
        //printf("%d\n", number);
        if ((number % n) == 0) {
            answer.push_back(number);
        }
    }

    return answer;
}

int main() {

    int input_n = 3;
    vector<int> input_numlist = { 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    vector<int> output_numlist = solution(input_n, input_numlist);

    for (const auto& number : output_numlist) {
        printf("%d\n", number);
    }


    return 0;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : ���� ū �� ã��
// 
// ���� ����
// ���� �迭 array�� �Ű������� �־��� ��, ���� ū ���� �� ���� �ε����� ���� �迭�� return �ϵ��� solution �Լ��� �ϼ��غ�����.
// 
// ���ѻ���
// 1 �� array�� ���� �� 100
// 0 �� array ���� �� 1, 000
// array�� �ߺ��� ���ڴ� �����ϴ�.
// 
// ����� ��
// array	        result
// [1, 8, 3]        [8, 1]
// [9, 10, 11, 8]   [11, 2]
//
//*************************************************************************************************************************************

vector<int> solution(vector<int> array) {
    vector<int> answer;

    int cnt = 0, tempbuf = 0, idx = 0;
    for (const auto& i : array) {
        if (tempbuf < i) {
            tempbuf = i;
            idx = cnt;
        }
        cnt++;
    }
    answer.emplace_back(tempbuf);
    answer.emplace_back(idx);

    return answer;
}

int main() {
    vector<int> input_array;
    vector<int> output_array;

    input_array = { 1, 8, 3 };
    output_array = solution(input_array);
    for (const auto& j : output_array) {
        cout << j << endl;
    }

    input_array = { 9, 10, 11, 8 };
    output_array = solution(input_array);
    for (const auto& j : output_array) {
        cout << j << endl;
    }

    return 0;
}
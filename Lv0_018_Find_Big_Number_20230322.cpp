#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 가장 큰 수 찾기
// 
// 문제 설명
// 정수 배열 array가 매개변수로 주어질 때, 가장 큰 수와 그 수의 인덱스를 담은 배열을 return 하도록 solution 함수를 완성해보세요.
// 
// 제한사항
// 1 ≤ array의 길이 ≤ 100
// 0 ≤ array 원소 ≤ 1, 000
// array에 중복된 숫자는 없습니다.
// 
// 입출력 예
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
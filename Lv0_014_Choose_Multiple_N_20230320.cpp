#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : n의 배수 고르기
// 
// 문제 설명
// 정수 n과 정수 배열 numlist가 매개변수로 주어질 때, numlist에서 n의 배수가 아닌 수들을 제거한 배열을 return하도록 solution 함수를 완성해주세요.
// 
// 제한사항
// 1 ≤ n ≤ 10,000
// 1 ≤ numlist의 크기 ≤ 100
// 1 ≤ numlist의 원소 ≤ 100, 000
// 
// 입출력 예
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
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 배열의 유사도
// 
// 문제 설명
// 두 배열이 얼마나 유사한지 확인해보려고 합니다. 문자열 배열 s1과 s2가 주어질 때 같은 원소의 개수를 return하도록 solution 함수를 완성해주세요.
// 
// 제한사항
// 1 ≤ s1, s2의 길이 ≤ 100
// 1 ≤ s1, s2의 원소의 길이 ≤ 10
// s1과 s2의 원소는 알파벳 소문자로만 이루어져 있습니다
// s1과 s2는 각각 중복된 원소를 갖지 않습니다.
// 
// 입출력 예
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
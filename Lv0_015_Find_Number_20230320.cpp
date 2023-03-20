#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 숫자 찾기
// 
// 문제 설명
// 정수 num과 k가 매개변수로 주어질 때, num을 이루는 숫자 중에 k가 있으면 num의 그 숫자가 있는 자리 수를 return하고 없으면 -1을 return 하도록 solution 함수를 완성해보세요.
// 
// 제한사항
// 0 < num < 1,000,000
// 0 ≤ k < 10
// num에 k가 여러 개 있으면 가장 처음 나타나는 자리를 return 합니다.
// 
// 입출력 예
// num	    k	result
// 29183	1	3
// 232443	4	4
// 123456	7 - 1
//
//*************************************************************************************************************************************

int solution(int num, int k) {
    int answer = 0;

    //int를 문자열로 변경하여 각 index에 대한 값 비교
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
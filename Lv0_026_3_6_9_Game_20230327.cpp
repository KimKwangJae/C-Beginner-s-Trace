#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 369 게임
// 
// 문제 설명
// 머쓱이는 친구들과 369게임을 하고 있습니다. 369게임은 1부터 숫자를 하나씩 대며 3, 6, 9가 들어가는 숫자는 숫자 대신 
// 3, 6, 9의 개수만큼 박수를 치는 게임입니다. 머쓱이가 말해야하는 숫자 order가 매개변수로 주어질 때, 
// 머쓱이가 쳐야할 박수 횟수를 return 하도록 solution 함수를 완성해보세요.
//
// 제한사항
// 1 ≤ order ≤ 1,000,000
// 
// 입출력 예
// order	result
// 3	    1
// 29423	2
//
//*************************************************************************************************************************************

int solution(int order) {
    int answer = 0;

    string tmp_str = to_string(order);

    for (const auto v : tmp_str) {
        if (v == '3' || v == '6' || v == '9')
            answer++;
    }

    return answer;
}

int main() {
    printf("result : %d\n", solution(3));
    printf("result : %d\n", solution(29423));
    return 0;
}
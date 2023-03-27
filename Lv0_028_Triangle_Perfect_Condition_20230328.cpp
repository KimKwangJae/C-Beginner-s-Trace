#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 삼각형의 완성조건 (1)
// 
// 문제 설명
// 선분 세 개로 삼각형을 만들기 위해서는 다음과 같은 조건을 만족해야 합니다.
// 가장 긴 변의 길이는 다른 두 변의 길이의 합보다 작아야 합니다.
// 삼각형의 세 변의 길이가 담긴 배열 sides이 매개변수로 주어집니다.세 변으로 삼각형을 만들 수 있다면 1, 만들 수 없다면 2를 return하도록 solution 함수를 완성해주세요.
//
// 제한사항
// sides의 원소는 자연수입니다.
// sides의 길이는 3입니다.
// 1 ≤ sides의 원소 ≤ 1, 000
// 
// 입출력 예
// sides	        result
// [1, 2, 3]	    2
// [3, 6, 2]	    2
// [199, 72, 222]	1
//
//*************************************************************************************************************************************

int solution(vector<int> sides) {
    int answer = 2;

    int tmp = sides[0];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (sides[j] > sides[j+1]) {
                tmp = sides[j];
                sides[j] = sides[j + 1];
                sides[j + 1] = tmp;
            }
        }
    }

    if (sides[0] + sides[1] > sides[2])
        answer = 1;

    return answer;
}

int main() {
    vector<int> input_vec = {1,2,3};
    printf("Triangle Condition : %d\n", solution(input_vec));

    input_vec = { 3,6,2 };
    printf("Triangle Condition : %d\n", solution(input_vec));

    input_vec = { 199,72,222 };
    printf("Triangle Condition : %d\n", solution(input_vec));

    return 0;
}
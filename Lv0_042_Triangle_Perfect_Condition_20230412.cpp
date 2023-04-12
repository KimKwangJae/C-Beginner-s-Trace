#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 삼각형의 완성조건 (2)
// 
// 문제 설명
// 선분 세 개로 삼각형을 만들기 위해서는 다음과 같은 조건을 만족해야 합니다.
// 가장 긴 변의 길이는 다른 두 변의 길이의 합보다 작아야 합니다.
// 삼각형의 두 변의 길이가 담긴 배열 sides이 매개변수로 주어집니다.나머지 한 변이 될 수 있는 정수의 개수를 return하도록 solution 함수를 완성해주세요.
//
// 제한사항
// sides의 원소는 자연수입니다.
// sides의 길이는 2입니다.
// 1 ≤ sides의 원소 ≤ 1, 000
// 
// 입출력 예
// sides	result
// [1, 2]	1
// [3, 6]	5
// [11, 7]	13
//
//*************************************************************************************************************************************

int solution(vector<int> sides) {
    int answer = 0;

    int long_sides = sides[0] > sides[1] ? sides[0] : sides[1];
    int small_sides = sides[0] > sides[1] ? sides[1] : sides[0];

    // 가장 긴 변이 주어진 숫자인 경우
    answer += long_sides - (long_sides - small_sides);

    // 나머지 한 변이 가장 긴 변인 경우
    answer += (long_sides + small_sides) - long_sides - 1;  //(중복 1개 제거)

    return answer;
}

int main() {

    return 0;
}
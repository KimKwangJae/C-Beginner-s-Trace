#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 약수 구하기
// 
// 문제 설명
// 정수 n이 매개변수로 주어질 때, n의 약수를 오름차순으로 담은 배열을 return하도록 solution 함수를 완성해주세요.
// 
// 제한사항
// 1 ≤ n ≤ 10,000
// 
// 입출력 예
// n	result
// 24   [1, 2, 3, 4, 6, 8, 12, 24]
// 29   [1, 29]
//
//*************************************************************************************************************************************

vector<int> solution(int n) {
    vector<int> answer;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            answer.emplace_back(i);
    return answer;
}

int main() {
    int input_num;
    vector<int> output_mathmetical_factor;

    input_num = 24;
    printf("숫자 %d의 약수 : \n", input_num);

    output_mathmetical_factor = solution(input_num);
    for (const auto& a : output_mathmetical_factor) {
        printf("%d\n", a);
    }


    return 0;
}
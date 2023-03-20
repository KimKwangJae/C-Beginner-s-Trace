#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 자릿수 더하기
// 
// 문제 설명
// 정수 n이 매개변수로 주어질 때 n의 각 자리 숫자의 합을 return하도록 solution 함수를 완성해주세요
// 
// 제한사항
// 0 ≤ n ≤ 1,000,000
// 
// 입출력 예
// n	result
// 1234	10
// 930211	16
//
//*************************************************************************************************************************************

int solution(int n) {
    int answer = 0;

    //자리수 검사
    int cnt = 1;
    for (int i = 10; i <= 1000000; i*=10) {
        if (n < i) {
            cnt;                                                                                // i = 10 --> 1의 자리
            break;
        }
        cnt++;
    }

    //12345 (cnt 5)
    int temp_n = n;
    for (int j = 1; j <= cnt; j++) {
        answer += temp_n % 10;   //j=1 1의자리
        temp_n /= 10;
    }

    return answer;
}

int main() {
    printf("Start!!\n");
    printf("Add Digits : %d\n", solution(12345));
    printf("Add Digits : %d\n", solution(10000));
    printf("Add Digits : %d\n", solution(10100));
    printf("End!!\n");
    return 0;
}
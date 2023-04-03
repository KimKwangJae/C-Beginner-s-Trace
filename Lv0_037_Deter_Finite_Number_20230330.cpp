#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 유한소수 판별하기
// 
// 문제 설명
// 소수점 아래 숫자가 계속되지 않고 유한개인 소수를 유한소수라고 합니다. 분수를 소수로 고칠 때 유한소수로 나타낼 수 있는 분수인지 판별하려고 합니다. 
// 유한소수가 되기 위한 분수의 조건은 다음과 같습니다.
// 기약분수로 나타내었을 때, 분모의 소인수가 2와 5만 존재해야 합니다.
// 두 정수 a와 b가 매개변수로 주어질 때, a / b가 유한소수이면 1을, 무한소수라면 2를 return하도록 solution 함수를 완성해주세요.
//
// 제한사항
// a, b는 정수
// 0 < a ≤ 1, 000
// 0 < b ≤ 1, 000
// 
// 입출력 예
// a	  b	    result
// 7	  20	1
// 11	  22	1
// 12	  21	2
//
//*************************************************************************************************************************************

int solution(int a, int b) {
    int answer = 1;
    
    // 분자, 분모의 최대공약수 구하기
    vector<int> a_vec;
    for (int i = 1; i <= a; i++) {
        if (a % i == 0)
            a_vec.push_back(i);
    }
    vector<int> b_vec;
    for (int i = 1; i <= b; i++) {
        if (b % i == 0)
            b_vec.push_back(i);
    }

    //------------------------------------------------------
    for (int z = 0; z < (int)a_vec.size(); z++) {
        printf("%d ", a_vec[z]);
    }
    printf("\n");
    for (int z = 0; z < (int)b_vec.size(); z++) {
        printf("%d ", b_vec[z]);
    }
    printf("\n\n");
    //------------------------------------------------------
    
    //약분 (문제 포인트)
    int divide_n = 0;
    for (int i = a_vec.size()-1; i >= 0; i--) {
        for (int j = b_vec.size()-1; j >= 0; j--) {
            if (a_vec[i] == b_vec[j]) {
                divide_n = a_vec[i];
                break;
            }
        }
        if (divide_n != 0)
            break;
    }
    if (divide_n != 0) {
        a = a / divide_n;
        b = b / divide_n;
    }

    // 분모 소인수 구하기
    b_vec.clear();
    for (int i = 2; i <= b; i++) {
        if (b % i == 0) {
            bool sosu = true;
            for (int j = 2; j <= i-1; j++) {
                //소수판별
                if (i % j == 0) {
                    sosu = false;
                }
            }
            if(sosu)
                b_vec.push_back(i);
        }
    }

    //------------------------------------------------------
    printf("최대공약수 : %d\n", divide_n);
    printf("a : %d\n", a);
    printf("b : %d\n", b);
    for (int z = 0; z < (int)b_vec.size(); z++) {
        printf("%d ", b_vec[z]);
    }
    printf("\n\n");
    //------------------------------------------------------

    for (int i = 0; i < (int)b_vec.size(); i++) {
        if (b_vec[i] != 2 && b_vec[i] != 5) {
            answer = 2;
            break;
        }
    }

    return answer;
}

int main() {
    printf("output (7, 20) : %d\n", solution(7, 20));
    printf("-----------------------------------------------------------\n");
    printf("output (11, 22) : %d\n", solution(11, 22));
    printf("-----------------------------------------------------------\n");
    printf("output (12, 21) : %d\n", solution(12, 21));
    return 0;
}
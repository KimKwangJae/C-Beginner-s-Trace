#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 가까운 수
// 
// 문제 설명
// 정수 배열 array와 정수 n이 매개변수로 주어질 때, array에 들어있는 정수 중 n과 가장 가까운 수를 return 하도록 solution 함수를 완성해주세요.
//
// 제한사항
// 1 ≤ array의 길이 ≤ 100
// 1 ≤ array의 원소 ≤ 100
// 1 ≤ n ≤ 100
// 가장 가까운 수가 여러 개일 경우 더 작은 수를 return 합니다.
// 
// 입출력 예
// array	    n	result
// [3, 10, 28]	20	28
// [10, 11, 12]	13	12
//
//*************************************************************************************************************************************

int solution(vector<int> array, int n) {
    int answer = 0;


    for (unsigned int i = 0; i < array.size() - 1; i++) {
        for (unsigned int j = 0; j < array.size()-1; j++) {
            if (array[j] > array[j + 1]) {
                int tmp;
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }

    for (unsigned int j = 0; j < array.size(); j++) {
        printf("array order %d\n", array[j]);
    }

    int cmp_int = 0, cmp_int_bk = 0;
    for (unsigned int i = 0; i < array.size(); i++) {
        cmp_int = array[i] - n;
        if (cmp_int < 0)
            cmp_int *= -1;

        if (i == 0)
            answer = array[i];
        else {
            if (cmp_int_bk > cmp_int) {
                answer = array[i];
            }
        }
        cmp_int_bk = cmp_int;
    }

    return answer;
}

int main() {
    vector<int> input_array = { 3, 10, 28 };
    printf("output : %d\n", solution(input_array, 20));

    input_array = { 10, 11, 12 };
    printf("output : %d\n", solution(input_array, 13));

    input_array = { 10, 13, 11 };
    printf("output : %d\n", solution(input_array, 12));

    return 0;
}
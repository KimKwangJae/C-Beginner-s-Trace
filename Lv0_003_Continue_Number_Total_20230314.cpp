#include <string>
#include <vector>
#include <iostream>

using namespace std;


//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 연속된 수의 합
// 
// 문제 설명
// 연속된 세 개의 정수를 더해 12가 되는 경우는 3, 4, 5입니다.두 정수 num과 total이 주어집니다.
// 연속된 수 num개를 더한 값이 total이 될 때, 정수 배열을 오름차순으로 담아 return하도록 solution함수를 완성해보세요.
// 
// 제한사항
// 1 ≤ num ≤ 100
// 0 ≤ total ≤ 1000
// num개의 연속된 수를 더하여 total이 될 수 없는 테스트 케이스는 없습니다.
// 
// 입출력 예
// num	total	result
// 3	12     [3, 4, 5]
// 5	15     [1, 2, 3, 4, 5]
// 4	14     [2, 3, 4, 5]
// 5	5      [-1, 0, 1, 2, 3]
// 
// 날짜 : 2023.03.14
// 포인트 : 문자열 처리 & 알고리즘 구상
//*************************************************************************************************************************************


vector<int> solution(int num, int total);

int main() {
    // 정수 배열을 return
    int input_num, input_total;

    cout << "연속된 수의 개수를 입력하세요." << endl;
    cin >> input_num;
    cout << endl;
    cout << "연속된 수의 합계를 입력하세요." << endl;
    cin >> input_total;
    cout << endl;

    vector<int> result = solution(input_num, input_total);
    vector<int>::iterator iter;
    for (iter = result.begin(); iter != result.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}

vector<int> solution(int num, int total) {
    vector<int> answer;

    //int 범위 –2,147,483,648 ~ 2,147,483,647
    int cnt = 1, i_start, i_end, j, total_tmp;
    bool find_chk = false;

    i_start = -100;
    while (1) {
        cout << "[while][i_start : " << i_start << "]" << endl;
        total_tmp = 0;
        for (int i = i_start; i < (i_start + num); i++) {
            total_tmp += i;
            if (total == total_tmp) {
                i_end = i;
                find_chk = true;
                break;
            }
        }

        if (find_chk)
            break;

        cnt++;
        i_start++;
    }

    cout << i_end << endl;

    //vector 값 생성
    for (j = 1; j <= num; j++) {
        answer.push_back(i_end + (j - num));
    }

    return answer;
}
#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 특이한 정렬
// 
// 문제 설명
// 정수 n을 기준으로 n과 가까운 수부터 정렬하려고 합니다. 
// 이때 n으로부터의 거리가 같다면 더 큰 수를 앞에 오도록 배치합니다. 
// 정수가 담긴 배열 numlist와 정수 n이 주어질 때 numlist의 원소를 n으로부터 가까운 순서대로 정렬한 배열을 return하도록 solution 함수를 완성해주세요.
//
// 제한사항
// 1 ≤ n ≤ 10,000
// 1 ≤ numlist의 원소 ≤ 10, 000
// 1 ≤ numlist의 길이 ≤ 100
// numlist는 중복된 원소를 갖지 않습니다.
// 
// 입출력 예
// numlist	                                n	    result
// [1, 2, 3, 4, 5, 6]	                    4       [4, 5, 3, 6, 2, 1]
// [10000, 20, 36, 47, 40, 6, 10, 7000]	    30      [36, 40, 20, 47, 10, 6, 7000, 10000]
//
//*************************************************************************************************************************************

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;

    answer.push_back(numlist[0]);
    for (unsigned int i = 0; i < numlist.size(); i++) {
        int differ = (n - numlist[i]) < 0 ? (n - numlist[i]) * -1 : (n - numlist[i]);                   //타겟 n과 현재 비교값의 차이 계산
        for (unsigned int j = 0; j < answer.size(); j++) {
                int differ_exist = (n - answer[j]) < 0 ? (n - answer[j]) * -1 : (n - answer[j]);        //타겟 n과 answer 내부값의 차이 계산

                if (differ <= differ_exist) {                                                           //현재 비교값이 작거나 같으면 (스왑 또는 삽입)
                    if (differ == differ_exist && numlist[i] > answer[j]) {                             //스왑
                        int tmp = answer[j];
                        answer[j] = numlist[i];
                        answer.insert(answer.begin() + (j + 1), 1, tmp);
                    }
                    else if (differ == differ_exist && numlist[i] < answer[j]) {                        //삽입
                        answer.insert(answer.begin() + (j + 1), 1, numlist[i]);
                    }
                    else if (differ == differ_exist && numlist[i] == answer[j]) {                       //최초 실행 시 입력값 (Pass)
                        printf("Same Number.. Pass \n");
                    }
                    else {                                                                              //스왑
                        int tmp = answer[j];
                        answer[j] = numlist[i];
                        answer.insert(answer.begin() + (j + 1), 1, tmp);
                    }
                    break;
                }
                else {
                    if (j == answer.size() - 1)
                        answer.push_back(numlist[i]);                                                    // 기존 값을 모두 비교 후 현재 값보다 작은 값이 없으면 마지막에 추가
                }
        }

        for (unsigned int z = 0; z < answer.size(); z++) {
            printf("%d ", answer[z]);
        }
        printf("\n------------------------------------------------------------------\n");
    }

    return answer;
}

int main() {
    vector<int> input;
    vector<int> output;
    int t_number;

    //input = {1, 2, 3, 4, 5, 6};
    //t_number = 4;
    //output = solution(input, t_number);
    //for (unsigned int i = 0; i < output.size(); i++) {
    //    printf("%d ", output[i]);
    //}
    //printf("\n\n\n");

    //input = { 10000, 20, 36, 47, 40, 6, 10, 7000 };
    //t_number = 30;
    //output = solution(input, t_number);
    //for (unsigned int i = 0; i < output.size(); i++) {
    //    printf("%d ", output[i]);
    //}
    //printf("\n\n\n");

    input = { 600, 400, 300, 200, 700, 800, 100, 900 };
    t_number = 500;
    output = solution(input, t_number);
    for (unsigned int i = 0; i < output.size(); i++) {
        printf("%d ", output[i]);
    }
    printf("\n\n\n");

    return 0;
}
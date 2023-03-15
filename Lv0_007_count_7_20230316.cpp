#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 7의 개수
// 
// 문제 설명
// 머쓱이는 행운의 숫자 7을 가장 좋아합니다. 정수 배열 array가 매개변수로 주어질 때, 7이 총 몇 개 있는지 return 하도록 solution 함수를 완성해보세요.
// 
// 제한사항
// 1 ≤ array의 길이 ≤ 100
// 0 ≤ array의 원소 ≤ 100, 000
// 
// 입출력 예
// array	    result
// [7, 77, 17]	4
// [10, 29]	    0
//*************************************************************************************************************************************


int solution(vector<int> array);

int main() {

    vector<int> input_array = {7, 77, 17};
    cout << solution(input_array) << endl;

    return 0;
}

int solution(vector<int> array) {
    int answer = 0;
    int tmp_array_bk;
    for (int i = 0; i < array.size(); i++) {
        //cout << "First for() Start! [" << i << "] ==============================================" << endl;
        //cout << "index : " << i << " (array value:" << array[i] << ")" << endl;
        
        tmp_array_bk = array[i];
        for (int j = 4; j >= 0; j--) {
            int divided_num = pow(10.0, (double)j);                         // 10의 배수 (큰수에서 작은수로)

            if (divided_num > 1) {
                if (tmp_array_bk / divided_num == 7)
                    answer++;
            }
            else {
                if (tmp_array_bk == 7)
                    answer++;
            }
            tmp_array_bk %= divided_num;
        }
    }
    return answer;
}
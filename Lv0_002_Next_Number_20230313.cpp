#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 다음에 올 숫자
// 
// 문제 설명
// 등차수열 혹은 등비수열 common이 매개변수로 주어질 때, 마지막 원소 다음으로 올 숫자를 return 하도록 solution 함수를 완성해보세요.
//
// 제한사항
// 2 < common의 길이 < 1,000
// -1,000 < common의 원소 < 2,000
// common의 원소는 모두 정수입니다.
// 등차수열 혹은 등비수열이 아닌 경우는 없습니다.
// 등비수열인 경우 공비는 0이 아닌 정수입니다.
//
// 입출력 예
// common	result
// [1, 2, 3, 4]	5
// [2, 4, 8]	16
//*************************************************************************************************************************************

// 주어진 함수 (내부에 Logic 구현)
int solution(vector<int> common) {
    int answer = 0;

    // 공차 : 앞, 뒤 숫자의 차
    // 공비 : 앞, 뒤 숫자의 비

    // 1. 빼야할 지 나눠야할 지 먼저 검사
    // 2. 검사 결과에 따라 적용 후 마지막 숫자 리턴

    //공차 검사
    if((common.at(1) - common.at(0)) == (common.at(2) - common.at(1)) ? true : false){
        printf("공차 검사 시작!\n");
        int temp1 = common.at(1) - common.at(0);                //공차
        answer = common.back() + temp1;
    }
    else {
        printf("공비 검사 시작!\n");
        int temp1_divided = common.at(1) / common.at(0);        //공비
        answer = common.back() * temp1_divided;
    }

    return answer;
}


int main() {

    vector<int> vInput;
    vInput = {1, 2, 3, 4};       //입력 예시 1
    //vInput = {2, 4, 8};          //입력 예시 2

    printf("This sequence is \n");        //vector 를 출력하는 방법 확인 (https://cocoze.tistory.com/6)

    vector<int>::iterator iter;         //컨테이너 원소를 참조하는 Iterator 를 이용하여 벡터 원소 출력
    for (iter = vInput.begin(); iter != vInput.end(); iter++) {
        cout << *iter << endl;
    }


    printf("Next Number is %d\n", solution(vInput));

    return 0;
}
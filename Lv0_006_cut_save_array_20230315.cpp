#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 잘라서 배열로 저장하기
// 
// 문제 설명
// 문자열 my_str과 n이 매개변수로 주어질 때, my_str을 길이 n씩 잘라서 저장한 배열을 return하도록 solution 함수를 완성해주세요.
// 
// 제한사항
// 1 ≤ my_str의 길이 ≤ 100
// 1 ≤ n ≤ my_str의 길이
// my_str은 알파벳 소문자, 대문자, 숫자로 이루어져 있습니다.
// 
// 입출력 예
// my_str	            n	result
// "abc1Addfggg4556b"	6   ["abc1Ad", "dfggg4", "556b"]
// "abcdef123"	        3   ["abc", "def", "123"]
// 
// 날짜 : 2023.03.15
// 포인트 : 문자열, 배열 처리
//*************************************************************************************************************************************


vector<string> solution(string my_str, int n);

int main() {
    string input_str = "abc1Addfggg4556b";
    int input_num = 6;

    vector<string> rtn = solution(input_str, input_num);
    vector<string>::iterator vi;
    for (vi = rtn.begin(); vi != rtn.end(); vi++) {
        cout << *vi << endl;
    }

    return 0;
}

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    vector<string>::iterator ianswer;
    
    unsigned int str_size = my_str.size();                                          // my_str 사이즈 확인
    int excute_cnt = str_size / n;                                                  // 나머지가 0이 아니면 몫 + 1
    if (str_size % n != 0)
        excute_cnt++;

    int i, pos = 0;
    for (i = 0; i < excute_cnt; i++) {
        ianswer = answer.begin() + i;                                               // insert 위치 지정
        answer.insert(ianswer, my_str.substr(pos, n));
        pos += n;
    }
    return answer;
}

/* Best Source -------------------------------------------------------------
vector<string> solution(string my_str, int n) {
    vector<string> answer;
    for (int i=0; i<my_str.length(); i+=n){
        answer.push_back(my_str.substr(i,n));
    }
    return answer;
}
------------------------------------------------------------------------- */
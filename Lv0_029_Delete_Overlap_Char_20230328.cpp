#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 중복된 문자 제거
// 
// 문제 설명
// 문자열 my_string이 매개변수로 주어집니다. my_string에서 중복된 문자를 제거하고 하나의 문자만 남긴 문자열을 return하도록 solution 함수를 완성해주세요.
//
// 제한사항
// 1 ≤ my_string ≤ 110
// my_string은 대문자, 소문자, 공백으로 구성되어 있습니다.
// 대문자와 소문자를 구분합니다.
// 공백(" ")도 하나의 문자로 구분합니다.
// 중복된 문자 중 가장 앞에 있는 문자를 남깁니다.
// 
// 입출력 예
// my_string	        result
// "people"	            "peol"
// "We are the world"	"We arthwold"
//
//*************************************************************************************************************************************

string solution(string my_string) {
    unsigned int cnt = 0;
    bool chk_chr = false;
    while (cnt < my_string.size()) {
        char tmp_chr = my_string[cnt];
        for (unsigned int i = cnt; i < my_string.size(); i++) {
            if (tmp_chr == my_string[i]) {
                if (!chk_chr)
                    chk_chr = true;
                else {
                    my_string.replace(i, 1, "");
                    i--;                            //문자열 하나를 지웠기 때문에 i 카운트를 하나 빼줘야 다음 문자 비교 가능
                }
            }
        }
        chk_chr = false;
        cnt++;
    }
    return my_string;
}

int main() {
    string input_str;

    input_str = "people";
    printf("output string : %s\n", solution(input_str).c_str());

    input_str = "We are the world";
    printf("output string : %s\n", solution(input_str).c_str());

    input_str = "1aaaa2";
    printf("output string : %s\n", solution(input_str).c_str());

    input_str = "1a    aaa2";
    printf("output string : %s\n", solution(input_str).c_str());

    return 0;
}
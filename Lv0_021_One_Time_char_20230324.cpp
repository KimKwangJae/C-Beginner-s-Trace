#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 한 번만 등장한 문자
// 
// 문제 설명
// 문자열 s가 매개변수로 주어집니다. s에서 한 번만 등장하는 문자를 사전 순으로 정렬한 문자열을 return 하도록 solution 함수를 완성해보세요. 
// 한 번만 등장하는 문자가 없을 경우 빈 문자열을 return 합니다.
// 
// 제한사항
// 0 < s의 길이 < 1,000
// s는 소문자로만 이루어져 있습니다.
// 
// 입출력 예
// s	        result
//"abcabcadc"	"d"
//"abdc"	    "abcd"
//"hello"	    "eho"
//
//*************************************************************************************************************************************

string solution(string s) {
    string answer = "";

    int chk_cnt[999] = {0};
    char tmp_chr;
    for (unsigned int i = 0; i < s.size(); i++) {
        for (unsigned int j = 0; j < s.size(); j++) {
            if (s[i] == s[j]) {
                chk_cnt[i] += 1;
            }
        }
    }

    for (unsigned int k = 0; k < s.size(); k++) {
        printf("int array : chk_cnt[%d] : %d\n", k, chk_cnt[k]);
    }

    for (int k = 0; k <= 999; k++) {
        if (chk_cnt[k] == 1) {
            answer.push_back(s[k]);
        }
    }

    printf("before order answer : %s\n", answer.c_str());

    //Bubble Order Ascending
    for (unsigned int j = 0; j < answer.size() - 1; j++) {
        for (unsigned int i = 0; i < answer.size() - 1; i++) {
            if (answer[i] > answer[i + 1]) {
                char tmp_chr;
                tmp_chr = answer[i];
                answer[i] = answer[i + 1];
                answer[i + 1] = tmp_chr;
            }
        }
    }

    return answer;
}

int main() {
    string output_string;

    output_string = solution("abcabcadc");
    printf("Return String : %s\n", output_string.c_str());

    output_string = solution("abdc");
    printf("Return String : %s\n", output_string.c_str());

    output_string = solution("hello");
    printf("Return String : %s\n", output_string.c_str());

    return 0;
}
#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : �� ���� ������ ����
// 
// ���� ����
// ���ڿ� s�� �Ű������� �־����ϴ�. s���� �� ���� �����ϴ� ���ڸ� ���� ������ ������ ���ڿ��� return �ϵ��� solution �Լ��� �ϼ��غ�����. 
// �� ���� �����ϴ� ���ڰ� ���� ��� �� ���ڿ��� return �մϴ�.
// 
// ���ѻ���
// 0 < s�� ���� < 1,000
// s�� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
// 
// ����� ��
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
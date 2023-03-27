#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : �ߺ��� ���� ����
// 
// ���� ����
// ���ڿ� my_string�� �Ű������� �־����ϴ�. my_string���� �ߺ��� ���ڸ� �����ϰ� �ϳ��� ���ڸ� ���� ���ڿ��� return�ϵ��� solution �Լ��� �ϼ����ּ���.
//
// ���ѻ���
// 1 �� my_string �� 110
// my_string�� �빮��, �ҹ���, �������� �����Ǿ� �ֽ��ϴ�.
// �빮�ڿ� �ҹ��ڸ� �����մϴ�.
// ����(" ")�� �ϳ��� ���ڷ� �����մϴ�.
// �ߺ��� ���� �� ���� �տ� �ִ� ���ڸ� ����ϴ�.
// 
// ����� ��
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
                    i--;                            //���ڿ� �ϳ��� ������ ������ i ī��Ʈ�� �ϳ� ����� ���� ���� �� ����
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
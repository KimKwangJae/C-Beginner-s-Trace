#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : �빮�ڿ� �ҹ���
// 
// ���� ����
// ���ڿ� my_string�� �Ű������� �־��� ��, �빮�ڴ� �ҹ��ڷ� �ҹ��ڴ� �빮�ڷ� ��ȯ�� ���ڿ��� return�ϵ��� solution �Լ��� �ϼ����ּ���.
// 
// ���ѻ���
// 1 �� my_string�� ���� �� 1,000
// my_string�� ���� �빮�ڿ� �ҹ��ڷθ� �����Ǿ� �ֽ��ϴ�.
// 
// ����� ��
// my_string	result
// "cccCCC"	    "CCCccc"
// "abCdEfghIJ"	"ABcDeFGHij"
//
//*************************************************************************************************************************************

string solution(string my_string) {
    for (unsigned int i = 0; i < my_string.size(); i++) {
        if (my_string[i] < 91)   //�빮���̸�
            my_string[i] += 32;
        else                     //�ҹ����̸�
            my_string[i] -= 32;
    }
    return my_string;
}

int main() {
    string output_str;

    output_str = solution("cccCCC");
    printf("output string : %s\n", output_str.c_str());

    output_str = solution("abCdEfghIJ");
    printf("output string : %s\n", output_str.c_str());

    //char a, b;
    //a = 'a';    //97
    //b = 'A';    //65        (32 ����)

    //printf("a : %d\n", a);
    //printf("A : %d\n", b);

    //a = 'z';    //122
    //b = 'Z';    //90
    //printf("z : %d\n", a);
    //printf("Z : %d\n", b);

    return 0;
}
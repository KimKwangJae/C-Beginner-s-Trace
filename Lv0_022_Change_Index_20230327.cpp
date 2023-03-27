#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : �ε��� �ٲٱ�
// 
// ���� ����
// ���ڿ� my_string�� ���� num1, num2�� �Ű������� �־��� ��, my_string���� �ε��� num1�� �ε��� num2�� �ش��ϴ� ���ڸ� �ٲ� ���ڿ��� return �ϵ��� solution �Լ��� �ϼ��غ�����.
// 
// ���ѻ���
// 1 < my_string�� ���� < 100
// 0 �� num1, num2 < my_string�� ����
//     my_string�� �ҹ��ڷ� �̷���� �ֽ��ϴ�.
//     num1 �� num2
// 
// ����� ��
// my_string	num1	num2	result
// "hello"	    1	    2	    "hlelo"
// "I love you"	3	    6	    "I l veoyou"
//
//*************************************************************************************************************************************

string solution(string my_string, int num1, int num2) {
    char tmp_chr;
    tmp_chr = my_string[num1];
    my_string[num1] = my_string[num2];
    my_string[num2] = tmp_chr;
    return my_string;
}

int main() {
    string output_str;

    output_str = solution("hello", 1, 2);
    printf("%s\n", output_str.c_str());

    output_str = solution("I love you", 3, 6);
    printf("%s\n", output_str.c_str());
    
    return 0;
}
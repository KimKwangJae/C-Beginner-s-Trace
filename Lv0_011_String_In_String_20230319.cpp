#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : ���ڿ��ȿ� ���ڿ�
// 
// ���� ����
// ���ڿ� str1, str2�� �Ű������� �־����ϴ�. str1 �ȿ� str2�� �ִٸ� 1�� ���ٸ� 2�� return�ϵ��� solution �Լ��� �ϼ����ּ���.
// 
// ���ѻ���
// 1 �� str1�� ���� �� 100
// 1 �� str2�� ���� �� 100
// ���ڿ��� ���ĺ� �빮��, �ҹ���, ���ڷ� �����Ǿ� �ֽ��ϴ�.
// 
// ����� ��
// str1	str2	result
// "ab6CDE443fgh22iJKlmn1o"	"6CD"	1
// "ppprrrogrammers"	"pppp"	2
// "AbcAbcA"	"AAA"	2
//
//*************************************************************************************************************************************

int solution(string str1, string str2) {
    int answer = 0;

    if (str1.find(str2) != -1)
        answer = 1;
    else
        answer = 2;

    return answer;
}

int main() {

    string a = "abcdefgh";

    int rtn = a.find("bcd");
    printf("%d\n", rtn);

    rtn = a.find("bcf");
    printf("%d\n", rtn);

    return 0;
}
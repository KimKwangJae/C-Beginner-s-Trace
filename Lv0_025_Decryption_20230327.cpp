#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : ��ȣ �ص�
// 
// ���� ����
// �� ������ �Ӿ��̴� ���� �� ������ ������ ���� ��ȣ ü�踦 ����Ѵٴ� ���� �˾Ƴ½��ϴ�.
// ��ȣȭ�� ���ڿ� cipher�� �ְ�޽��ϴ�.
// �� ���ڿ����� code�� ��� ��° ���ڸ� ��¥ ��ȣ�Դϴ�.
// ���ڿ� cipher�� ���� code�� �Ű������� �־��� �� �ص��� ��ȣ ���ڿ��� return�ϵ��� solution �Լ��� �ϼ����ּ���.
//
// ���ѻ���
// 1 �� cipher�� ���� �� 1,000
// 1 �� code �� cipher�� ����
// cipher�� �ҹ��ڿ� �������θ� �����Ǿ� �ֽ��ϴ�.
// ���鵵 �ϳ��� ���ڷ� ����մϴ�.
// 
// ����� ��
// cipher	                    code	result
// "dfjardstddetckdaccccdegk"	4	    "attack"
// "pfqallllabwaoclk"	        2	    "fallback"
//
//*************************************************************************************************************************************

string solution(string cipher, int code) {
    string answer = "";

    for (unsigned int i = code; i <= cipher.size(); i+=code) {
        answer.push_back(cipher[i - 1]);
        printf("[%u/%u] answer : %s\n", i, cipher.size(), answer.c_str());
    }

    return answer;
}

int main() {

    string output_str;
    output_str = solution("dfjardstddetckdaccccdegk", 4);
    printf("output string : %s\n", output_str.c_str());

    output_str = solution("pfqallllabwaoclk", 2);
    printf("output string : %s\n", output_str.c_str());

    return 0;
}
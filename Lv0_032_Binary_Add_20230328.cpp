#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : ������ ���ϱ�
// 
// ���� ����
// �������� �ǹ��ϴ� �� ���� ���ڿ� bin1�� bin2�� �Ű������� �־��� ��, �� �������� ���� return�ϵ��� solution �Լ��� �ϼ����ּ���.
//
// ���ѻ���
// return ���� �������� �ǹ��ϴ� ���ڿ��Դϴ�.
// 1 �� bin1, bin2�� ���� �� 10
// bin1�� bin2�� 0�� 1�θ� �̷���� �ֽ��ϴ�.
// bin1�� bin2�� "0"�� �����ϰ� 0���� �������� �ʽ��ϴ�.
// 
// ����� ��
// bin1	    bin2	result
// "10"	    "11"	"101"
// "1001"	"1111"	"11000"
//
//*************************************************************************************************************************************

string solution(string bin1, string bin2) {
    string answer = "";
    string answer_rev = "";

    //----------------------------------------------------------------
    //reverse bin1, bin2
    string bin1_rev, bin2_rev;
    for (int i = bin1.size()-1; i >= 0; i--)
        bin1_rev.push_back(bin1[i]);
    for (int i = bin2.size()-1; i >= 0; i--)
        bin2_rev.push_back(bin2[i]);
    //----------------------------------------------------------------


    unsigned int x = bin1_rev.size() > bin2_rev.size() ? bin1_rev.size() : bin2_rev.size();     // �� �� ū ��
    int sum = 0, up_add = 0;
    for (unsigned int i = 0; i < x; i++) {
        if (bin1_rev.size()-1 >= i) {
            if (bin1_rev[i] == '1')  sum += 1;
        }

        if (bin2_rev.size() - 1 >= i) {
            if (bin2_rev[i] == '1')  sum += 1;
        }

        sum += up_add;

        switch (sum) {
            case 0:
                answer_rev.push_back('0');
                up_add = 0;
                break;
            case 1:
                answer_rev.push_back('1');
                up_add = 0;
                break;
            case 2:
                answer_rev.push_back('0');
                up_add = 1;
                break;
            case 3:
                answer_rev.push_back('1');
                up_add = 1;
                break;
        }

        if (i == x - 1 && up_add == 1)
            answer_rev.push_back('1');

        sum = 0;
    }

    printf("answer reverse : %s\n", answer_rev.c_str());

    for (int i = answer_rev.size() - 1; i >= 0; i--)
        answer.push_back(answer_rev[i]);

    return answer;
}

int main() {
    printf("output : %s\n", solution("10", "11").c_str());
    printf("output : %s\n", solution("1001", "1111").c_str());
    return 0;
}
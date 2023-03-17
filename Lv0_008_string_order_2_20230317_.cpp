#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : ���ڿ� �����ϱ� (2)
// 
// ���� ����
// ���� ��ҹ��ڷ� �̷���� ���ڿ� my_string�� �Ű������� �־��� ��, my_string�� ��� �ҹ��ڷ� �ٲٰ� ���ĺ� ������� ������ ���ڿ��� return �ϵ��� solution �Լ��� �ϼ��غ�����.
// 
// ���ѻ���
// 0 < my_string ���� < 100
// 
// ����� ��
// my_string	result
// "Bcad"	"abcd"
// "heLLo"	"ehllo"
// "Python"	"hnopty"
//*************************************************************************************************************************************

// �빮�� A~Z (65~90)
// �ҹ��� a~z (97~122)

string solution(string my_string) {
    printf("-----------------------------------------------------\n");
    printf("[before] %s\n", my_string.c_str());

    //������ �������� 91���� ������ �빮�� --> �ҹ��� ��ȯ --> "+32"
    //������ �������� 91���� ũ�ų� ������ PASS

    //�ҹ��� ��ȯ
    unsigned int i, j, k, str_size = my_string.size();
    for (i = 0; i < str_size; i++) {
        if (my_string[i] < 91)
            my_string[i] += 32;
    }

    printf("[Cap change] %s\n", my_string.c_str());

    //����
    char chr_bk = '\n';
    for (j = 0; j < str_size; j++) {
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

        printf("[%d] Char : %c(%d)\n", j, my_string[j], my_string[j]);
        for (k = j; k < str_size; k++) {
            printf(">>>>>>>>>>>>>>>>\n");
            printf("[Compare] %c(%d) <-> %c(%d) ", my_string[j], my_string[j], my_string[k], my_string[k]);

            if (my_string[j] > my_string[k]) {
                chr_bk = my_string[j];
                my_string[j] = my_string[k];
                my_string[k] = chr_bk;
            }

            printf("[S_Result] %c(%d)\n", my_string[j], my_string[j]);
        }
        printf("[L_Result] %c(%d) (%s)\n", my_string[j], my_string[j], my_string.c_str());
    }

    printf("[after] %s\n", my_string.c_str());

    return my_string;
}

int main() {
    string input_str, rtn;

    input_str = "Bcad";
    rtn = solution(input_str);

    input_str = "heLLo";
    rtn = solution(input_str);

    input_str = "Python";
    rtn = solution(input_str);

    return 0;
}
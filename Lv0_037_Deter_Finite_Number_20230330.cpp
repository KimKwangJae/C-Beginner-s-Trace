#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : ���ѼҼ� �Ǻ��ϱ�
// 
// ���� ����
// �Ҽ��� �Ʒ� ���ڰ� ��ӵ��� �ʰ� ���Ѱ��� �Ҽ��� ���ѼҼ���� �մϴ�. �м��� �Ҽ��� ��ĥ �� ���ѼҼ��� ��Ÿ�� �� �ִ� �м����� �Ǻ��Ϸ��� �մϴ�. 
// ���ѼҼ��� �Ǳ� ���� �м��� ������ ������ �����ϴ�.
// ���м��� ��Ÿ������ ��, �и��� ���μ��� 2�� 5�� �����ؾ� �մϴ�.
// �� ���� a�� b�� �Ű������� �־��� ��, a / b�� ���ѼҼ��̸� 1��, ���ѼҼ���� 2�� return�ϵ��� solution �Լ��� �ϼ����ּ���.
//
// ���ѻ���
// a, b�� ����
// 0 < a �� 1, 000
// 0 < b �� 1, 000
// 
// ����� ��
// a	  b	    result
// 7	  20	1
// 11	  22	1
// 12	  21	2
//
//*************************************************************************************************************************************

int solution(int a, int b) {
    int answer = 1;
    
    // ����, �и��� �ִ����� ���ϱ�
    vector<int> a_vec;
    for (int i = 1; i <= a; i++) {
        if (a % i == 0)
            a_vec.push_back(i);
    }
    vector<int> b_vec;
    for (int i = 1; i <= b; i++) {
        if (b % i == 0)
            b_vec.push_back(i);
    }

    //------------------------------------------------------
    for (int z = 0; z < (int)a_vec.size(); z++) {
        printf("%d ", a_vec[z]);
    }
    printf("\n");
    for (int z = 0; z < (int)b_vec.size(); z++) {
        printf("%d ", b_vec[z]);
    }
    printf("\n\n");
    //------------------------------------------------------
    
    //��� (���� ����Ʈ)
    int divide_n = 0;
    for (int i = a_vec.size()-1; i >= 0; i--) {
        for (int j = b_vec.size()-1; j >= 0; j--) {
            if (a_vec[i] == b_vec[j]) {
                divide_n = a_vec[i];
                break;
            }
        }
        if (divide_n != 0)
            break;
    }
    if (divide_n != 0) {
        a = a / divide_n;
        b = b / divide_n;
    }

    // �и� ���μ� ���ϱ�
    b_vec.clear();
    for (int i = 2; i <= b; i++) {
        if (b % i == 0) {
            bool sosu = true;
            for (int j = 2; j <= i-1; j++) {
                //�Ҽ��Ǻ�
                if (i % j == 0) {
                    sosu = false;
                }
            }
            if(sosu)
                b_vec.push_back(i);
        }
    }

    //------------------------------------------------------
    printf("�ִ����� : %d\n", divide_n);
    printf("a : %d\n", a);
    printf("b : %d\n", b);
    for (int z = 0; z < (int)b_vec.size(); z++) {
        printf("%d ", b_vec[z]);
    }
    printf("\n\n");
    //------------------------------------------------------

    for (int i = 0; i < (int)b_vec.size(); i++) {
        if (b_vec[i] != 2 && b_vec[i] != 5) {
            answer = 2;
            break;
        }
    }

    return answer;
}

int main() {
    printf("output (7, 20) : %d\n", solution(7, 20));
    printf("-----------------------------------------------------------\n");
    printf("output (11, 22) : %d\n", solution(11, 22));
    printf("-----------------------------------------------------------\n");
    printf("output (12, 21) : %d\n", solution(12, 21));
    return 0;
}
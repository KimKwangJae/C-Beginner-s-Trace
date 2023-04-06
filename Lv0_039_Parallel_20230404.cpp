#include <string>
#include <vector>
#include <cmath>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : ����
// 
// ���� ����
// �� �� ���� ��ǥ�� ���� ������ �迭  dots�� ������ ���� �Ű������� �־����ϴ�.
// [[x1, y1], [x2, y2], [x3, y3], [x4, y4]]
// �־��� �� ���� ���� �� ���� �̾��� ��, �� ������ ������ �Ǵ� ��찡 ������ 1�� ������ 0�� return �ϵ��� solution �Լ��� �ϼ��غ�����.
//
// ���ѻ���
// dots�� ���� = 4
// dots�� ���Ҵ�[x, y] �����̸� x, y�� �����Դϴ�.
// 0 �� x, y �� 100
// ���� �ٸ� �ΰ� �̻��� ���� ��ġ�� ���� �����ϴ�.
// �� ������ ��ġ�� ���(��ġ�ϴ� ���)���� 1�� return ���ּ���.
// ������ �� ���� ���� ������ x�� �Ǵ� y��� ������ ���� �־����� �ʽ��ϴ�.
// 
// ����� ��
// dots	                                result
// [[1, 4], [9, 2], [3, 8], [11, 6]]    1
// [[3, 5], [4, 1], [2, 4], [5, 10]]    0
//
//*************************************************************************************************************************************

int solution(vector<vector<int>> dots) {
    int answer = 0;

    float incline_case_1_1, incline_case_2_1, incline_case_3_1,incline_case_1_2, incline_case_2_2, incline_case_3_2;
    float x1, x2, x3, x4, y1, y2, y3, y4;
    //a ------------------------
    x1 = (float)dots[0][0];
    y1 = (float)dots[0][1];
    //b ------------------------
    x2 = (float)dots[1][0];
    y2 = (float)dots[1][1];
    //c ------------------------
    x3 = (float)dots[2][0];
    y3 = (float)dots[2][1];
    //d ------------------------
    x4 = (float)dots[3][0];
    y4 = (float)dots[3][1];
    
    //[a-b, c-d] ------------------------------
    incline_case_1_1 = (y2 - y1) / (x2 - x1);
    incline_case_1_2 = (y4 - y3) / (x4 - x3);
    //[a-c, b-d] ------------------------------
    incline_case_2_1 = (y3 - y1) / (x3 - x1);
    incline_case_2_2 = (y4 - y2) / (x4 - x2);
    //[a-d, b-c] ------------------------------
    incline_case_3_1 = (y4 - y1) / (x4 - x1);
    incline_case_3_2 = (y3 - y2) / (x3 - x2);

    if (incline_case_1_1 == incline_case_1_2 || incline_case_2_1 == incline_case_2_2 || incline_case_3_1 == incline_case_3_2)
        answer = 1;

    return answer;
}

int main() {
    vector<vector<int>> input_dots;
    input_dots = { {1,4}, {9,2}, {3,8}, {11,6} };
    printf("output : %d\n", solution(input_dots));      // 1
    printf("------------------------------------------------------------\n");
    input_dots = { {3,5}, {4,1}, {2,4}, {5,10} };
    printf("output : %d\n", solution(input_dots));      // 0

    //float a = 1.24;
    //float b = 1.25;
    //float c = 1.26;

    //printf("(1.24 rounding) a : %f\n", round(a * 10) / 10);
    //printf("(1.25 rounding) b : %f\n", round(b * 10) / 10);
    //printf("(1.26 rounding) c : %f\n", round(c * 10) / 10);

    //a = round(a * 10) / 10;
    //b = round(b * 10) / 10;
    //c = round(c * 10) / 10;

    //if (b == c)
    //    printf("b==c\n");       //<--- This Condition is Right!
    //else
    //    printf("b!=c\n");

    //printf("incline : %f\n", (2.0-4.0) / (9.0-1.0));

    return 0;
}

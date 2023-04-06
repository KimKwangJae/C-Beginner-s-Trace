#include <string>
#include <vector>
#include <cmath>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 평행
// 
// 문제 설명
// 점 네 개의 좌표를 담은 이차원 배열  dots가 다음과 같이 매개변수로 주어집니다.
// [[x1, y1], [x2, y2], [x3, y3], [x4, y4]]
// 주어진 네 개의 점을 두 개씩 이었을 때, 두 직선이 평행이 되는 경우가 있으면 1을 없으면 0을 return 하도록 solution 함수를 완성해보세요.
//
// 제한사항
// dots의 길이 = 4
// dots의 원소는[x, y] 형태이며 x, y는 정수입니다.
// 0 ≤ x, y ≤ 100
// 서로 다른 두개 이상의 점이 겹치는 경우는 없습니다.
// 두 직선이 겹치는 경우(일치하는 경우)에도 1을 return 해주세요.
// 임의의 두 점을 이은 직선이 x축 또는 y축과 평행한 경우는 주어지지 않습니다.
// 
// 입출력 예
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

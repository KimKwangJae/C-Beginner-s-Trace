#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 겹치는 선분의 길이
// 
// 문제 설명
// 선분 3개가 평행하게 놓여 있습니다. 세 선분의 시작과 끝 좌표가 [[start, end], [start, end], [start, end]] 형태로 들어있는 
// 2차원 배열 lines가 매개변수로 주어질 때, 두 개 이상의 선분이 겹치는 부분의 길이를 return 하도록 solution 함수를 완성해보세요.
//
// 제한사항
// lines의 길이 = 3
// lines의 원소의 길이 = 2
// 모든 선분은 길이가 1 이상입니다.
// lines의 원소는[a, b] 형태이며, a, b는 각각 선분의 양 끝점 입니다.
// - 100 ≤ a < b ≤ 100
// 
// 입출력 예
// lines	                    result
// [[0, 1], [2, 5], [3, 9]]     2
// [[-1, 1], [1, 3], [3, 9]]    0
// [[0, 5], [3, 9], [1, 10]]    8
//
//*************************************************************************************************************************************

int solution(vector<vector<int>> lines) {
    int answer = 0;

    vector<int> line_mark;
    vector<vector<int>> lines_mark;         //예시) {{-1, 0, mark}, {0, 1, mark}, {1, 2, mark}}
    //1. 각 선분의 원소를 집합으로 저장
    //2. 겹치는 선분에 마크! (선분이 아닌 경우에도 정수 중복 마크될 수 있음!)
    for (unsigned int i = 0; i < lines.size(); i++) {
        bool exist_chk = false;

        for (int j = lines[i][0]; j <= lines[i][1]-1; j++) {
            //Init
            line_mark.clear();
            exist_chk = false;

            for (int k = 0; k < lines_mark.size(); k++) {
                if (lines_mark[k][0] == j && lines_mark[k][1] == j+1) {
                    exist_chk = true;
                    lines_mark[k][2] += 1;
                }
            }

            //중복 원소가 아닌 경우만 push_back() 실행
            if (!exist_chk) {
                line_mark.push_back(j);
                line_mark.push_back(j+1);
                line_mark.push_back(1);
                lines_mark.push_back(line_mark);
            }
        }
    }

    //printf로 lines_mark vector 결과 검사
    printf("duplicate write vector\n");
    for (unsigned int i = 0; i < lines_mark.size(); i++) {
        printf("(Number : %d, Number : %d, Count : %d)\n", lines_mark[i][0], lines_mark[i][1], lines_mark[i][2]);
    }

    //2개 이상 마크된 선분 Count --> answer
    vector<int> line_order;
    for (unsigned int i = 0; i < lines_mark.size(); i++) {
        if (lines_mark[i][2] > 1) {
            //line_order.push_back(lines_mark[i][0]);
            answer += 1;
        }
    }
    
    printf("----------------------------\n");

    return answer;
}

int main() {
    printf("----------------------------------------------\n");
    printf("output : %d\n", solution({{0,1},{2,5},{3,9}}));            //2
    printf("----------------------------------------------\n");
    printf("output : %d\n", solution({ {-1,1},{1,3},{3,9} }));         //0
    printf("----------------------------------------------\n");
    printf("output : %d\n", solution({ {0,5},{3,9},{1,10} }));         //8
    printf("----------------------------------------------\n");
    printf("output : %d\n", solution({ {-1,1},{-1,1},{-1,1} }));       //2
    printf("----------------------------------------------\n");
    printf("output : %d\n", solution({ {-1,0},{-1,1},{1,2} }));        //1
    printf("----------------------------------------------\n");
    printf("output : %d\n", solution({ {-100,-99},{0,1},{99,100} }));  //0
    return 0;
}

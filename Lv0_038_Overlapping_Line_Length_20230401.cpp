#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : ��ġ�� ������ ����
// 
// ���� ����
// ���� 3���� �����ϰ� ���� �ֽ��ϴ�. �� ������ ���۰� �� ��ǥ�� [[start, end], [start, end], [start, end]] ���·� ����ִ� 
// 2���� �迭 lines�� �Ű������� �־��� ��, �� �� �̻��� ������ ��ġ�� �κ��� ���̸� return �ϵ��� solution �Լ��� �ϼ��غ�����.
//
// ���ѻ���
// lines�� ���� = 3
// lines�� ������ ���� = 2
// ��� ������ ���̰� 1 �̻��Դϴ�.
// lines�� ���Ҵ�[a, b] �����̸�, a, b�� ���� ������ �� ���� �Դϴ�.
// - 100 �� a < b �� 100
// 
// ����� ��
// lines	                    result
// [[0, 1], [2, 5], [3, 9]]     2
// [[-1, 1], [1, 3], [3, 9]]    0
// [[0, 5], [3, 9], [1, 10]]    8
//
//*************************************************************************************************************************************

int solution(vector<vector<int>> lines) {
    int answer = 0;

    vector<int> line_mark;
    vector<vector<int>> lines_mark;         //����) {{-1, 0, mark}, {0, 1, mark}, {1, 2, mark}}
    //1. �� ������ ���Ҹ� �������� ����
    //2. ��ġ�� ���п� ��ũ! (������ �ƴ� ��쿡�� ���� �ߺ� ��ũ�� �� ����!)
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

            //�ߺ� ���Ұ� �ƴ� ��츸 push_back() ����
            if (!exist_chk) {
                line_mark.push_back(j);
                line_mark.push_back(j+1);
                line_mark.push_back(1);
                lines_mark.push_back(line_mark);
            }
        }
    }

    //printf�� lines_mark vector ��� �˻�
    printf("duplicate write vector\n");
    for (unsigned int i = 0; i < lines_mark.size(); i++) {
        printf("(Number : %d, Number : %d, Count : %d)\n", lines_mark[i][0], lines_mark[i][1], lines_mark[i][2]);
    }

    //2�� �̻� ��ũ�� ���� Count --> answer
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

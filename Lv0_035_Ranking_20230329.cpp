#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : ��� �ű��
// 
// ���� ����
// ���� ������ ���� ������ ��� ������ �������� �л����� ����� �ű���� �մϴ�. 
// ���� ������ ���� ������ ���� 2���� ���� �迭 score�� �־��� ��, 
// ���� ������ ���� ������ ����� �������� �ű� ����� ���� �迭�� return�ϵ��� solution �Լ��� �ϼ����ּ���.
//
// ���ѻ���
// 0 �� score[0], score[1] �� 100
// 1 �� score�� ���� �� 10
// score�� ���� ���̴� 2�Դϴ�.
// score�� �ߺ��� ���Ҹ� ���� �ʽ��ϴ�.
// 
// ����� ��
// score	                                                                            result
// [[80, 70], [90, 50], [40, 70], [50, 80]]                                             [1, 2, 4, 3]
// [[80, 70], [70, 80], [30, 50], [90, 100], [100, 90], [100, 100], [10, 30]]           [4, 4, 6, 2, 2, 1, 7]
//
//*************************************************************************************************************************************

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;

    //------------------------------------------------------------------------ ���� �� ��հ� printf
    vector<float> answer_vec_order;
    vector<float> answer_vec_not_order;
    for (unsigned int i = 0; i < score.size(); i++) {
        float average_value = ((float)score[i][0] + (float)score[i][1]) / 2;
        answer_vec_order.push_back(average_value);
        answer_vec_not_order.push_back(average_value);
        printf("%.1f ", answer_vec_order[i]);
    }

    printf("\n\n");

    //------------------------------------------------------------------------ �������� ����
    for (unsigned int i = 0; i < answer_vec_order.size() - 1; i++) {
        for (unsigned int j = 0; j < answer_vec_order.size() - 1; j++) {
            if (answer_vec_order[j] < answer_vec_order[j + 1]) {
                float tmp;
                tmp = answer_vec_order[j];
                answer_vec_order[j] = answer_vec_order[j + 1];
                answer_vec_order[j + 1] = tmp;
            }
        }
    }

    //------------------------------------------------------------------------  ���� �� ��հ� printf
    for (unsigned int i = 0; i < answer_vec_order.size(); i++) {
        printf("%.1f ", answer_vec_order[i]);
    }

    printf("\n\n");

    //------------------------------------------------------------------------ �� ��հ��� �ߺ� ���� ����
    vector < vector<float>> answer_order_cnt;
    vector<float> tmp_vector;
    for (unsigned int i = 0; i < answer_vec_order.size(); i++) {
        
        int chk_cnt = 0;
        for (unsigned int j = 0; j < answer_vec_order.size(); j++) {
            if (answer_vec_order[i] == answer_vec_order[j])
                chk_cnt++;
        }
        tmp_vector.push_back(answer_vec_order[i]);      //��հ�
        tmp_vector.push_back(chk_cnt);                  //�ߺ� ����
        tmp_vector.push_back(0);                        //���� ��� ���

        answer_order_cnt.push_back(tmp_vector);

        tmp_vector.clear();      //Init
        chk_cnt = 0;             //Init
    }

    //------------------------------------------------------------------------  �� ��հ��� �ߺ� ���� ���� printf
    for (unsigned int i = 0; i < answer_order_cnt.size(); i++) {
        //printf("%.1f - %.1f - %.1f / ", answer_order_cnt[i][0], answer_order_cnt[i][1], answer_order_cnt[i][2]);
    }

    //printf("\n\n");

    //------------------------------------------------------------------------ Rank �ۼ�
    //answer_vec_not_order
    int rank = 1;
    int offset = 0;
    for (unsigned int i = 0; i < answer_order_cnt.size(); i++) {
        if (answer_order_cnt[i][1] == 1) {                                                          // �ߺ����� ������ ��� (rank ����)
            rank += offset;
            answer_order_cnt[i][2] = rank;
            offset = 0;
        }
        else {
            if (i == 0) {                                                                           // ù ��° ���� �ߺ��� ��� (rank '1' �Է�)
                answer_order_cnt[i][2] = rank;
                offset++;
                continue;
            }
            if (i > 0 && ( answer_order_cnt[i - 1][0] == answer_order_cnt[i][0] ) ) {               // ù ��° �� ���� ���� �ߺ� & ������ ������ ��� (rank ���� & offset ����)
                answer_order_cnt[i][2] = rank;
                offset++;
                continue;
            }
            if (i > 0 && ( answer_order_cnt[i-1][0] != answer_order_cnt[i][0] ) ){                  // ù ��° �� ���� ���� �ߺ� & �ٸ� ������ ��� (rank ���� & offset '1' �ʱ�ȭ)
                rank += offset;
                answer_order_cnt[i][2] = rank;
                offset = 1;                     // ���Ӱ� �ߺ� ����� ���۵ǹǷ� offset 1�� �ʱ�ȭ
                continue;
            }
        }
        rank++;
    }

    //------------------------------------------------------------------------  �� ��հ��� �ߺ� ���� ���� printf
    for (unsigned int i = 0; i < answer_order_cnt.size(); i++) {
        printf("%.1f - %.1f - %.1f / ", answer_order_cnt[i][0], answer_order_cnt[i][1], answer_order_cnt[i][2]);
    }

    printf("\n\n");

    //------------------------------------------------------------------------  �� ��հ��� �ߺ� ���� ���� printf
    for (unsigned int i = 0; i < answer_vec_not_order.size(); i++) {
        for (unsigned int j = 0; j < answer_vec_not_order.size(); j++) {
            if (answer_vec_not_order[i] == answer_order_cnt[j][0]) {
                answer.push_back(answer_order_cnt[j][2]);
                break;
            }
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> input_score;
    vector<int> output_score;

    input_score = { {80, 70}, {90,50}, {40,70}, {50,80} };
    output_score = solution(input_score);
    for (unsigned int i = 0; i < output_score.size(); i++) {
        printf("%d ", output_score[i]);
    }

    printf("\n\n");

    input_score = { {80, 70}, {90,50}, {40,70}, {50,80} , {50,80} };
    output_score = solution(input_score);
    for (unsigned int i = 0; i < output_score.size(); i++) {
        printf("%d ", output_score[i]);
    }

    printf("\n\n");

    input_score = { {80, 70}, {70, 80}, {30, 50}, {90, 100}, {100, 90}, {100, 100}, {10, 30} };         //�ߺ��� 2�� �����ϴ� Rank
    output_score = solution(input_score);
    for (unsigned int i = 0; i < output_score.size(); i++) {
        printf("%d ", output_score[i]);
    }

    printf("\n\n");

    input_score = { {80, 70}, {70, 80}, {30, 50}, {50, 30}, {100, 90}, {90, 100}};                      //��� �ߺ��� �����ϴ� Rank
    output_score = solution(input_score);
    for (unsigned int i = 0; i < output_score.size(); i++) {
        printf("%d ", output_score[i]);
    }

    printf("\n\n");

    input_score = { {1,1}, {2,1}, {3,1}, {4,1}, {5,1}, {6,1}, {7,1}, {8,1}, {9,1}, {0,0} };                      
    output_score = solution(input_score);
    for (unsigned int i = 0; i < output_score.size(); i++) {
        printf("%d ", output_score[i]);
    }

    printf("\n\n");

    input_score = { {1, 3}, {3, 1}, {2, 3}, {3, 2}, {1, 2}, {0, 0} };
    output_score = solution(input_score);
    for (unsigned int i = 0; i < output_score.size(); i++) {
        printf("%d ", output_score[i]);
    }

    printf("\n\n");

    return 0;
}
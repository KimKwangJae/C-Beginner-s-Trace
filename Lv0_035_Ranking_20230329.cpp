#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 등수 매기기
// 
// 문제 설명
// 영어 점수와 수학 점수의 평균 점수를 기준으로 학생들의 등수를 매기려고 합니다. 
// 영어 점수와 수학 점수를 담은 2차원 정수 배열 score가 주어질 때, 
// 영어 점수와 수학 점수의 평균을 기준으로 매긴 등수를 담은 배열을 return하도록 solution 함수를 완성해주세요.
//
// 제한사항
// 0 ≤ score[0], score[1] ≤ 100
// 1 ≤ score의 길이 ≤ 10
// score의 원소 길이는 2입니다.
// score는 중복된 원소를 갖지 않습니다.
// 
// 입출력 예
// score	                                                                            result
// [[80, 70], [90, 50], [40, 70], [50, 80]]                                             [1, 2, 4, 3]
// [[80, 70], [70, 80], [30, 50], [90, 100], [100, 90], [100, 100], [10, 30]]           [4, 4, 6, 2, 2, 1, 7]
//
//*************************************************************************************************************************************

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;

    //------------------------------------------------------------------------ 정렬 전 평균값 printf
    vector<float> answer_vec_order;
    vector<float> answer_vec_not_order;
    for (unsigned int i = 0; i < score.size(); i++) {
        float average_value = ((float)score[i][0] + (float)score[i][1]) / 2;
        answer_vec_order.push_back(average_value);
        answer_vec_not_order.push_back(average_value);
        printf("%.1f ", answer_vec_order[i]);
    }

    printf("\n\n");

    //------------------------------------------------------------------------ 내림차순 정렬
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

    //------------------------------------------------------------------------  정렬 후 평균값 printf
    for (unsigned int i = 0; i < answer_vec_order.size(); i++) {
        printf("%.1f ", answer_vec_order[i]);
    }

    printf("\n\n");

    //------------------------------------------------------------------------ 각 평균값의 중복 수량 점검
    vector < vector<float>> answer_order_cnt;
    vector<float> tmp_vector;
    for (unsigned int i = 0; i < answer_vec_order.size(); i++) {
        
        int chk_cnt = 0;
        for (unsigned int j = 0; j < answer_vec_order.size(); j++) {
            if (answer_vec_order[i] == answer_vec_order[j])
                chk_cnt++;
        }
        tmp_vector.push_back(answer_vec_order[i]);      //평균값
        tmp_vector.push_back(chk_cnt);                  //중복 개수
        tmp_vector.push_back(0);                        //최종 출력 등수

        answer_order_cnt.push_back(tmp_vector);

        tmp_vector.clear();      //Init
        chk_cnt = 0;             //Init
    }

    //------------------------------------------------------------------------  각 평균값의 중복 수량 점검 printf
    for (unsigned int i = 0; i < answer_order_cnt.size(); i++) {
        //printf("%.1f - %.1f - %.1f / ", answer_order_cnt[i][0], answer_order_cnt[i][1], answer_order_cnt[i][2]);
    }

    //printf("\n\n");

    //------------------------------------------------------------------------ Rank 작성
    //answer_vec_not_order
    int rank = 1;
    int offset = 0;
    for (unsigned int i = 0; i < answer_order_cnt.size(); i++) {
        if (answer_order_cnt[i][1] == 1) {                                                          // 중복없는 숫자인 경우 (rank 변경)
            rank += offset;
            answer_order_cnt[i][2] = rank;
            offset = 0;
        }
        else {
            if (i == 0) {                                                                           // 첫 번째 값이 중복인 경우 (rank '1' 입력)
                answer_order_cnt[i][2] = rank;
                offset++;
                continue;
            }
            if (i > 0 && ( answer_order_cnt[i - 1][0] == answer_order_cnt[i][0] ) ) {               // 첫 번째 값 이후 부터 중복 & 동일한 숫자인 경우 (rank 유지 & offset 증가)
                answer_order_cnt[i][2] = rank;
                offset++;
                continue;
            }
            if (i > 0 && ( answer_order_cnt[i-1][0] != answer_order_cnt[i][0] ) ){                  // 첫 번째 값 이후 부터 중복 & 다른 숫자인 경우 (rank 변경 & offset '1' 초기화)
                rank += offset;
                answer_order_cnt[i][2] = rank;
                offset = 1;                     // 새롭게 중복 대상이 시작되므로 offset 1로 초기화
                continue;
            }
        }
        rank++;
    }

    //------------------------------------------------------------------------  각 평균값의 중복 수량 점검 printf
    for (unsigned int i = 0; i < answer_order_cnt.size(); i++) {
        printf("%.1f - %.1f - %.1f / ", answer_order_cnt[i][0], answer_order_cnt[i][1], answer_order_cnt[i][2]);
    }

    printf("\n\n");

    //------------------------------------------------------------------------  각 평균값의 중복 수량 점검 printf
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

    input_score = { {80, 70}, {70, 80}, {30, 50}, {90, 100}, {100, 90}, {100, 100}, {10, 30} };         //중복이 2개 존재하는 Rank
    output_score = solution(input_score);
    for (unsigned int i = 0; i < output_score.size(); i++) {
        printf("%d ", output_score[i]);
    }

    printf("\n\n");

    input_score = { {80, 70}, {70, 80}, {30, 50}, {50, 30}, {100, 90}, {90, 100}};                      //모두 중복이 존재하는 Rank
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
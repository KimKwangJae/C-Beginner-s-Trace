#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 옹알이1
// 
// 문제 설명
// 머쓱이는 태어난 지 6개월 된 조카를 돌보고 있습니다.
// 조카는 아직 "aya", "ye", "woo", "ma" 네 가지 발음을 최대 한 번씩 사용해 조합한(이어 붙인) 발음밖에 하지 못합니다.
// 문자열 배열 babbling이 매개변수로 주어질 때, 머쓱이의 조카가 발음할 수 있는 단어의 개수를 return하도록 solution 함수를 완성해주세요.
// 
// 제한사항
// 1 ≤ babbling의 길이 ≤ 100
// 1 ≤ babbling[i]의 길이 ≤ 15
// babbling의 각 문자열에서 "aya", "ye", "woo", "ma"는 각각 최대 한 번씩만 등장합니다.
// 즉, 각 문자열의 가능한 모든 부분 문자열 중에서 "aya", "ye", "woo", "ma"가 한 번씩만 등장합니다.
// 문자열은 알파벳 소문자로만 이루어져 있습니다.
// 
// 날짜 : 2023.03.05
// 포인트 : 문자열 처리 (내 주관적 생각)
//*************************************************************************************************************************************

// 주어진 함수 (내부에 Logic 구현)
int solution(vector<string> babbling);




int main() {

	//-----------------------------------------------------------------------------------------------------------
	// 샘플 입력 예시1 ("aya", "yee", "u", "maa", "wyeoo")
	// 샘플 입력 예시2 ("ayaye", "uuuma", "ye", "yemawoo", "ayaa")
	
	//(참고) vector<string> 변수 초기화 방법
	//vector<string> babbling_input = { "aya", "yee", "u", "maa", "wyeoo" };			// 되는 지만 검사하고 GitHub에 Upload 할 Code는 getline으로 만들어서 저장!
	
	vector<string> babbling_input;
	string tmp;
	int continue_chk;		//0:Stop, 1:Continue (Other ReEnter)
	unsigned int i;
	for (i = 0; i < 100; i++) {
		if (i > 0) {																	// 최초 이후 부터는 그만 입력할 지 선택
			cout << "If you want to stop, Enter \"0\" or Not \"1\"" << endl;
			cin >> continue_chk;
			while (continue_chk != 0 && continue_chk != 1) {
				cout << "Please Enter it correctly." << endl;
				cin >> continue_chk;
			}
			if (continue_chk) {
				cin >> tmp;
				babbling_input.push_back(tmp);											// input data 입력
			}
			else
				break;																	// for() 탈출
		}
		else {																			// 최초 입력은 그냥 실행
			cout << "Please Enter sample words." << endl;
			cin >> tmp;
			babbling_input.push_back(tmp);
		}
	}

	// 입력 받은 발음 출력
	for (i = 0; i < babbling_input.size(); i++) {
		if (i == 0)																		// i (First)
			cout << "You're Enter Words : {\"" << babbling_input[i] << "\", ";
		else if (i == babbling_input.size() - 1)										// i (Last)
			cout << "\"" << babbling_input[i] << "\"}" << endl;
		else                                                                            // i (Middle)
			cout << "\"" << babbling_input[i] << "\", ";
	}

	cout << "Baby can say babbling : " << solution(babbling_input) << endl;				// 샘플 입력 예시1 - 기대 Return Value (1)
																						// 샘플 입력 예시2 - 기대 Return Value (3)

    return 0;
}


int solution(vector<string> babbling) {
	int answer = 0;

	for (unsigned int i = 0; i < babbling.size(); i++) {
		bool check = false;

		// 단 하나라도 할 수 없는 발음이 있는 경우를 check 를 통해 검사 (check - true:발음불가, false:발음가능)
		// substr()을 사용하여 문자열 Read
		// for() 인수 j에 값을 더하여 비교한 문자 길에 만큼 패스
		for (unsigned int j = 0; j < babbling[i].size(); j++) {
			if (babbling[i].substr(j, 3) == "aya") j += 2;
			else if (babbling[i].substr(j, 2) == "ye") j += 1;
			else if (babbling[i].substr(j, 3) == "woo") j += 2;
			else if (babbling[i].substr(j, 2) == "ma") j += 1;
			else {
				check = true;
				break;
			}
		}

		if (!check) answer++;
	}

	return answer;
}

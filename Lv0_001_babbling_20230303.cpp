#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : �˾���1
// 
// ���� ����
// �Ӿ��̴� �¾ �� 6���� �� ��ī�� ������ �ֽ��ϴ�.
// ��ī�� ���� "aya", "ye", "woo", "ma" �� ���� ������ �ִ� �� ���� ����� ������(�̾� ����) �����ۿ� ���� ���մϴ�.
// ���ڿ� �迭 babbling�� �Ű������� �־��� ��, �Ӿ����� ��ī�� ������ �� �ִ� �ܾ��� ������ return�ϵ��� solution �Լ��� �ϼ����ּ���.
// 
// ���ѻ���
// 1 �� babbling�� ���� �� 100
// 1 �� babbling[i]�� ���� �� 15
// babbling�� �� ���ڿ����� "aya", "ye", "woo", "ma"�� ���� �ִ� �� ������ �����մϴ�.
// ��, �� ���ڿ��� ������ ��� �κ� ���ڿ� �߿��� "aya", "ye", "woo", "ma"�� �� ������ �����մϴ�.
// ���ڿ��� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
// 
// ��¥ : 2023.03.05
// ����Ʈ : ���ڿ� ó�� (�� �ְ��� ����)
//*************************************************************************************************************************************

// �־��� �Լ� (���ο� Logic ����)
int solution(vector<string> babbling);




int main() {

	//-----------------------------------------------------------------------------------------------------------
	// ���� �Է� ����1 ("aya", "yee", "u", "maa", "wyeoo")
	// ���� �Է� ����2 ("ayaye", "uuuma", "ye", "yemawoo", "ayaa")
	
	//(����) vector<string> ���� �ʱ�ȭ ���
	//vector<string> babbling_input = { "aya", "yee", "u", "maa", "wyeoo" };			// �Ǵ� ���� �˻��ϰ� GitHub�� Upload �� Code�� getline���� ���� ����!
	
	vector<string> babbling_input;
	string tmp;
	int continue_chk;		//0:Stop, 1:Continue (Other ReEnter)
	unsigned int i;
	for (i = 0; i < 100; i++) {
		if (i > 0) {																	// ���� ���� ���ʹ� �׸� �Է��� �� ����
			cout << "If you want to stop, Enter \"0\" or Not \"1\"" << endl;
			cin >> continue_chk;
			while (continue_chk != 0 && continue_chk != 1) {
				cout << "Please Enter it correctly." << endl;
				cin >> continue_chk;
			}
			if (continue_chk) {
				cin >> tmp;
				babbling_input.push_back(tmp);											// input data �Է�
			}
			else
				break;																	// for() Ż��
		}
		else {																			// ���� �Է��� �׳� ����
			cout << "Please Enter sample words." << endl;
			cin >> tmp;
			babbling_input.push_back(tmp);
		}
	}

	// �Է� ���� ���� ���
	for (i = 0; i < babbling_input.size(); i++) {
		if (i == 0)																		// i (First)
			cout << "You're Enter Words : {\"" << babbling_input[i] << "\", ";
		else if (i == babbling_input.size() - 1)										// i (Last)
			cout << "\"" << babbling_input[i] << "\"}" << endl;
		else                                                                            // i (Middle)
			cout << "\"" << babbling_input[i] << "\", ";
	}

	cout << "Baby can say babbling : " << solution(babbling_input) << endl;				// ���� �Է� ����1 - ��� Return Value (1)
																						// ���� �Է� ����2 - ��� Return Value (3)

    return 0;
}


int solution(vector<string> babbling) {
	int answer = 0;

	for (unsigned int i = 0; i < babbling.size(); i++) {
		bool check = false;

		// �� �ϳ��� �� �� ���� ������ �ִ� ��츦 check �� ���� �˻� (check - true:�����Ұ�, false:��������)
		// substr()�� ����Ͽ� ���ڿ� Read
		// for() �μ� j�� ���� ���Ͽ� ���� ���� �濡 ��ŭ �н�
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

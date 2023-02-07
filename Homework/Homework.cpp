#include <iostream>
#include <string>
#include "Student.h"
#include "DynamicArray.h"

using namespace std;

int length = 0;

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    DynamicArray<Student*> students;

    while (true) {

        cout << "1. 입력하기 2. 모두 출력 3. 추가 입력" << endl;

        int num = 0;
        cin >> num;

        switch (num) {
        case 1: {
            cout << "몇 명을 입력하시겠습니까? " << endl;

            cin >> length;

            for (int i = 0; i < length; i++) {

                Student* student = new Student;

                cout << "이름을 입력하세요 \n";
                string name; cin >> name;
                student->SetName(name);

                cout << "성적을 입력하세요 \n";
                int score; cin >> score;
                student->SetScore(score);

                students.push_back(student);
            }

            break;
        }

        case 2 :

            for (int i = 0; i < students.size(); i++) {
                cout << "이름 : " << students[i]->GetName() << "\n";
                cout << "성적 : " << students[i]->GetScore() << "\n";
            }

            break;
        case 3: {
            // 카피하고 새로 할당
            cout << "추가할 인원수를 입력해 주세요 \n";
            int add_num = 0;
            cin >> add_num;

            for (int i = 0; i < add_num; i++) {
                Student* student = new Student;

                cout << "이름을 입력하세요 \n";
                string name; cin >> name;
                student->SetName(name);

                cout << "성적을 입력하세요 \n";
                int score; cin >> score;
                student->SetScore(score);

                students.push_back(student);
            }

            break;
        }
        default :
            continue;
        }

    }

    return 0;
}
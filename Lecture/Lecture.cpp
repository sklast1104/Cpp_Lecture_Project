#include <iostream>
#include <typeinfo>

class Base {};
class Derived : public Base {};

int main() {
    Base* p = new Derived;
    if (typeid(*p) == typeid(Derived)) {
        std::cout << "p is of type Derived" << std::endl;
    }
    else {
        std::cout << "p is of type Base" << std::endl;
    }
    return 0;
}

// 1. TextRPG 클래스 버전
// 2. 성적표 클래스 버전 (동적 배열)
/*
1. 입력을 누르면 몇 명을 입력할 지 묻는다
2. 입력한 사람 수 만큼 이름과 각종 성적을 입력받는다
3. 모두 출력 메뉴를 입력하면 입력한 모든 성적 데이터를 출력한다
4. 추가 입력 메뉴를 선택하면 기존 인원 + 새로 추가할 인원만큼 입력 받는다
*/
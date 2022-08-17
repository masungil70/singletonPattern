// singletonPattern.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

class Printer {
private:
	Printer() {
		cout << "Printer() 생성자 호출" << endl;
	}
	~Printer() {
		cout << "~Printer() 소멸자 호출" << endl;
	}
public:
	static Printer* getPrinter() {
		// Printer 정적 객체 생성 
		static Printer printer;
		return &printer;
	}
	void print(...) { 
		cout << "pointer object address = 0x" << static_cast<void*>(this) << endl;
	}
};


//문제가 있는 코드 임 -> 해결된 코드 
int main()
{
	Printer* a1 = Printer::getPrinter();
	Printer* a2 = Printer::getPrinter();
	Printer* a3 = Printer::getPrinter();

	a1->print();
	a2->print();
	a3->print();
}

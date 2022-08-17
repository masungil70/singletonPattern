// singletonPattern.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

class Printer {
public:
	Printer() {}
	~Printer() {}
	void print(...) { 
		cout << "pointer object address = 0x" << static_cast<void*>(this) << endl;
	}
};
//업무상 문제가 있는 코드 임 
int main()
{

	Printer a1;
	Printer a2;
	Printer a3;

	a1.print();
	a2.print();
	a3.print();
}

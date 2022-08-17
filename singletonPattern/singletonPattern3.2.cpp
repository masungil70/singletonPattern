// singletonPattern.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class Printer {
private:
	Printer() {}
	~Printer() {}

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

void threadFunc() {
	Printer* a1 = Printer::getPrinter();
	a1->print();
}

//문제가 있는 코드 임 
int main()
{
	vector<thread> list;

	for (int i = 0; i < 10; i++) {
		list.emplace_back(thread{ threadFunc });
	}

	for (auto& item : list) {
		item.join();
	}
	return 0;
}
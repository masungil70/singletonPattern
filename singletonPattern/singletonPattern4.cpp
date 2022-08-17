// singletonPattern.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

//template을 이용한 싱글턴 클래스 
template <typename T>
class Singleton {
protected:
	Singleton() {}
	~Singleton() {}
public:
	static Singleton<T>* getInstance() {
		// Printer 정적 객체 생성 
		static Singleton<T> instance;
		return &instance;
	}
	void print(...) { 
		cout << "pointer object address = 0x" << static_cast<void*>(this) << endl;
	}
};

class SamsungPrinter : public Singleton<SamsungPrinter>{
public:
};

class LGPrinter : public Singleton<LGPrinter> {
public:
};

//문제가 있는 코드 임 
int main()
{
	SamsungPrinter::getInstance()->print();
	SamsungPrinter::getInstance()->print();
	LGPrinter::getInstance()->print();
	LGPrinter::getInstance()->print();

	return 0;
}
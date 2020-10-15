#include <iostream>
#include <stdexcept>
class Test {
public:
	Test(char id) : id_(id) {}
	~Test() {
		std::cout << "Destructor execution: "
			<< id_ << std::endl;
	}
private:
	char id_;
};
int funcB() {
	Test r('B');
	throw std::runtime_error("Exception from funcB!\n");
	std::cout << "Executed in B" << std::endl;
	return 0;
}
int funcA() {
	Test r('A');
	funcB();
	std::cout << "Executed in A" << std::endl;
	return 0;
}
int main() {
	try {
		funcA();
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what();
	}
}
/* 
스택 언와인딩은 exception처리와 관련된 개념으로,
예외 발생시, 리턴주소를 참조하지 않고,  
exception핸들러가 있는 위치를 찾아서 그 위치로 가는 것을 
스택 언와인딩이라고 함 */

/*
(실습 1-1) 분석결과 :
결과 
Executed in B
Destructor execution: B
Executed in A
Destructor execution: A 
따라서,  exception이 발생하지 않은 정상적인 실행흐름임 */

/* (실습 1-2) 분석결과 : 
결과2
Destructor execution: B
Destructor execution: A
Exception : Exception from funcB! 
따라서, exception이 발생한 경우로, cout 부분들이 호출되지 않음 */
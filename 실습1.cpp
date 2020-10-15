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
���� ����ε��� exceptionó���� ���õ� ��������,
���� �߻���, �����ּҸ� �������� �ʰ�,  
exception�ڵ鷯�� �ִ� ��ġ�� ã�Ƽ� �� ��ġ�� ���� ���� 
���� ����ε��̶�� �� */

/*
(�ǽ� 1-1) �м���� :
��� 
Executed in B
Destructor execution: B
Executed in A
Destructor execution: A 
����,  exception�� �߻����� ���� �������� �����帧�� */

/* (�ǽ� 1-2) �м���� : 
���2
Destructor execution: B
Destructor execution: A
Exception : Exception from funcB! 
����, exception�� �߻��� ����, cout �κе��� ȣ����� ���� */
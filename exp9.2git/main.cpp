#include"Investment.h"
int main() {
	Person Wang(100000);
	Wang.addInvest(Saving(50000));
	cout <<"ʣ�౾��" <<Wang.princinpal();
	cout << "һ�괢����ࣺ"<<Wang.settle() << endl;
	Wang.addInvest(Fund(20000));
	cout << "ʣ�౾��" << Wang.princinpal();
	cout << "һ�������ࣺ" << Wang.settle() << endl;
}
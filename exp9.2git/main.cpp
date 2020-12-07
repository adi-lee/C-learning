#include"Investment.h"
int main() {
	Person Wang(100000);
	Wang.addInvest(Saving(50000));
	cout <<"剩余本金：" <<Wang.princinpal();
	cout << "一年储蓄结余："<<Wang.settle() << endl;
	Wang.addInvest(Fund(20000));
	cout << "剩余本金：" << Wang.princinpal();
	cout << "一年基金结余：" << Wang.settle() << endl;
}
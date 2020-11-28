#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
template<typename X>
class HN {//HNÊÇHuffmanNode
	template<typename T>
	friend class HTree;
private:
	double m_weight;
	X m_data = NULL;
	HN* m_left = nullptr;
 	HN* m_right = nullptr;
public:
	HN() = default;
	/*HN(X* data, double* weight) {
		this->m_data = data;
		this->weight = weight;
		this->left = NULL;
		this->right = NULL;
		this->m_parent = NULL;
	}
	HN(X* data, double* setweight, HN* setparent, HN* setleft, HN* setright) {
		this->m_data = data;
		this->weight = setweight;
		this->left = setleft;
		this->right = setright;
		this->m_parent = setparent;

	}*/
	X& data() { return m_data; }
	double& weight() { return m_weight; }
	HN*& left() { return m_left; }
	HN*& right() { return m_right; }
};
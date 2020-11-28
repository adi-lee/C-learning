#include"Huffman.h"
#include<vector> 
int num[10] = { 0 }, letter[26] = { 0 }, other = 0, othernum[100] = { 0 }, l;
char d[100] = { "0" };//初始化字符数组
char* p = d;
double weight1[100] = { 0 };
double* q = weight1;
void count(string& str) {
    for (unsigned i = 0; i < str.size(); i++) {
        char c = str.at(i);
        if ('\n' != c) {
            p = d;
            for (l = 0; l < 100; l++) {
                if (*p == c) {
                    othernum[l]++;//other表示出现的第几个其他字符，othernum表示该字符的个数
                    break;
                }
                else p++;
            }
            p = d;
            if (l == 100) {//l=100意味着出现了一个新的other字符
                for (int k = 0; k < other; k++) {
                    p++;
                }
                *p = c;
                ++other;
            }
        }
        p = d;
    }
    for (int k = 0; k < other; k++) {
        cout << "符号：" << *p << "出现次数：" << othernum[k] + 1;
        double f = othernum[k] + 1;
        *q = f / str.size();
        cout << "该字符在本文中的出现频率是:" << *q << endl;
        p++;
        q++;

    }
}

int main() {
    ifstream inFile;
    inFile.open("huffman.txt");
    string str1;
    if (inFile) { //条件成立，则说明文件打开成功
        cout << "huffman.txt open scessful" << endl;
        getline(inFile, str1);//按行显示
        cout << str1 << endl;
        inFile.close();
    }
    else {
        cout << "huffman.txt doesn't exist" << endl;
        return 0;//终止程序运行
    }
    inFile.open("Test.txt");
    string str;
    if (inFile) { //条件成立，则说明文件打开成功
        cout << "Test.txt open scessful" << endl;
        getline(inFile, str);//按行显示
        cout << str << endl;
        inFile.close();
    }
    else {
        cout << "Test.txt doesn't exist" << endl;
        return 0;
    }
    count(str1);
    vector<HN<char>*> node;
    node.reserve(1000);
    HTree<char>s1;
    HN<char>* temp = new HN<char>[100];
    for (int i = 0; i < other; i++) {
        temp[i].data() = d[i];
        //  cout << temp->data();
        temp[i].weight() = weight1[i];
        temp[i].left() = NULL;
        temp[i].right() = NULL;
        node.push_back(&temp[i]);
    }
    HN<char>* root = s1.createHfmTree(node);
    vector<int> key;
    //cout << "编码如下：" << endl;
    s1.print(root, key);
    return 0;
    system("pause");

}
#include"Huffman.h"
#include<vector> 
int num[10] = { 0 }, letter[26] = { 0 }, other = 0, othernum[100] = { 0 }, l;
char d[100] = { "0" };//��ʼ���ַ�����
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
                    othernum[l]++;//other��ʾ���ֵĵڼ��������ַ���othernum��ʾ���ַ��ĸ���
                    break;
                }
                else p++;
            }
            p = d;
            if (l == 100) {//l=100��ζ�ų�����һ���µ�other�ַ�
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
        cout << "���ţ�" << *p << "���ִ�����" << othernum[k] + 1;
        double f = othernum[k] + 1;
        *q = f / str.size();
        cout << "���ַ��ڱ����еĳ���Ƶ����:" << *q << endl;
        p++;
        q++;

    }
}

int main() {
    ifstream inFile;
    inFile.open("huffman.txt");
    string str1;
    if (inFile) { //������������˵���ļ��򿪳ɹ�
        cout << "huffman.txt open scessful" << endl;
        getline(inFile, str1);//������ʾ
        cout << str1 << endl;
        inFile.close();
    }
    else {
        cout << "huffman.txt doesn't exist" << endl;
        return 0;//��ֹ��������
    }
    inFile.open("Test.txt");
    string str;
    if (inFile) { //������������˵���ļ��򿪳ɹ�
        cout << "Test.txt open scessful" << endl;
        getline(inFile, str);//������ʾ
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
    //cout << "�������£�" << endl;
    s1.print(root, key);
    return 0;
    system("pause");

}
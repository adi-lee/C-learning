#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
void count(string &str) {
    int num[10] = { 0 }, letter[26] = { 0 }, other = 0, othernum[100] = { 0 },l;
    char d[100] = {"0"};//��ʼ���ַ�����
    char* p = d;
    for ( unsigned  i = 0; i < str.size(); i++) {
        char c = str.at(i);
       if ('\n' != c) {
            if (c >= '0' && c <= '9') {
            num[(int)(c - '0')]++;
            }   
            else if (c >= 'a' && c <= 'z') letter[(int)(c - 'a')]++;
            else if (c >= 'A' && c <= 'Z') letter[(int)(c - 'A')]++;
            else {
                p = d;
                for (l=0; l< 100; l++) {
                    if (*p == c) {
                        othernum[l]++;//other��ʾ���ֵĵڼ��������ַ���othernum��ʾ���ַ��ĸ���
                        break;
                    }
                    else p++; 
                }
                p = d;
                if (l == 100) {//i=99��ζ�ų�����һ���µ�other�ַ�
                    for (int k = 0;k< other; k++) {
                        p++;
                    }
                    *p = c;
                   ++other; 
                }
            }
        }
       p = d;
    }
    for (int i = 0; i < 10; i++) {
        cout << "���֣�" << i << "���ִ�����" << num[i] ;
        double f = num[i];
        cout<<"���ַ��ڱ����еĳ���Ƶ����:" << f / str.size() << endl;
    }
    for (int j = 0; j < 26; j++) {
        cout << "��ĸ��" << (char)(j + 'a') << "���ִ�����" << letter[j];
        double f = letter[j];
        cout << "���ַ��ڱ����еĳ���Ƶ����:" << f / str.size() << endl;
    }
    for (int k = 0; k < other; k++) {
        cout << "���ţ�" << *p << "���ִ�����" << othernum[k]+1 ;
        double f = othernum[k]+1;
        cout << "���ַ��ڱ����еĳ���Ƶ����:" << f / str.size() << endl;
        p++;
    }
}




int main() {
    ifstream inFile;
    inFile.open("huffman.txt");
    string str;
    if (inFile) { //������������˵���ļ��򿪳ɹ�
        cout << "huffman.txt open scessful" << endl;
        getline(inFile, str);//������ʾ
        
        cout << str << endl;
        count(str);
        inFile.close();
    }
    else
        cout << "Test.txt doesn't exist" << endl;
    inFile.open("Test.txt");
    string str1;
    if (inFile) { //������������˵���ļ��򿪳ɹ�
        cout << "Test.txt open scessful" << endl;
        getline(inFile, str1);//������ʾ
        cout << str1 << endl;
        count(str1);
        inFile.close();
    }
    else
        cout << "huffman.txt doesn't exist" << endl;
    return 0;

    system("pause");
}
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
void count(string &str) {
    int num[10] = { 0 }, letter[26] = { 0 }, other = 0, othernum[100] = { 0 },l;
    char d[100] = {"0"};//初始化字符数组
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
                        othernum[l]++;//other表示出现的第几个其他字符，othernum表示该字符的个数
                        break;
                    }
                    else p++; 
                }
                p = d;
                if (l == 100) {//i=99意味着出现了一个新的other字符
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
        cout << "数字：" << i << "出现次数：" << num[i] ;
        double f = num[i];
        cout<<"该字符在本文中的出现频率是:" << f / str.size() << endl;
    }
    for (int j = 0; j < 26; j++) {
        cout << "字母：" << (char)(j + 'a') << "出现次数：" << letter[j];
        double f = letter[j];
        cout << "该字符在本文中的出现频率是:" << f / str.size() << endl;
    }
    for (int k = 0; k < other; k++) {
        cout << "符号：" << *p << "出现次数：" << othernum[k]+1 ;
        double f = othernum[k]+1;
        cout << "该字符在本文中的出现频率是:" << f / str.size() << endl;
        p++;
    }
}




int main() {
    ifstream inFile;
    inFile.open("huffman.txt");
    string str;
    if (inFile) { //条件成立，则说明文件打开成功
        cout << "huffman.txt open scessful" << endl;
        getline(inFile, str);//按行显示
        
        cout << str << endl;
        count(str);
        inFile.close();
    }
    else
        cout << "Test.txt doesn't exist" << endl;
    inFile.open("Test.txt");
    string str1;
    if (inFile) { //条件成立，则说明文件打开成功
        cout << "Test.txt open scessful" << endl;
        getline(inFile, str1);//按行显示
        cout << str1 << endl;
        count(str1);
        inFile.close();
    }
    else
        cout << "huffman.txt doesn't exist" << endl;
    return 0;

    system("pause");
}
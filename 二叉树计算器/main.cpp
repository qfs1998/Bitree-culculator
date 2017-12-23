#include"culculator.h"
int main()
{
	string Infix_Formula;
	getline(cin, Infix_Formula);
	/*if(Judge(Infix_Formula))cout<<"correct\n";
	else cout << "error\n";*/
	vector<string> v;
	stack<char> s;
	Infix_To_Suffix(v, s, Infix_Formula);
	stack<BiTree*>TS;
	BiTree*p = (BiTree*)malloc(sizeof(BiTree));
	p = CreatTree(TS, v);
	double num=Culculate(p);
	cout << num << endl;
	system("pause");
	return 0;
}
#pragma once
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<sstream>
#define MAX_FORMULA_LENGTH 100
using namespace std;
struct BiTree
{
	char op;
	double num;
	BiTree*lchild, *rchild;
};
bool  Judge(const string & Infix_Formula);
void Infix_To_Suffix(vector<string>&v, stack<char>&s, const string&Infix_Formula);//���򵽺���,vector�д����˰���׺���ʽ˳�����е�string
int Isoperand(char c);
int Isoperator(char c);
BiTree* CreatTree(stack<BiTree*>&TS, vector<string>&v);
double Culculate(BiTree*T);

#pragma once
#include<iostream>
#include<string>
#include<stack>
#define MAX_FORMULA_LENGTH 100
using namespace std;
bool  Judge(const string & Infix_Formula);
void Infix_To_Suffix(stack<char>&s, const string&Infix_Formula, string Suffix_f[MAX_FORMULA_LENGTH]);
int Isoperand(char c);
int Isoperator(char c);
/*struct LSnode
{
string data;
LSnode *next;
};
struct my_stack//LS means LinkStack
{
LSnode *top;
LSnode *base;
int count;
my_stack()//¹¹Ôì
{
top = (LSnode*)malloc(sizeof(LSnode));
top->next = NULL;
base = top;
count = 0;
}
void push(char c);
string pop();
string gettop();
};*/
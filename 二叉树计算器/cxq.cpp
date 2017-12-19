#include"culculator.h"
int Isoperand(char c)
{
	if (c == '.' || (c > '0'&&c < '9'))
		return 1;
	return 0;
}
int Isoperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/'||c=='('||c==')')
		return 1;
	return 0;
}


bool  Judge(const string & Infix_Formula)
{
	int lb = 0, rb = 0;
	if (Infix_Formula[0] != '-' || !Isoperand(Infix_Formula[0]))
		return 0;
	for (int i = 0; i < Infix_Formula.size(); ++i)
	{
		if (Infix_Formula[i] == '(')++lb;
		if (Infix_Formula[i] == ')')++rb;
		if (rb > lb)
			return 0;
		if (Isoperand(Infix_Formula[i]))
		{
			if (Infix_Formula[i - 1] == ')')return 0;
			if (Infix_Formula[i + 1] == '(')return 0;
		}
		if (Isoperator(Infix_Formula[i]))
		{
			if (Isoperator(Infix_Formula[i - 1])||Infix_Formula[i+1]=='.')return 0;
			if (Isoperator(Infix_Formula[i +1 ])||Infix_Formula[i+1]=='.')return 0;
		}
    }
	return 1;
}
void Infix_To_Suffix(stack<char>s, const string&Infix_Formula, string Suffix_f[MAX_FORMULA_LENGTH])//÷––ÚµΩ∫Û–Ú
{
	for (int i = 0; i < Infix_Formula.size(); ++i)
	{
		if (i == 0 && Infix_Formula[i] == '-')
		{

		}
	}
}

/*void my_stack::push(char c)
{
LSnode *p = (LSnode*)malloc(sizeof(LSnode));
p->data = c;
p->next = top->next;
top->next = p;
++count;
}
string my_stack::gettop()
{
if (top != base)
return top->next->data;
}
string my_stack::pop()
{
string t=top->next->data;
LSnode *p = top->next;
top->next = p->next;
free(p);
--count;
return t;
}*/
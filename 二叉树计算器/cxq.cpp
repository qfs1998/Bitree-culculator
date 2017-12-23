#include"culculator.h"
int Isoperand(char c)
{
	if (c == '.' || (c >= '0'&&c <= '9'))
		return 1;
	return 0;
}
int Isoperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/'||c=='('||c==')')
		return 1;
	return 0;
}


bool  Judge(const string & Infix_Formula)//≈–∂œ
{
	int lb = 0, rb = 0;
	if (Infix_Formula[0] != '-' && !Isoperand(Infix_Formula[0]))
		return 0;
	for (int i = 0; i < Infix_Formula.size(); ++i)
	{
		if (Infix_Formula[i] == '(')++lb;
		if (Infix_Formula[i] == ')')++rb;
		if (rb > lb)
			return 0;
		if (i!=0&&Isoperand(Infix_Formula[i]))
		{
			if (Infix_Formula[i - 1] == ')')return 0;
			if (Infix_Formula[i + 1] == '(')return 0;
		}
		if (i!=0&&Isoperator(Infix_Formula[i]))
		{
			if (Isoperator(Infix_Formula[i - 1])||Infix_Formula[i+1]=='.')return 0;
			if (Isoperator(Infix_Formula[i +1 ])||Infix_Formula[i+1]=='.')return 0;
		}
    }
	return 1;
}

int Priority(char  c)
{
if(c=='+'||c=='-')
		return 1;
if(c=='*'||c=='/')
		return 2;
if(c=='(')
		return 3;
if(c==')')
		return -1;
	}




void Infix_To_Suffix(vector<string>&v, stack<char>&s, const string&Infix_Formula)//÷––ÚµΩ∫Û–Ú
{
	for (int i = 0; i < Infix_Formula.size(); ++i)
	{
		if (i == 0 && Infix_Formula[i] == '-')
		{
			v.push_back("0");
			s.push('-');
		}
		else if (i == 0 && Isoperand(Infix_Formula[i]))
		{
			string t = "";
			t += Infix_Formula[i];
			v.push_back(t);
		}
		else if (i != 0 && Isoperand(Infix_Formula[i - 1]) && Isoperand(Infix_Formula[i]))
		{
			v[v.size()-1] += Infix_Formula[i];
		}
		else if (i != 0 && Isoperator(Infix_Formula[i - 1]) && Isoperand(Infix_Formula[i]))
		{
			string t = "";
			t += Infix_Formula[i];
			v.push_back(t);
		}
		//∑˚∫≈
		else if (Isoperator(Infix_Formula[i]))
		{
			if (s.empty())
			{
				s.push(Infix_Formula[i]);
			}
			else if (Infix_Formula[i] == '(')
			{
				s.push(Infix_Formula[i]);
			}
			else if (!s.empty() && Priority(Infix_Formula[i]) > Priority(s.top()))
			{
				s.push(Infix_Formula[i]);
			}
			else if (!s.empty() && Infix_Formula[i] == ')')
			{
				while (!s.empty() && s.top() != '(')
				{
					string t = "";
					t += s.top();
					v.push_back(t);
					s.pop();
				}
				s.pop();
			}
			else if (!s.empty() && Priority(Infix_Formula[i]) <= Priority(s.top()) && s.top() != '(')//5*(3+2)
			{
				while (!s.empty()&&Priority(s.top()) >= Priority(Infix_Formula[i]) && s.top() != '(')
				{
					string t = "";
					t += s.top();
					v.push_back(t);
					s.pop();
				}
				s.push(Infix_Formula[i]);
			}
			else if (!s.empty() && Priority(Infix_Formula[i]) < Priority(s.top()) && s.top() == '(')
			{
				s.push(Infix_Formula[i]);
			}
		}
	}
	while(!s.empty())
	{
		string t = "";
		t += s.top();
		s.pop();
		v.push_back(t);
	}

}

BiTree* CreatTree(stack<BiTree*>&TS, vector<string>&v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		BiTree * p = (BiTree*)malloc(sizeof(BiTree));
		if (Isoperand(v[i][0]))
		{
			stringstream ss;
			ss << v[i];
			ss >> p->num;
			p->lchild = NULL;
			p->rchild = NULL;
			ss.clear();
			TS.push(p);
		}
		else if (Isoperator(v[i][0]))
		{
			p->op = v[i][0];
			p->rchild = TS.top();
			TS.pop();
			p->lchild = TS.top();
			TS.pop();
			TS.push(p);
		}
	}
	return TS.top();
}
double Culculate(BiTree*T)
{
	if (T->lchild!= NULL&&T->rchild!=NULL)
	{
		switch (T->op)
		{
		case'+':
			T->num = Culculate(T->lchild)+ Culculate(T->rchild);
			break;
		case'-':
			T->num = Culculate(T->lchild) - Culculate(T->rchild);
			break;
		case'*':
			T->num = Culculate(T->lchild) * Culculate(T->rchild);
			break;
		case'/':
			T->num = Culculate(T->lchild) / Culculate(T->rchild);
			break;
		}
	}
	return T->num;
}
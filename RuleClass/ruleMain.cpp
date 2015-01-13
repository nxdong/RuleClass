
#include "Rules.h"
#include "Produce.h"
#include <string>
#include <iostream>
#include <wchar.h>
using namespace std;
int main()
{
	CRules testRule;
	//testRule.InsertRule(L"F", L"F[+F]F[-F]F");
	testRule.InsertRule(L"F", L"FSC");
	testRule.InsertRule(L"S", L"s");
	testRule.InsertRule(L"C", L"ScF");
	CProduce pro(L"F",testRule);
	pro.SetDegree(3);
	wcout << pro.getResult()<< endl;
	system("pause");
}
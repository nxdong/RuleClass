
#include "Rules.h"
#include "Produce.h"
#include <string>
#include <iostream>
#include <wchar.h>
using namespace std;
int main()
{
	singlerule srule;
	srule.InsertLeftRule(L"F");
	srule.InsertRightRule(L"FAF", 0.1);
	srule.InsertRightRule(L"FBF", 0.9);
	//srule.InsertRightRule(L"FCF", 0.4);
	CRules testRule;
	testRule.InsertRule(srule);
	CProduce pro(L"F",testRule);
	pro.SetDegree(4);
	wcout << pro.getResult()<< endl;
	system("pause");
}
#pragma once
#include <string>
#include <vector>
using namespace std;
// error define
enum ruleerr
{
	FRESH_SUCESS,
	FRESH_ERR,

	INSERT_SUCESS,
	INSERT_ERR,

	MATCH_SUCCESS,
	MATCH_ERR,
};



//	����ʽ������
//	P �� F   �� LRule Ϊ P ; RRule Ϊ F;
typedef vector<wstring const> LRule;	/*������벿��*/
typedef vector<wstring const> RRule;	/*�����Ұ벿��*/
//TODO : ���� 
typedef vector<double  const> probability;      
// ���������࣬���ڴ洢��������
class CRules
{
public:
	CRules();
	~CRules();
private:
	LRule m_leftRule;
	RRule m_rightRule;

	int   m_nRules;
public:
	// ��գ���ʼ������
	int Fresh();
	// �����¹���
	int InsertRule(wstring const &lrule, wstring const &rrule);
	// ƥ��������������ڣ�������Ӧrrule
	int MatchRule(wstring const lrule, wstring &retstr) const;
	// �õ�������Ŀ
	int GetRulesNum() const;
};


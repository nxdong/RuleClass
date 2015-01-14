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
// �������Ľṹ�塣
typedef wstring LEFTPART;							//����ǰ�벿��
typedef struct RIGHTPART
{
	wstring rstr;									//�����벿��			
	double  odds;									//�ò��ֳ��ֵļ���
	RIGHTPART(wstring rule, double dodds) :rstr(rule), odds(dodds){};
	RIGHTPART() :rstr(NULL), odds(1){};
};
typedef struct singlerule
{
	enum {MAX_RAND = 100};
private:
	LEFTPART	leftpart;
	vector<RIGHTPART> rightpart;
public:
	wstring getLeftRule()const{return leftpart;}    
	wstring getRightRule()const
	{
		size_t vsize = rightpart.size();
		int randNum = rand() % MAX_RAND;
		double addnum = 0.0;
		for (size_t i = 0; i < vsize; i++)
		{
			if (randNum >= MAX_RAND*addnum 
				&& randNum <= (addnum + rightpart[i].odds)*MAX_RAND)
			{
				return rightpart[i].rstr;
			}
			addnum += rightpart[i].odds;
		}
		return L"";
	}
	// ��������ǰ�벿��
	void InsertLeftRule(wstring const lrule){ leftpart = lrule; }
	// ��������Լ��䷢���ĸ���
	void InsertRightRule(wstring const insertrule,double idodds)
	{
		RIGHTPART insertRightPart(insertrule, idodds);
		rightpart.push_back(insertRightPart);
	}
	//�����뵥����ʱ������Ϊ1
	void InsertRightRule(wstring const rrule)
	{
		RIGHTPART insertRightPart(rrule,1.0);
		rightpart.push_back(insertRightPart);
	}
};


//	����ʽ������
//	P �� F   �� LRule Ϊ P ; RRule Ϊ F;
// vector<wstring const> LRule;	/*������벿��*/
//typedef vector<wstring const> RRule;	/*�����Ұ벿��*/
//TODO : ���� 
//typedef vector<double  const> probability;      
// ���������࣬���ڴ洢��������
class CRules
{
public:
	CRules();
	~CRules();
private:
//	LRule m_leftRule;
//	RRule m_rightRule;
	vector<singlerule> m_rules;
	int   m_nRules;
public:
	// ��գ���ʼ������
	int Fresh();
	// �����¹���
	int InsertRule(singlerule const &rule);
	// ƥ��������������ڣ�������Ӧrrule
	int MatchRule(wstring const lrule, wstring &retstr) const;
	// �õ�������Ŀ
	int GetRulesNum() const;
};


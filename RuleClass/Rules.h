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
// 定义规则的结构体。
typedef wstring LEFTPART;							//规则前半部分
typedef struct RIGHTPART
{
	wstring rstr;									//规则后半部分			
	double  odds;									//该部分出现的几率
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
	// 插入规则的前半部分
	void InsertLeftRule(wstring const lrule){ leftpart = lrule; }
	// 插入规则以及其发生的概率
	void InsertRightRule(wstring const insertrule,double idodds)
	{
		RIGHTPART insertRightPart(insertrule, idodds);
		rightpart.push_back(insertRightPart);
	}
	//当插入单规则时，概率为1
	void InsertRightRule(wstring const rrule)
	{
		RIGHTPART insertRightPart(rrule,1.0);
		rightpart.push_back(insertRightPart);
	}
};


//	产生式规则定义
//	P → F   则 LRule 为 P ; RRule 为 F;
// vector<wstring const> LRule;	/*规则左半部份*/
//typedef vector<wstring const> RRule;	/*规则右半部份*/
//TODO : 概率 
//typedef vector<double  const> probability;      
// 产生规则类，用于存储产生规则
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
	// 清空，初始化规则
	int Fresh();
	// 加入新规则
	int InsertRule(singlerule const &rule);
	// 匹配规则，如果规则存在，返回相应rrule
	int MatchRule(wstring const lrule, wstring &retstr) const;
	// 得到规则数目
	int GetRulesNum() const;
};


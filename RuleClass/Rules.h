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



//	产生式规则定义
//	P → F   则 LRule 为 P ; RRule 为 F;
typedef vector<wstring const> LRule;	/*规则左半部份*/
typedef vector<wstring const> RRule;	/*规则右半部份*/
//TODO : 概率 
typedef vector<double  const> probability;      
// 产生规则类，用于存储产生规则
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
	// 清空，初始化规则
	int Fresh();
	// 加入新规则
	int InsertRule(wstring const &lrule, wstring const &rrule);
	// 匹配规则，如果规则存在，返回相应rrule
	int MatchRule(wstring const lrule, wstring &retstr) const;
	// 得到规则数目
	int GetRulesNum() const;
};


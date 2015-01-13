#include "Rules.h"


CRules::CRules()
{
	Fresh();
}

CRules::~CRules()
{
}
int CRules::Fresh()
{
	m_leftRule.clear();
	m_rightRule.clear();
	m_nRules = 0;
	return FRESH_SUCESS;
}
int CRules::InsertRule(wstring const &lrule, wstring const &rrule)
{
	m_leftRule.push_back(lrule);
	m_rightRule.push_back(rrule);
	m_nRules += 1;
	return INSERT_SUCESS;

	if (lrule.empty() == 0 || rrule.empty() == 0)return INSERT_ERR;

}

int CRules::MatchRule(wstring const lrule, wstring &retstr) const
{
	if (lrule.empty())	return MATCH_ERR;
	size_t nRulesNum = m_leftRule.size();		// 规则总数
	size_t pos = 0;								// 匹配规则位置
	for (size_t pos = 0; pos < nRulesNum; pos++)
	{
		if (m_leftRule[pos] == lrule)
		{
			retstr = m_rightRule[pos];
			return MATCH_SUCCESS;
		}
	}

	return MATCH_ERR;
}
int CRules::GetRulesNum()const
{
	return m_nRules;
}
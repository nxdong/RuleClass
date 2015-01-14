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
	m_rules.clear();
	m_nRules = 0;
	return FRESH_SUCESS;
}
int CRules::InsertRule(singlerule const &rule)
{
	m_rules.push_back(rule);
	m_nRules += 1;
	if (m_rules.empty() == 0)return INSERT_ERR;
	return INSERT_SUCESS;

}

int CRules::MatchRule(wstring const lrule, wstring &retstr) const
{
	if (lrule.empty())	return MATCH_ERR;
	size_t nRulesNum = m_rules.size();		// 规则总数
	size_t pos = 0;								// 匹配规则位置
	for (size_t pos = 0; pos < nRulesNum; pos++)
	{
		if (m_rules[pos].getLeftRule() == lrule)
		{
			retstr = m_rules[pos].getRightRule();
			return MATCH_SUCCESS;
		}
	}

	return MATCH_ERR;
}
int CRules::GetRulesNum()const
{
	return m_nRules;
}
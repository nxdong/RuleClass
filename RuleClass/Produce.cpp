#include "Produce.h"


CProduce::CProduce(wstring const &src, CRules const &rule) 
					:m_src(src), m_rules(rule)
{
}

CProduce::~CProduce()
{
}

int CProduce::ProduceStr()
{
	wstring tempSource(m_src);						// 中间临时源串，每次迭代不同,初始化为源串
	for (size_t degree = 0; degree < m_degree; degree++)
	{
													// 循环一次 迭代一次 迭代结果存在 tempSource中以便下次迭代
		int nSourceLength = tempSource.length();
		wstring midstr;
		for (size_t pos = 0; pos < nSourceLength; pos++)
		{

			wstring inStr;							// match 函数参数1
			inStr = tempSource[pos];
			wstring retstr;
			m_rules.MatchRule(inStr, retstr);
			midstr += retstr;
		}
		tempSource = midstr;
		
	}
	m_resultstr = tempSource;
	return PRODUCE_SUCCESS;
}
int CProduce::SetDegree(int degree)
{
	int ret;
	assert(degree >= 0);
	m_degree = degree;
	ret = ProduceStr();
	return ret;
}
wstring CProduce::getResult()const
{
	return m_resultstr;
}
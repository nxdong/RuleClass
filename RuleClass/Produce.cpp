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
	wstring tempSource(m_src);						// �м���ʱԴ����ÿ�ε�����ͬ,��ʼ��ΪԴ��
	for (size_t degree = 0; degree < m_degree; degree++)
	{
													// ѭ��һ�� ����һ�� ����������� tempSource���Ա��´ε���
		int nSourceLength = tempSource.length();
		wstring midstr;
		for (size_t pos = 0; pos < nSourceLength; pos++)
		{

			wstring inStr;							// match ��������1
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
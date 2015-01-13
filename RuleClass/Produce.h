#pragma once
#include "Rules.h"
#include <cassert>
// error define
enum produceErr
{
	PRODUCE_SUCCESS,
	PRODUCE_ERR
};
class CProduce
{
public:
	CProduce(wstring const &src,CRules const &rule);
	~CProduce();
private:				
	wstring const m_src;					// 源串
	int		      m_degree;				    // 迭代次数
	CRules	const m_rules;					// 产生式规则
	wstring		  m_resultstr;				// 结果串
private:
	int ProduceStr();
public:
	// 设置遍历深度，并且产生结果串
	int SetDegree(int degree);
	wstring getResult()const;
};


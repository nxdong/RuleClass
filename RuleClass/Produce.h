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
	wstring const m_src;					// Դ��
	int		      m_degree;				    // ��������
	CRules	const m_rules;					// ����ʽ����
	wstring		  m_resultstr;				// �����
private:
	int ProduceStr();
public:
	// ���ñ�����ȣ����Ҳ��������
	int SetDegree(int degree);
	wstring getResult()const;
};


#pragma once

namespace Musoeun
{
	class MCommand
	{
	public:
		MCommand() {}
		virtual ~MCommand() {}

		virtual void Execute() { }
	};
};
//commad ����
//overload
//overide
//virtyal

//binding
//���α׷� �ҽ��� ���� ���� ���� ���, �̸� �ĺ��ڵ鿡 ���� �� �Ǵ� �Ӽ��� Ȯ���ϴ� ����
//���� ���ε�(static binding) ���ε� ������ ������ ������ �̷������ ���ε�
//���� ���ε�(dynamic binding) ���ε� ������ ���α׷� �����߿� �̷������ ���ε�

#pragma once
#include "SCommand.hpp";

class MeCommand : public Cool::SCommand
{
public:
	void Execute()
	{
		std::cout << "¹ÌÇ³ ÄÑÁü";
	}
};
class YakCommand : public Cool::SCommand
{
public:
	void Execute()
	{
		std::cout << "¾àÇ³ ÄÑÁü";
	}
};
class KangCommand : public Cool::SCommand
{
public:
	void Execute()
	{
		std::cout << "°­Ç³ ÄÑÁü";
	}
};
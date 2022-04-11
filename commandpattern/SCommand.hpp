#pragma once

namespace Cool
{
	class SCommand
	{
	public:
		SCommand() {}
		virtual ~SCommand() {}

		virtual void Execute() { }
	};
};//버추얼을 붙여야지 소멸자가 
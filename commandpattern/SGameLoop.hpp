#pragma once

namespace Cool
{
	SCommand* key[2];

	void Initialize()
	{
		key[0] = new MeCommand();
		key[1] = new YakCommand();
		key[2] = new KangCommand();
	}

	void Input()
	{
		int input;
		std::cin >> input;

		key[input]->Execute();
	}

	void Update()
	{
	}

	void Rendrt()
	{
	}
	void Release()
	{
		for (size_t i = 0; i < 3; i++)
		{
			delete(key[i]);
		}
	}

	class SGameLoop
	{
	public:
		bool isGameRunning = false;
		SGameLoop()
		{}
		~SGameLoop()
		{}

		void Run()
		{
			isGameRunning = true;

			Initialize();

			while (isGameRunning)
			{
				Input();
				Update();
				Rendrt();
			}
			Release();
		}
	};
}
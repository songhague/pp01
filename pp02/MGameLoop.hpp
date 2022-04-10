#pragma once

namespace Musoeun
{
	MCommand *key[5];

	void Initialize()
	{
		key[0] = new LeftCommand();
		key[1] = new RightCommand();
		key[2] = new DownCommand();
		key[3] = new JumpCommand();
		key[4] = new RunCommand();
		//std::cout << "초기화...\n";
		//3강꺼
	}

	void Input()
	{
		int input;
		std::cin >> input;

		key[input]->Execute();

		//std::cout << "입력중...\n";
		//std::cin >>a;
	}

	void Update()
	{
		//std::cout << "업데이트중...\n";
	}

	void Rendrt()
	{
		//std::cout << "도는중...\n";
	}
	void Release()
	{
		//std::cout << "삭제중...\n";
		for (size_t i = 0; i < 5; i++)
		{
			delete(key[i]);
		}
	}

	class MGameLoop
	{
	public:
		bool isGameRunning = false;
		MGameLoop()
		{}
		~MGameLoop()
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
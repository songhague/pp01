//#include <iostream>
//#include<string>
//
//using namespace std;
//int is_game_running = false;
//
//class GameObject
//{
//public :
//	GameObject()
//	{
//		cout << "게임 오브젝트 생성!\n";
//	}
//	virtual ~GameObject()
//	{
//		cout << "게임 오브젝트 소멸!\n";
//	}
//
//	virtual void Start()
//	{
//		cout << "게임 오브젝트 스타트!\n";
//	}
//	virtual void Update() 
//	{
//		cout << "게임 오브젝트 스타트!\n";
//	}
//};
//
//class Player : public GameObject 
//{
//public :
//	int HP = 100;
//
//	Player() 
//	{
//		cout << "송하규 생성!!!\n";
//	}
//	~Player()
//	{
//		cout << "송하규 소멸!!!\n";
//	}
//	void Start()
//	{
//		cout << "송하규의 HP는" << HP << "입니다!\n";
//	}
//	void Update()
//	{
//		cout << "송하규 업데이트\n";
//	}
//};
//class Enemy : public GameObject
//{
//public:
//	int HP = 100;
//
//	Enemy()
//	{
//		cout << "이대환 생성!!!\n";
//	}
//
//	~Enemy()
//	{
//		cout << "이대환 소멸!!!\n";
//	}
//
//	void Start()
//	{
//		cout << "이대환의 HP는"<< HP << "입니다!\n";
//	}
//
//	void Update()
//	{
//		cout << "이대환 업데이트\n";
//	}
//};
//
//int main()
//{
//	is_game_running = true;
//
//	GameObject* p = new Player();
//	GameObject* e = new Enemy();
//
//	p->Start();
//	e->Start();
//
//	while (is_game_running)
//	{
//		p->Update();
//		e->Update();
//
//		cout << "입력해주세요 (1: 게임 종료, 2: 게임 계속): ";
//		int input;
//		cin >> input;
//		if (input == 1)
//			is_game_running = false;
//	}
//
//	delete(p);
//	delete(e);
//
//	return 0;
//}
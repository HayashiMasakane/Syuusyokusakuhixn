
#include"SceneManager.h"
#include"TestScene.h"
//	エントリーポイント
int main()
{


	SceneManager::GetInstance().Init();

	SceneManager::GetInstance().AddScene<TestScene>("test");
	SceneManager::GetInstance().AddScene<TestScene>("test2");

	SceneManager::GetInstance().ChangeMainScene("test");
	SceneManager::GetInstance().Update();
	SceneManager::GetInstance().ChangeMainScene("test2");
	SceneManager::GetInstance().Update();







	return 0;
}

#include"SceneManager.h"
#include"TestScene.h"
//	エントリーポイント
int main()
{


	SceneManager::GetInstance().Init();

	SceneManager::GetInstance().AddScene<TestScene>("test");
	SceneManager::GetInstance().ChangeMainScene("test");


	SceneManager::GetInstance().Update();







	return 0;
}
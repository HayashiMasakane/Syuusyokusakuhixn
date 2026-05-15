
#include"SceneManager.h"
#include"TectScene.h"
//	エントリーポイント
int main()
{


	SceneManager::GetInstance().Init();
	SceneManager::GetInstance().AddScene<TectScene>("test");

	SceneManager::GetInstance().ChangeMainScene("rrr");
	SceneManager::GetInstance().ChangeMainScene("test");


	SceneManager::GetInstance().Update();







	return 0;
}
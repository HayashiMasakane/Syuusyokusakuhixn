//	オブジェクト関係
#include"GameObjectManager.h"
#include"GameObject.h"
#include"TestObject1.h"

//	scene関係
#include"SceneManager.h"
#include"Scene.h"

//	エントリーポイント
int main()
{
	using namespace Framework;
	//	オブジェクトの確認
	{
	//GameObject::GameObjectManager gameObjectManager;

	//gameObjectManager.AddGameObject<GameObject::GameObjects::TestObject1>("test1");

	////	追加していない場合のエラー確認	成功
	//gameObjectManager.GetGameObject("test1");

	////	デリーとの確認
	//GameObject::GameObject* gameObject1 = gameObjectManager.GetGameObject("test1");
	//gameObjectManager.DeteleGameObject();	//	予約されていない場合の確認
	//gameObject1->SetDeleteFlag();
	//gameObjectManager.DeteleGameObject();	//	予約した場合の確認
	}

	
	Framework::Scene::SceneManager::GetInstanse().Update();
	//	AddSceneのエラー確認
	Framework::Scene::SceneManager::GetInstanse().AddScene<Scene::Scene>("testScene");
	Framework::Scene::SceneManager::GetInstanse().AddScene<Scene::Scene>("testScene");
	
	//	ChangeSceneのエラー確認
	Framework::Scene::SceneManager::GetInstanse().ChangeScene("testScene");
	Framework::Scene::SceneManager::GetInstanse().ChangeScene("ellr");

	Framework::Scene::SceneManager::GetInstanse().Update();



	//	終了処理
	return 0;
}
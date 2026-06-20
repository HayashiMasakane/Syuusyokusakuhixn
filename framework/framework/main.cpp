#include"GameObjectManager.h"
#include"GameObject.h"
#include"TestObject1.h"
//	エントリーポイント
int main()
{
	using namespace Framework;

	GameObject::GameObjectManager gameObjectManager;

	gameObjectManager.AddGameObject<GameObject::GameObjects::TestObject1>("test1");

	//	追加していない場合のエラー確認	成功
	gameObjectManager.GetGameObject("test1");

	//	デリーとの確認
	GameObject::GameObject* gameObject1 = gameObjectManager.GetGameObject("test1");
	gameObjectManager.DeteleGameObject();	//	予約されていない場合の確認
	gameObject1->SetDeleteFlag();
	gameObjectManager.DeteleGameObject();	//	予約した場合の確認


	//	終了処理
	return 0;
}
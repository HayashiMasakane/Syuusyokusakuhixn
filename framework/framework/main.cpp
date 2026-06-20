#include"GameObjectManager.h"
#include"GameObject.h"
//	エントリーポイント
int main()
{
	Framework::GameObject::GameObjectManager gameObjectManager;

	gameObjectManager.AddGameObject<Framework::GameObject::GameObject>("aaa");
	gameObjectManager.AddGameObject<Framework::GameObject::GameObject>("aaa");

	
	gameObjectManager.GetGameObject("ccc");




	//	終了処理
	return 0;
}
#include "GameObject.h"
#include"TestComponent.h"
#include<iostream>

/// <summary>
/// 生成時にオブジェクト名を変更
/// 任意ののオブジェクト名に変更
/// </summary>
/// <param name="_gameObjectId">オブジェクト番号を入れる</param>
GameObject::GameObject(const GameObjectId& _gameGameObjectId) :m_gameObjectId(m_gameObjectId)
{
	std::cout << "GameObject作成:" << m_gameObjectId << std::endl;

}

/// <summary>
/// 削除されるときにUninit()を処理する
/// </summary>
GameObject::~GameObject()
{
	std::cout << "GameObject削除:" << m_gameObjectId << std::endl;
}

/// <summary>
/// オブジェクト名を返す
/// </summary>
/// <returns>オブジェクト名を返すconst参照</returns>
const GameObjectId& GameObject::GetGameObjectId()
{
	return m_gameObjectId;


}




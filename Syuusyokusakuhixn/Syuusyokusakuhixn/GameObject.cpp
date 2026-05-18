#include "GameObject.h"
#include"TestComponent.h"
#include<iostream>

/// <summary>
/// 生成時にオブジェクト名を変更
/// 任意ののオブジェクト名に変更
/// </summary>
/// <param name="_gameObjectId">オブジェクト番号を入れる</param>
/// <param name="_componentManager">Scnen内のプライベート変数::コンポネントマネージャを入れる</param>
GameObject::GameObject(const GameObjectId& _gameObjectId, ComponentManager& _componentManager) :m_gameObjectId(_gameObjectId), m_componentManager(_componentManager)
{
}

/// <summary>
/// 削除されるときにUninit()を処理する
/// </summary>
GameObject::~GameObject()
{
}

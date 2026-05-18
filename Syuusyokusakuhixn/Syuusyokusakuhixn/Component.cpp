#include "Component.h"
#include<iostream>
/// <summary>
/// 生成時にこのコンポーネントを持っているオブジェクトのIdを格納
/// </summary>
/// <param name="_gameObjectId">これを持っているオブジェクトid</param>
Component::Component(const GameObjectId& _gameObjectId) :m_gameObjectId(_gameObjectId)
{
}



/// <summary>
/// これを所持しているオブジェクトののIdを渡す
/// </summary>
/// <returns>これを所持しているオブジェクトののIdをconst 参照で渡す</returns>
const GameObjectId& Component::GetGameObjectId()
{
	return m_gameObjectId;
}

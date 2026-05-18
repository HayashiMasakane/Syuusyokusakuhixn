#pragma once
#include"GameObjectId.h"
/// <summary>
/// Componentの基底クラス
/// </summary>
class Component
{
private:
	const GameObjectId m_gameObjectId;

public:
	Component(const GameObjectId& _gameObjectId);
	virtual ~Component() = default;

	virtual void Init() = 0;
	virtual void Uninit() = 0;
	//	Updateはシステムでする

	const GameObjectId& GetGameObjectId();

};
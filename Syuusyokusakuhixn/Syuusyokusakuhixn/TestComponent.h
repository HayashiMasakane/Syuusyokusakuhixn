#pragma once

#include"Component.h"

/// <summary>
/// ‚¿‚á‚ñ‚Æ“®‚­‚©‚ÌŠm”F—p
/// </summary>
class TestComponent :public Component
{
public:
	TestComponent(const GameObjectId _gameObjectId);
	~TestComponent();

	 void Init() override;
	 void Uninit() override;
};


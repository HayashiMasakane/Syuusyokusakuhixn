#pragma once
#include "Scene.h"

/// <summary>
///	シーンがちゃんと動くかオブジェクトが動くかを調べるための派生シーン
/// </summary>
class TestScene :public Scene
{
public:
	TestScene() = default;
	~TestScene()override {};


	void Init()override;
	void Uninit()override;
	void Update() override;
	void Draw()override;

};


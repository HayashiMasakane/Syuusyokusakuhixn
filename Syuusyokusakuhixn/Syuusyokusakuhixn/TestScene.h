#pragma once
#include "Scene.h"
#include<string >
/// <summary>
///	シーンがちゃんと動くかオブジェクトが動くかを調べるための派生シーン
/// </summary>
class TestScene :public Scene
{
public:
	TestScene(std::string _sceneName);
	~TestScene()override = default;


	void Init()override;
	void Uninit()override;
	void Update() override;
	void Draw()override;

};


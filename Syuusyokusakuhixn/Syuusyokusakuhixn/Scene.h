#pragma once

/// <summary>
///	sceneの基底クラス
/// sceneマネージャでインスタンスを作る
/// </summary>
class Scene
{


public:
	virtual void Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;



};


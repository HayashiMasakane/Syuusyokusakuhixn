#pragma once

/// <summary>
/// ゲーム本体クラス
/// アプリケーションクラスがインスタンスを持つ
/// </summary>
class Game
{
private:

	static	void Update();
	static	void Draw();

public:

static	void Init();
static	void Uninit();


static	void GameLoop();


};


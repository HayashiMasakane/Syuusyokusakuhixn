#include "SceneManager.h"
#include"Scene.h"
#include<Windows.h>

/// <summary>
/// 自動でUninitを処理する
/// </summary>
SceneManager::~SceneManager()
{
	Uninit();
}

/// <summary>
/// 参照インスタンスを返す
/// パブリック関数を使うには必要
/// </summary>
/// <returns>インスタンスを返す</returns>
SceneManager& SceneManager::GetInstance()
{
	static SceneManager instance;
	return instance;
}

/// <summary>
/// SceneManager を初期化
/// </summary>
void SceneManager::Init()
{
}

/// <summary>
/// メソッド変数全てを解放する
/// </summary>
void SceneManager::Uninit()
{

	//	scenes全てのUnint()を回し解放する
	for (auto& scene : m_scenes)
	{
		scene.second->Uninit();
	}
	m_scenes.clear();
	m_mainScene = nullptr;
}

/// <summary>
/// MainSceneの更新
/// </summary>
void SceneManager::Update()
{
	//	シーンの変更予約があるなら新しいシーンに変更する
	if (!m_nextMainSceneName.empty())
	{
		if (m_mainScene)
		{
			m_mainScene->Uninit();
		}

		m_mainScene = m_scenes[m_nextMainSceneName].get();
		m_mainScene->Init();

		m_nextMainSceneName.clear();
	}


	m_mainScene->Update();
}

/// <summary>
/// MainSceneの描画
/// </summary>
void SceneManager::Draw()
{
	m_mainScene->Draw();
}

/// <summary>
/// シーンを入れ替える予約を入れる
/// シーンがあるなら次フレームのUpdate()で実際に入れ替える
/// </summary>
/// <param name="_name"></param>
void SceneManager::ChangeMainScene(const std::string _name)
{

	if (!m_scenes.contains(_name))
	{
		MessageBoxA(NULL, "ChangeMainSceneの引数のシーンがありません", "えらー", MB_ICONWARNING | MB_OK);
		return;
	}

	m_nextMainSceneName = _name;

}




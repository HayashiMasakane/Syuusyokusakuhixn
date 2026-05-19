#include "SceneManager.h"
#include<Windows.h>
#include<iostream>
#include"Scene.h"


/// <summary>
/// 自動でUninitを処理する
/// </summary>
SceneManager::~SceneManager()
{
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << "~SceneManager()" << std::endl;

	Uninit();
}

void SceneManager::ChangeScene()
{
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << "ChangeScene" << std::endl;

	if (m_mainScene)
	{
		std::cout << "DeleteMainScene " << std::endl;
		DeleteMainScene();
	}
	std::cout << "Scene::Init()" << std::endl;

	m_mainScene = m_scenes[m_nextMainSceneName].get();
	m_mainScene->Init();

	m_nextMainSceneName.clear();
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
		//	削除するシーンの名前を表示
		const std::string& sceneName = scene.first;
		std::cout << "Uninit():" << sceneName << std::endl;

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
		ChangeScene();
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
	std::cout << "ChangeMainScene:" << _name << std::endl;
	if (!m_scenes.contains(_name))
	{
		MessageBoxA(NULL, "ChangeMainSceneの引数のシーンがありません", "えらー", MB_ICONWARNING | MB_OK);
		return;
	}

	m_nextMainSceneName = _name;

}

/// <summary>
/// m_mainSceneの削除処理
/// </summary>
void SceneManager::DeleteMainScene()
{
	std::cout << "Scene::Uninit()" << std::endl;
	m_mainScene->Uninit();
}




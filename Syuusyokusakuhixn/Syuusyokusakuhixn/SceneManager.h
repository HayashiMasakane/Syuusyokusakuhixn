#pragma once
#include<unordered_map>
#include<memory>
#include<string>
#include<Windows.h>
class Scene;

/// <summary>
/// sceneの生成管理をするシングルトン
/// m_scenesでシーンををインスタンス化
/// </summary>
class SceneManager
{
private:
	using SceneMap = std::unordered_map<std::string, std::unique_ptr<Scene>>;
	SceneMap m_scenes;

	//	更新シーン
	Scene* m_mainScene = nullptr;

	//	変更先の名前
	std::string m_nextMainSceneName;


	SceneManager() = default;
	~SceneManager();
	SceneManager(SceneManager&) = delete;
	SceneManager operator=(SceneManager&) = delete;

	void ChangeScene();

public:
	//	参照インスタンスを返す
	static  SceneManager& GetInstance();

	void Init();
	void Uninit();
	void Update();
	void Draw();

	template<typename T>
	void AddScene(const std::string _name);
	//	現在のsceneを引数のsceneに変更予約をする
	void ChangeMainScene(const std::string _name);
	void DeleteMainScene();


};

#include<iostream>
/// <summary>
/// シーンクラスをマネージャーに追加
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="_name"></param>
template<typename T>
inline void SceneManager::AddScene(const std::string _name)
{
	//	同じ名前のシーンがあるならリターン
	if (m_scenes.contains(_name))
	{
		MessageBoxA(NULL, "警告", "すでに同じシーンがあります", MB_ICONWARNING | MB_OK);
		return;
	}

	m_scenes[_name] = std::make_unique<T>(_name);
	std::cout << "AddScene:" << _name << std::endl;

	//	mainSceneがないなら入れる
	if (m_mainScene == nullptr)
	{
		m_nextMainSceneName = _name;
	}
}

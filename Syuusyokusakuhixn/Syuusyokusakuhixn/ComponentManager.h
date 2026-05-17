#pragma once
#include<vector>
#include<unordered_map>
#include<typeindex>
#include"GameObjectId.h"

class Component;
class GameObject;

/// <summary>
/// コンポーネントの生成管理をする。Componentの更新はシステムでする
/// AddComponentはGameObjectクラスで使う
/// </summary>
class ComponentManager
{
private:
    //  フレンド宣言
    friend GameObject;


    // 型ごとに vector<T> を保持するための辞書
    //  type_index  :Component派生クラス
    //  void*       :vector<T>の先頭アドレスを入れる
    std::unordered_map<std::type_index, void*> m_componentMap;



    // 型ごとに vector<T> を取得（なければ作る）
    template<typename T>
    std::vector<T>& GetMap()
    {
        auto key = std::type_index(typeid(T));

        // まだ配列がないなら作る
        if (m_componentMap.find(key) == m_componentMap.end())
        {
            m_componentMap[key] = new std::vector<T>();
        }

        return *static_cast<std::vector<T>*>(m_componentMap[key]);
    }



    /// <summary>
    /// コンポーネントを追加（同じコンポーネントも付けれるぞ）
    /// ゲームオブジェクトクラス内で登録する
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="_name"></param>
    /// <returns></returns>
    template<typename T>
    T* AddComponent(GameObjectId _name)
    {
        auto& arr = GetMap<T>();

        arr.push_back(T(_name));
        T* comp = &arr.back();

        return comp;
    }


public:




    // Component の配列をシステムに渡す
    template<typename T>
    std::vector<T*> GetComponents(GameObjectId owner)
    {
        std::vector<T*> result;

        auto& arr = GetMap<T>();
        for (auto& c : arr)
        {
            if (c.owner == owner)
                result.push_back(&c);
        }

        return result;
    }

};

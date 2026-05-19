#include "TestSystem.h"
#include<iostream>
#include<vector>
#include"ComponentManager.h"
#include"TestComponent.h"

/// <summary>
/// シーンに入っているtestComponentの数分coutする
/// </summary>
/// <param name="_componentManger"></param>
void TestSystem(ComponentManager& _componentManger)
{
	std::cout << "TestSystem開始" << std::endl;

	auto testComs = _componentManger.GetAllComponents<TestComponent>();

	for (auto& com : testComs)
	{
		std::cout << "TestSystem:for" << std::endl;
	}


	std::cout << "TestSystem終了" << std::endl;

}

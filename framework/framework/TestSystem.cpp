#include"TestSystem.h"
#include"TestComponent.h"

using namespace Framework::Component::Components;

void TestSystem(const std::vector<TestComponent*>& _testComponents)
{
	//	Å‘å”‚ğæ“¾
	int maxNum = _testComponents.size();



	for (int num = 0; num < maxNum; num++)
	{
		_testComponents[num]->TestCommentDraw();
	}

}


#include "TestComponent.h"
#include<iostream>
namespace Framework
{
	namespace Component
	{
		namespace Components
		{

			void TestComponent::OnInit()
			{
				std::cout << "テストコンポーネント初期化" << std::endl;
			}
			void TestComponent::OnUninit()
			{
				m_testcom1 = nullptr;
				std::cout << "テストコンポーネント終了" << std::endl;

			}

			void TestComponent::SetTestComponent1(TestComponent1* _testcom1)
			{
				m_testcom1 = _testcom1;
			}

			void TestComponent::TestCommentDraw()
			{
				std::cout << "TestCommentDraw実行" << std::endl;
				
			}





		}
	}
}


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
				std::cout << "テストコンポーネント終了" << std::endl;

			}

			void TestComponent::TestCommentDraw()
			{
				std::cout << "TestCommentDraw実行" << std::endl;
				
			}





		}
	}
}


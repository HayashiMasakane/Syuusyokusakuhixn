#include "TestComponent1.h"
#include<iostream>
namespace Framework
{
	namespace Component
	{
		namespace Components
		{

			void TestComponent1::OnInit()
			{
				std::cout << "テストコンポーネント1初期化" << std::endl;
			}
			void TestComponent1::OnUninit()
			{
				std::cout << "テストコンポーネント1終了" << std::endl;

			}

			void TestComponent1::TestCommentDraw()
			{
				std::cout << "TestCommentDraw実行" << std::endl;

			}





		}
	}
}
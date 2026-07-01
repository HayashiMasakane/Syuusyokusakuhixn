#pragma once
#include "Component.h"


namespace Framework
{
	namespace Component
	{
		namespace Components
		{
			/// <summary>
			/// テストコンポーネントに関連図ける物
			/// </summary>
			class TestComponent1 :public Component
			{
			private:
				void OnInit()override;
				void OnUninit()override;

			public:
				void TestCommentDraw();



			};

		}
	}
}


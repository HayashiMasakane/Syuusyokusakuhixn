#pragma once
#include "Scene.h"

namespace Framework
{
	namespace Scene
	{
		namespace Scenes
		{
			class TestScene1 : public Scene
			{
			private:
				void OnInit()override;
				void OnUninit()override;
				void OnUpdate()override;
				void OnDraw()override;

			public:
				TestScene1() = default;
				~TestScene1();




			};



		}

	}//	Scene
}//	Framework

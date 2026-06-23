#pragma once

namespace Framework
{
	namespace Scene
	{
		class Scene
		{
		private:

		protected:
			//	派生オブジェクトの処理用
			//virtual void OnInit() = 0;
			//virtual void OnUninit() = 0;
			//virtual void OnUpdate() = 0;
			//virtual void OnDraw() = 0;

		public:
			Scene() = default;
			~Scene();

			void Init();
			void Uninit();
			void Update();
			void Draw();

		};

	}//	Scene
}//	Framework
#pragma once

namespace Framework
{
	namespace GameObject
	{
		/// <summary>
		/// GameObject基底クラス
		/// インスタンスはオブジェクトマネージャーが持つ
		/// </summary>
		class GameObject
		{
		protected:
			//	派生オブジェクトの処理用
		//	virtual void OnInit() = 0;
		//	virtual void OnUninit() = 0;



		public:
			GameObject() = default;
			~GameObject() = default;

			void Init();
			void Uninit();

		};

	}//	GameObject
}//	Framework




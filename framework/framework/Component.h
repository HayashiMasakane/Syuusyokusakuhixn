#pragma once

namespace Framework
{

	namespace Component
	{
		/// <summary>
		/// コンポーネント基底クラス
		/// </summary>
		class Component
		{
		private:
			bool m_deleteFlag = false;


		protected:
			//	派生オブジェクトの処理用
			virtual void OnInit() = 0;
			virtual void OnUninit() = 0;

		public:
			Component() = default;
			~Component() = default;

			void Init();
			void Uninit();

			void SetDeleteFlag();
			bool GetDeleteFlag();

			//	派生クラスのメソッドポインタ変数にnullがいるなら弾く
			//	ように派生クラスで書く
			virtual	bool HasMethodPointerComponent() = 0;

		};


	}//	Component
}//	Framework


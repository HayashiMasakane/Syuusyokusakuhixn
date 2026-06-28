#include "Component.h"
namespace Framework
{
	namespace Component
	{
		void Component::Init()
		{
			OnInit();
		}
		void Component::Uninit()
		{
			OnUninit();
		}

		/// <summary>
		/// íœ—\–ñ‚ğƒZƒbƒg
		/// </summary>
		void Component::SetDeleteFlag()
		{
			m_deleteFlag = true;
		}

		/// <summary>
		/// íœ—\–ñ‚ğæ“¾
		/// </summary>
		/// <returns></returns>
		bool Component::GetDeleteFlag()
		{
			return m_deleteFlag;
		}


	}//	Component
}//	Framework
#ifndef LEDA_EXCEPTION_HH
#define LEDA_EXCEPTION_HH
#include "string.hh"

namespace LEDA
{
	class InvalidArgumentException
	{
		protected:
			String m_what_happened;

		public:
			InvalidArgumentException(const String& what_happened)
			{
				m_what_happened=what_happened;
			}

			String what_happened() const
			{
				return m_what_happened;
			}

			operator String() const
			{
				return what_happened();
			}
	}
}

#endif


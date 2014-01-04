#ifndef LEDA_DRAWABLE_HH
#define LEDA_DRAWABLE_HH
#include "types.hh"

namespace LEDA
{
	class DrawVisitor
	{
		protected:
			DrawVisitor() // OpenGL and stuff here
			{}
	};

	template <unsigned int dimensions=2>
	class Drawable
	{
		protected:
			virtual void draw(const DrawVisitor&) const = 0;
	};
}

#endif


#ifndef LEDA_GEOMETRY_HPP
#define LEDA_GEOMETRY_HPP
#include "drawable.hh"
#include "types.hh"
#include "macros.hh"
#include "value.hh"

namespace LEDA
{
	template<uint number_of_coords=2, typename CoordType=Value>
	class Coords
	{
		protected:
			CoordType m_coords[number_of_coords];

		public:
			CoordType operator[](uint n)
			{
				ASSERT(n<number_of_coords);
				return m_coords[n];
			}
	};

	typedef Coords<2> Coords2D;
	typedef Coords<3> Coords3D;

	template<typename CoordType>
	class Polygon : public Drawable<CoordType::number_of_coords>
	{
		protected:
			PolygonData<CoordType> m_data;

		public:
			
	};

	class Rectangle : public Polygon
	{

	};
}

#endif


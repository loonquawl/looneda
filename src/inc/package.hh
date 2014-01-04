#ifndef LEDA_PACKAGE_HPP
#define LEDA_PACKAGE_HPP
#include "session.hh"
#include "string.hh"
#include "map.hh"
#include "types.hh"
#include "vector.hh"
#include "value.hh"

namespace LEDA
{
	class PackageElement : public Drawable 
	{
		protected:
			Value width

			PackageElement()
			{}
	};

	class Pad : public PackageElement
	{
		public:
	};

	class PackageText : public PackageElement
	{

	};

	class Package : public SessionBase, public Drawable
	{
		protected:
			class PackageLayer : public Named
			
				protected:
					Vector<PackageElement> m_elements;
					bool m_hidden;

					PackageLayer()
					{
						m_classname="PackageLayer";
					}

					PackageLayer(const String& name)
					: Named(name)
					{
						m_classname="PackageLayer";
					}

					operator String()
					{
						return get_name();
					}

					uint get_level()
					{
						return m_level;
					}
			};

			Vector<PackageLayer>	m_layers;

		public:
			Package()
			{
				m_classname="Package";
			}

			Package(const String& name)
			: SessionBase(name)
			{
				m_classname="Package";
			}
	};
}

#endif


#ifndef LEDA_UNIT_HPP
#define LEDA_UNIT_HPP
#include <stdexcept>
#include "types.hh"
#include "string.hh"
#include "session.hh"

namespace LEDA
{
	template<typename Valtype=DefaultNumericalType>
	class Unit : public SessionBase
	{
		public:
			enum class UnitType
			{
				length,
				area,
				volume,

				mass,
				speed,

				voltage,
				current,
				resistance
			};

			const char* mc_unit_type_names[] = 
			{
				"length",
				"area",
				"volume",
				
				"mass",
				"speed",

				"voltage",
				"current",
				"resistance"
			};

		protected:
			Valtype m_metric_conv_ratio;
			UnitType m_type;

		public:

			Unit(const String& name, Valtype conversion_ratio, UnitType type)
			: SessionBase(name), m_metric_conversion_ratio(conversion_ratio), m_type(type)
			{
				m_classname="Unit";
			}

			operator String() const
			{
				return m_name;
			}

			operator Valtype() const
			{
				return m_metric_conversion_ratio;
			}

			operator UnitType() const
			{
				return m_type;
			}

			String get_name() const
			{
				return m_name;
			}

			Valtype get_metric_conv_ratio() const
			{
				return m_metric_conv_ratio;
			}

			Valtype get_conv_ratio(const Unit& u2) const
			{
				return m_metric_conv_ratio / u2.get_metric_conv_ratio();
			}

			UnitType get_type() const
			{
				return m_type;
			}
		
			const char* get_type_string() const
			{
				return mc_unit_type_names[(size_t)(m_type)];
			}

			bool is_of_the_same_type(const Unit& u2) const
			{
				return m_type == u2.get_type();
			}
	};
}

#endif


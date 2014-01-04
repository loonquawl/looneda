#ifndef LEDA_VALUE_H
#define LEDA_VALUE_HH
#include <stdlib.h>
#include <sstream>
#include "session.hh"
#include "string.hh"
#include "unit.hh"
#include "types.hh"

namespace LEDA
{
	template<typename Valtype=DefaultNumericalType>
	class Value : public SessionBase
	{
		protected:
			String m_unitname;
			Valtype m_value;

			void add(const Value& val2)
			{
				m_value += val2.as(m_unitname);
			}

			void sub(const Value& val2)
			{
				m_value -= val2.as(m_unitname);
			}
			
			void mul(const Value& val2)
			{
				m_value *= val2.as(m_unitname);
			}

			void div(const Value& val2)
			{
				// TODO std division by zero exception
				m_value /= val2.as(m_unitname);
			}

		public:
			Value()
			: m_value(0)
			{
				m_classname="Value";
			}

			Value(Valtype val, const String& unitname)
			: m_value(val), m_unitname(unitname)
			{
				m_classname="Value";
			}

			Value(const String& fromstring)
			{
				std::stringstream stream(fromstring);
				stream >> m_value >> m_unitname;
			}

			Valtype as(const String& unit_name)
			{
				if (unit_name == m_unitname)
					return m_value;

				// instance names in our session
				const String this_unitname = String(m_classname) + '#' + m_unitname;
				const String tgt_unitname  = String(m_classname) + '#' + unit_name;

				// we get a pointer type specified by implementation of our session instance
				// (weak_ptr, shared_ptr, etc)
				auto this_unit=static_cast<Unit<Valtype>*>((*mp_session)[this_unitname].get());
				auto tgt_unit=static_cast<Unit<Valtype>*>((*mp_session)[tgt_unitname].get());

			        if (this_unit == nullptr)
			        	throw InvalidArgumentException(String("Unit ")+this_unitname+" wasn't defined.");

				if (tgt_unit == nullptr)
					throw InvalidArgumentException(String("Unit ")+tgt_unitname+" wasn't defined.");
					
				if (!this_unit.is_of_the_same_type(tgt_unit))
					throw InvalidArgumentException(String("Cannot convert "+this_unit.get_type_string()+
								       " to "+tgt_unit.get_type_string()+".");
	
			        return m_value * this_unit->get_conv_ratio(*tgt_unit);
			}

			Valtype as(const Value& val)
			{
				// keep in mind it'll only work with same session's values
				return as(val.get_unitname());
			}

			Value operator=(Valtype val)
			{
				m_value=val;
			}

			operator Valtype()
			{
				return m_value;
			}

			operator String()
			{
				std::stringstream out;
				out << m_value << " " << m_unitname;
				return out.str();
			}
			
			void set_unit(const String& unitname)
			{
				m_value = as(unitname);
				m_unitname = unitname;
			}

			String get_unitname()
			{
				return m_unitname;
			}
	};

	template <typename Valtype>
	Value&& operator+(const Value<Valtype>& val1, const Value<Valtype>& val2)
	{
		return Value<Valtype>(val1).add(val2);
	}

	template <typename Valtype>
	Value&& operator-(const Value<Valtype>& val1, const Value<Valtype>& val2)
	{
		return Value<Valtype>(val1).sub(val2);
	}

	template <typename Valtype>
	Value&& operator*(const Value<Valtype>& val1, const Value<Valtype>& val2)
	{
		return Value<Valtype>(val1).mul(val2);
	}

	template <typename Valtype>
	Value&& operator/(const Value<Valtype>& val1, const Value<Valtype>& val2)
	{
		return Value<Valtype>(val1).div(val2);
	}
}

#endif


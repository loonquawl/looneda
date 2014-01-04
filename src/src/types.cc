#include <cstdlib>
#include "types.hh"
#include "string.hh"

using namespace LEDA;

template<>
HierarchyManager* Singleton<HierarchyManager>::sp_instance=nullptr;

unsigned int Base::s_instance_number = 0;

void Base::register_instance()
{
	HierarchyManager::inst().add_instance(this);
}

Base::Base()
: m_classname("Base")
{
	m_instance_number=++s_instance_number;
	register_instance();
}

Base::~Base()
{
	HierarchyManager::inst().remove_instance(this);
}

Session* Base::get_session()
{
	return SessionManager::inst()[String("Session#")+session_name].get();	
}

Named::Named()
{
	m_name=std::to_string(m_instance_number);
	m_classname="Named";
}

Named::Named(const String& name)
: m_name(name)
{
	m_classname="Named";
}


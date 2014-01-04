#include <assert.h>
#include "session.hh"
#include "macros.hh"

using namespace LEDA;

template<>
SessionManager* Singleton<SessionManager>::sp_instance=nullptr;

SessionBase::SessionBase()
{
	m_classname="SessionBase";
}

SessionBase::SessionBase(const String& name)
: Named(name)
{
	m_classname="SessionBase";
}

SessionBase::~SessionBase()
{
}


#ifndef LEDA_SESSION_HPP
#define LEDA_SESSION_HPP
#include "types.hh"
#include "manager.hh"
#include "map.hh"
#include "sharedptr.hh"
#include "singleton.hh"
#include "string.hh"

namespace LEDA
{
	class Session;

	/*
	 *	Data characteristic to an EDA session:
	 *	used units, used footprints, PCB, schematics, etc.
	 */

	class SessionBase : public Named
	{
		friend class Session;

		protected:
			SharedPtr<Session> mp_session;

		public:
			SessionBase();
			SessionBase(const String&);
			virtual ~SessionBase();

			SharedPtr<Session> get_session()
			{
				return mp_session;
			}
	};

	typedef Manager<SessionBase,String,UnorderedMap,SharedPtr> SessionMgrType;

	class Session : public Named, public SessionMgrType
	{
		public:
			Session()
			{
				m_classname="Session";
			}

			Session(const String& name)
			: Named(name)
			{
				m_classname="Session";
			}

			virtual void add_instance(SharedPtr<SessionBase> p_inst)
			{
				SessionMgrType::add_instance(p_inst);
				p_inst->mp_session=this;
			}
	};

	class SessionManager : public Manager<Session,String,UnorderedMap,SharedPtr>, public Singleton<SessionManager>
	{
		friend class Singleton<SessionManager>;

		protected:
			SessionManager()
			{}
	};
}

#endif


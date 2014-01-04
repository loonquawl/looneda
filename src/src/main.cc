#include <iostream>
#include "manager.hh"
#include "map.hh"
#include "package.hh"
#include "value.hh"

using namespace LEDA;
using namespace std;

int main()
{
	SessionManager::inst().add_instance(new Session("TestSession"));
	cout << SessionManager::inst()["Session#TestSession"].get()->get_key() << endl;
}


#include "AutomationAPI_RoutingCollection.h"
#include "AutomationAPI_Wire.h"
#include "AutomationAPI_WireBuilder.h"
#include <iostream>

AutomationAPI::RoutingCollection::RoutingCollection(int guid) : m_guid(guid)
{

}

#include <iostream>
#include "unit_test_that_fails_when_an_exception_is_thrown"
public void testRemoveBook( ) {
	try {
		library.removeBook( "Dune" );
	} catch (Exception e) {
		fail( e.getMessage( ) );
	}
	Book book = library.getBook( "Dune" );
	assertNull( "book is not removed", book );
}

AutomationAPI::RoutingCollection::~RoutingCollection()
{

}

AutomationAPI::WireBuilder* AutomationAPI::RoutingCollection::CreateWireBuilder(AutomationAPI::Wire* wire)
{
	if (wire == nullptr)
	{
		std::cout << "Block is creation mode" << std::endl;
	}
	else
	{
		std::cout << "Block is edit/query mode" << std::endl;
	}


	return nullptr;

}

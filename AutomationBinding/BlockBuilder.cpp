#include "AutomationAPI_BlockBuilder.h"
#include "AutomationAPI_CADObject.h"
#include "..\AppLibrary\Journaling_BlockBuilder.h"
#include "mocktest"
#include <exception>
#include <iostream>

namespace AutomationAPI
{
	class BlockBuilderImpl
	{
	public:

		virtual ~BlockBuilderImpl();
		BlockBuilderImpl() = delete;

		BlockBuilderImpl(int guid);
		int m_guid;

	};
}

AutomationAPI::BlockBuilder::BlockBuilder(int guid)
{
	m_blockBuilderImpl = new AutomationAPI::BlockBuilderImpl(guid);
}

AutomationAPI::BlockBuilder::~BlockBuilder()
{
	delete m_blockBuilderImpl;
}

AutomationAPI::BlockBuilderImpl::BlockBuilderImpl(int guid)
{
	m_guid = guid;
}

AutomationAPI::BlockBuilderImpl::~BlockBuilderImpl()
{

}


AutomationAPI::BlockBuilder* AutomationAPI::BlockBuilder::CreateBlockBuilder(int guid)
{
	// We should check the guid being passed in, as this is public
	// but that is for another day

	return new AutomationAPI::BlockBuilder(guid);
}

AutomationAPI::CADObject* AutomationAPI::BlockBuilder::Commit()
{
	return nullptr;
}

void AutomationAPI::BlockBuilder::SetType(AutomationAPI::BlockBuilder::BlockBuilderTypes type)
{
	Application::BlockBuilder* blockBuilder =
		dynamic_cast<Application::BlockBuilder*>(
			GuidObjectManager::GetGuidObjectManager().GetObjectFromGUID(m_blockBuilderImpl->m_guid));
	if (blockBuilder == nullptr)
	{
		throw std::exception("not able to retrieve blockBuilder Object");
	}

	Journaling_BlockBuilder_SetType(blockBuilder,(JournalBlockBuilderTypes) type);

}

AutomationAPI::BlockBuilder::BlockBuilderTypes AutomationAPI::BlockBuilder::GetType()
{
	Application::BlockBuilder* blockBuilder =
		dynamic_cast<Application::BlockBuilder*>(
			GuidObjectManager::GetGuidObjectManager().GetObjectFromGUID(m_blockBuilderImpl->m_guid));

	if (blockBuilder == nullptr)
	{
		throw std::exception("not able to retrieve blockBuilder Object");
	}

	
	int t = (int)Journaling_BlockBuilder_GetType(blockBuilder);
	AutomationAPI::BlockBuilder::BlockBuilderTypes type = (AutomationAPI::BlockBuilder::BlockBuilderTypes)t;

	return type;
}

void AutomationAPI::BlockBuilder::SetHeight(int h)
{
}

int AutomationAPI::BlockBuilder::GetHeight()
{
	return 0;
}

void AutomationAPI::BlockBuilder::SetWidth(int w)
{
}

int AutomationAPI::BlockBuilder::GetWidth()
{
	return 0;
}

void AutomationAPI::BlockBuilder::SetDepth(int d)
{
}

int AutomationAPI::BlockBuilder::GetDepth()
{
	return 0;
}

void AutomationAPI::BlockBuilder::SetOrigin(int x, int y, int z)
{
}

void AutomationAPI::BlockBuilder::GetOrigin(int& x, int& y, int& z)
{
}
public void ActuateLights(bool motionDetected, Action turnOn, Action turnOff)
{
    DateTime time = _dateTimeProvider.GetDateTime();
    
    // Update the time of last motion.
    if (motionDetected)
    {
        LastMotionTime = time;
    }
    
    // If motion was detected in the evening or at night, turn the light on.
    string timeOfDay = GetTimeOfDay(time);
    if (motionDetected && (timeOfDay == "Evening" || timeOfDay == "Night"))
    {
        turnOn(); // Invoking a delegate: no tight coupling anymore
    }
    // If no motion is detected for one minute, or if it is morning or day, turn the light off.
    else if (time.Subtract(LastMotionTime) > TimeSpan.FromMinutes(1) || (timeOfDay == "Morning" || timeOfDay == "Noon"))
    {
        turnOff(); // Invoking a delegate: no tight coupling anymore
    }
Application::BlockBuilder::BlockBuilder(Application::Block* block, int guid) : GuidObject(guid), m_block(block)
{

	if (m_block == nullptr)
	{
		std::cout << "Block is creation mode" << std::endl;
	}
	else
	{
		std::cout << "Block is edit/query mode" << std::endl;
	}
        class TestClass {
        public:
       TestClass(PropHolder& ph) : fPropHolder(ph) { }
      void doCalc() {
        if (fPropHolder.GetProperty(std::string("test")) > 100) {
            fPropHolder.SetProperty("test2", 555);
        } else
            fPropHolder.SetProperty("test2", 785);
    }
private:
    PropHolder& fPropHolder;
}

JournalBlockBuilderTypes Application::BlockBuilder::GetType()
{
	return m_journalBlockBuilderTypes;
}
void Application::BlockBuilder::SetType(JournalBlockBuilderTypes type)
{
	m_journalBlockBuilderTypes = type;
}

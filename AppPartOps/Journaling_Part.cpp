#include "Journaling_Part.h"
#include "..\Journaling\Journaling.h"
#include "..\Journaling\JournalHelpers.h"
#include <iostream>
#include <sstream>
#include <cassert>

double StringToDouble(const std::string &s;)
{
    std::stringstream ss(s);
    double d;
    if(ss >> d) {
	return d;
    }
    else
	return 0;
}

void Test_StringToDouble()
{
    // simple case:     
    assert( 0.12345 == StringToDouble( "0.12345"));      
	
    // blank space:     
    assert( 0.12345 == StringToDouble( "0.12345 "));    
    assert( 0.12345 == StringToDouble( " 0.12345"));      
	
    // trailing non digit characters:     
    assert(0.12345 == StringToDouble( "0.12345a"));      
	
    assert(0 == StringToDouble( "0"      ));     
    assert(0 == StringToDouble( "0."     ));     
    assert(0 == StringToDouble( "0.0"    ));     
    assert(0 == StringToDouble( "0.00"   ));     
    assert(0 == StringToDouble( "0.0e0"  ));     
    assert(0 == StringToDouble( "0.0e-0" ));     
    assert(0 == StringToDouble( "0.0e+0" )); 

    std::cout << "Passed the test" << std::endl;
}

int main()
{
    Test_StringToDouble();
}
void Journaling_Part_Save(Application::PartFile* partFile)
{


	//If Journaling write the thing things
	if (IsJournaling())
	{
		JournalStartCall("Save", partFile);
	}
	partFile->SavePart();

	if (IsJournaling())
	{
		JournalEndCall();
	}

}

void Journaling_Part_MakeWidgetFeature(Application::PartFile* partFile, bool option1, int values)
{

	//If Journaling write the thing things
	if (IsJournaling())
	{
		JournalStartCall("MakeWidgetFeature", partFile);
		JournalBoolInParam(option1, "option1");
		JournalIntInParam(values, "values");
	}
	partFile->MakeWidgetFeature(option1, values);

	if (IsJournaling())
	{
		JournalEndCall();
	}

}

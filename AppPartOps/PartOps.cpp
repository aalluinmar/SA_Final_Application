#include "PartOps.h"
#include "PartOpsInternal.h"
#include "DelMeBadPattern.h"
#include <iostream>
#include "..\Journaling\Journaling.h"
#include "..\Journaling\JournalHelpers.h"
#include "..\Core\GuidObject.h"
#include "..\AppLibrary\Feature.h"
#include "..\Core\StringUtils.h"
#include "..\Core\CoreSession.h"
#include "..\Core\Observer.h"
#include <algorithm>  // std::max_element
#include <cstdio>     // std::printf

#include "ampl/ampl.h"
using namespace std;
int main(int argc, char **argv) {
  try {
    std::string modelDirectory(argc == 3 ? argv[2] : "../models");
    modelDirectory += "/qpmv";

    // Create an AMPL instance
    ampl::AMPL ampl;

    /*
    // If the AMPL installation directory is not in the system search path:
    ampl::Environment env("full path to the AMPL installation directory");
    ampl::AMPL ampl(env);
    */

    // Number of steps of the efficient frontier
    const int steps = 10;

    if (argc > 1) ampl.setOption("solver", argv[1]);

    ampl.setBoolOption("reset_initial_guesses", true);
    ampl.setBoolOption("send_statuses", false);
    ampl.setOption("solver", "cplex");

    // Load the AMPL model from file
    ampl.read(modelDirectory + "/qpmv.mod");
    ampl.read(modelDirectory + "/qpmvbit.run");

    // Set tables directory (parameter used in the script above)
    ampl.getParameter("data_dir").set(modelDirectory);
    // Read tables
    ampl.readTable("assetstable");
    ampl.readTable("astrets");

    ampl::Variable portfolioReturn = ampl.getVariable("portret");
    ampl::Parameter averageReturn = ampl.getParameter("averret");
    ampl::Parameter targetReturn = ampl.getParameter("targetret");
    ampl::Objective variance = ampl.getObjective("cst");

    // Relax the integrality
    ampl.setBoolOption("relax_integrality", true);
    // Solve the problem
    ampl.solve();
    // Calibrate the efficient frontier range
    double minret = portfolioReturn.value();
    ampl::DataFrame values = averageReturn.getValues();
    ampl::DataFrame::Column col = values.getColumn("averret");
    double maxret = std::max_element(col.begin(), col.end())->dbl();
    double stepsize = (maxret - minret) / steps;
    double returns[steps];
    double variances[steps];

    for (int i = 0; i < steps; i++) {
      std::printf("Solving for return = %g\n", maxret - (i - 1) * stepsize);
      // Set target return to the desired point
      targetReturn.set(maxret - (i - 1) * stepsize);
      ampl.eval("let stockopall:={};let stockrun:=stockall;");
      // Relax integrality
      ampl.setBoolOption("relax_integrality", true);
      ampl.solve();
      std::printf("QP result = %g\n", variance.value());
      // Adjust included stocks
      ampl.eval("let stockrun:={i in stockrun:weights[i]>0};");
      ampl.eval("let stockopall:={i in stockrun:weights[i]>0.5};");
      // Set integrality back
      ampl.setBoolOption("relax_integrality", false);
      ampl.solve();
      std::printf("QMIP result = %g\n", variance.value());
      // Store data of corrent frontier point
      returns[i] = maxret - (i - 1) * stepsize;
      variances[i] = variance.value();
    }

    // Display efficient frontier points
    std::printf("RETURN    VARIANCE\n");
    for (int i = 0; i < steps; i++)
      std::printf("%-6f  %-6f\n", returns[i], variances[i]);
    return 0;
  } catch (const std::exception &e) {
    std::printf("%s\n", e.what());
    
}

Application::PartFile::PartFile(std::string partFilePath, int guid) : GuidObject(guid),  m_partFilePath(partFilePath)
{
	cout << "    PartFile::PartFile called with " << partFilePath << " " << guid << endl;
}

void Application::PartFile::ClosePart()
{
	cout << "    PartFile::ClosePart called" << endl;

	PartOpsNotifierData partOpsNotifierData;
	partOpsNotifierData.guid = this->GetGuid();
	partOpsNotifierData.partName = this->m_partFilePath;
	PartOpsNotifierData* ptr = &partOpsNotifierData;

	CoreSession::GetInstance().CreateMessage(Observer::ClosePart, (void*)ptr);
}

void Application::PartFile::SavePart()
{
	cout << "    PartFile::SavePart called" << endl;

	PartOpsNotifierData partOpsNotifierData;
	partOpsNotifierData.guid = this->GetGuid();
	partOpsNotifierData.partName = this->m_partFilePath;
	PartOpsNotifierData* ptr = &partOpsNotifierData;

	CoreSession::GetInstance().CreateMessage(Observer::SavePart, (void*)ptr);
}

void Application::PartFile::MakeWidgetFeature(bool option1, int values)
{
	cout << "    MakeWidgetFeature called with " << option1 << " " << values << endl;
}

Application::PartFile* Application::PartFile::CreatePartFile(std::string partFilePath)
{
	int guid = 123424; 

	Application::PartFile* partFile = new Application::PartFile( partFilePath, guid);
	GuidObjectManager::GetGuidObjectManager().SetObjectFromGUID(guid, partFile);

	PartOpsNotifierData partOpsNotifierData;
	partOpsNotifierData.guid = guid;
	partOpsNotifierData.partName = partFilePath;
	PartOpsNotifierData* ptr = &partOpsNotifierData;

	CoreSession::GetInstance().CreateMessage(Observer::CreatePart, (void*)ptr);
	return partFile;
}

Application::PartFile* Application::PartFile::OpenPartFile(std::string partFilePath)
{
	int guid = -1;
	
	ReadInPartFile(guid, partFilePath);


	PartFile* partFile = new PartFile(partFilePath, guid);
	GuidObjectManager::GetGuidObjectManager().SetObjectFromGUID(guid, partFile);
	
	PartOpsNotifierData partOpsNotifierData;
	partOpsNotifierData.guid = guid;
	partOpsNotifierData.partName = partFilePath;
	PartOpsNotifierData* ptr = &partOpsNotifierData;

	CoreSession::GetInstance().CreateMessage(Observer::OpenPart, (void*)ptr);

	return partFile;
}



std::string PartFileNameToken = "PartFileName:";
std::string SchemaVersionToken = "SchemaVersion:";



void ReadInPartFile(int & guid, std::string partFilePath)
{
	guid = 54321;
	string line;
	ifstream localPartFile(partFilePath);
	if (localPartFile.is_open())
	{
		while (getline(localPartFile, line))
		{
			cout << line << '\n';

			if (startsWith(line, PartFileNameToken))
			{
				std::string partFileName = line.substr(PartFileNameToken.size(), line.size() - PartFileNameToken.size());
				cout << "    "<< PartFileNameToken << " " << partFileName << endl;
			}
			else if (startsWith(line, SchemaVersionToken))
			{
				std::string partFileName = line.substr(SchemaVersionToken.size(), line.size() - SchemaVersionToken.size());
				cout << "    "<< SchemaVersionToken <<" " << partFileName << endl;
			}
			else if(startsWith(line, FeatureToken))
			{
				std::string featureType = line.substr(FeatureToken.size(), line.size() - FeatureToken.size());
				ProcessFeature(featureType, localPartFile);
			}


		}
		localPartFile.close();
	}


}

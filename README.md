# SA_Final_Application

> Estimation of Work

- We predicted that meeting the criteria and making the observer functionality more general would take 15-20 hours.

> Requirements

- The main requirements for our project are to implement a fake FlexLM system that will read the text file of licenses available, implementing a licensing library that rests on top of Flex LM Libraries. Requirements include cloud apps and desktop apps. In cloud apps, we require some type of credentials to use JSON API. We need a licensing toolkit that should be implemented on our own as a desktop app. We use Flexera called FLEXLM as a toolkit that must be paid. The team has to set up the local license file or license server on the network. The license file contains a list of entitlements which is validated when read by the license server. The hard part is to divide up the code so that the portions can only be accessed under the license features which we want. These are the main requirements to be considered for the project.

> Design Documents

- For Design Document, go through ([Design Document](https://github.com/aalluinmar/SA_Final_Application/blob/main/DESIGNDOCUMENT.md))

> Conclusions

- Requirements:
    The requirements are added to the application. As we know that the requirements are classified as required, desired and optional. Items that are listed as required are added as part of our project. Cloud apps and desktop apps are added to our application as part of our application.
- Design Document:
    Design document is also given in the project under read.md file which contains all the APIs. Journaling Layer APIs contain app part ops, automation binding and fake automation, journaling ,UI library. App part ops contain journaling part, partOps, dll main, journaling session. Automation binding includes wirebuilder, feature collection, rooting collection, extrude and block builder.
- Unit Tests:
    Unit tests are added to the project in the folder of core unit tests. Test.cpp file and pch.cpp files are the test files that contains unit tests for our application.
- Implementation:
    For our project fake FlexLM is implemented that reads the test files of licences available. We have used a licensing toolkit that is implemented.
    
  Finally, the licensing functionality is added to our project. The three licenses are added to our product which are basic, part operations, solid modeling. The licensing toolkit that is used is abstracted away. we made the API be differentiate calls to the functionality through the UI and automation API.
 

# SA_Final_Application

> Design Document

## AppPartOps
    
> journaling_part

    - Testing a function that which converts string to double string.
    - double StringToDouble(const std::string &s;);
    - This function accepts a string parameter and returns a double and if not, it returns 0.
    - void Test_StringToDouble();
    - This function peforms a series of checks to ensure that it works as expected.
    - Assert() evaluates its argument and calls abort() if the result is zero.

    ![alt journalingpart.png UML Diagram](https://github.com/aalluinmar/SA_Final_Application/tree/main/UML_Diagrams/journalingpart.png)

> PartOps

    - Entering models and data AMPL maintains a ‘‘current’’ model, which is the one that will be sent to the solver if you type solve. At the beginning of an interactive session, the current model is empty. A model command reads declarations from a file and adds them to the current model; a data command reads data statements from a file to supply values for components already in the current model. Thus you may use several model or data commands to build up the description of an optimization problem, reading data from different files. You can also type parts of a model and its data directly at an AMPL prompt. Model declarations such as param, var and subject to act as commands that add components to the current model.

    ![alt partops.png UML Diagram](https://github.com/aalluinmar/SA_Final_Application/tree/main/UML_Diagrams/partops.png)

> Dllmain

    - The following methods are  available to input AMPL commands;
        amplpy.AMPL.eval(), 
        amplpy.AMPL.read() and amplpy. AMPL.read_data() / readData();
        They send the strings specified (or the specified files) to the AMPL engine for interpretation. 
        Their async versions: 
            amplpy.AMPL.eval_async() / evalAsync(), amplpy.AMPL.read_async() / readAsync() and amplpy.AMPL.read_data_async() / readDataAsync(), permit the calling program to continue the execution while the underlying AMPL process is busy in some time consuming operation, and to define a callback to be executed when the operation is over.
    
    ![alt dllmain.png UML Diagram](https://github.com/aalluinmar/SA_Final_Application/tree/main/UML_Diagrams/dllmain.png)
    
> Journaling session

    - Set a callback for AMPL async operation implementation (amp1::Runnable) start and interrupt async operations.

    ![alt Journaling_session.png UML Diagram](https://github.com/aalluinmar/SA_Final_Application/tree/main/UML_Diagrams/Journaling_session.png)

## Automotion Binding

> Wirebuilder

    - With the additional message, the rest results provide better information about the cause of the test failure:
        1) testRemoveBook(LibraryTest)junit.framework.AssertionFailedError: book is not removed
    - Although all assert conditions ultimately must evaluate to a Boolean result of TRUE or FALSE, it can be tedious to constantly reduce every expression to this form. The xUnits offer a variety of assert functions to help. 
    - This assert method has variants that take a message parameter to describe the failure, as shown above. The assertEquals() method has variants that take different data types as arguments.

    ![alt wirebuilder.png UML Diagram](https://github.com/aalluinmar/SA_Final_Application/tree/main/UML_Diagrams/wirebuilder.png)

 > FeatureCollection

    - The expected error behavior is that an exception is thrown when the removeBook( ) where the method is called for a nonexistent Book. If the exception is thrown, the unit test succeeds. If it is not thrown, fail() is called. The fail( ) method is another useful variation on the basic assert method. It is equivalent to assertTrue(false), but it reads better.

    ![alt FeatureCollection.png UML Diagram](https://github.com/aalluinmar/SA_Final_Application/tree/main/UML_Diagrams/FeatureCollection.png)
    
> RootingCollection

    - This unit test uses fail() to cause the test to fail when an unexpected exception is thrown. The exception’s message attribute is used as the assert message.
    - The same general pattern is followed to test expected error behavior that is not represented by an exception: the test fails if the error is not seen and succeeds if it is.

    ![alt routingcollection.png UML Diagram](https://github.com/aalluinmar/SA_Final_Application/tree/main/UML_Diagrams/routingcollection.png)

> Extrude

    - The caller provides a DateTime argument, instead of secretly looking for this information by itself. From the unit testing perspective, this is great; the method is now deterministic that’s, its return value fully depends on the input), so state-based testing is as easy as passing some DateTime value and checking the result:

        public void GetTimeOfDay_For6AM_ReturnsMorning()
        {
            // Arrange phase is empty: testing static method, nothing to initialize

            // Act
            string timeOfDay = GetTimeOfDay(new DateTime(2016, 12, 31, 06, 00, 00));

            // Assert
            Assert.AreEqual("Morning", timeOfDay);
        }
    - Is the caller’s responsibility to provide date and time to the GetTimeOfDay(DateTime dateTime) method, meaning that they could become untestable if we don’t pay enough attention.

> BlockBuilder

    - The ActuateLights(bool motionDetected) method accept two more arguments: a pair of Action delegates, pointing to methods that should be called to turn the light on and off.

## Fake Automotion

> CallFakeJavaAutomotion

    - You use HTTPUrlConnection, If you are supporting clients who are using older versions of Java, and you can’t add a dependency then this might be for you.

> FakeAutomationJava

    - To create an interface which declares the methods you  call against the APOD API, with annotations defining how those correspond to HTTP requests.
    - The return typeof CompletableFuture<APOD> makes this an asynchronous client. Square with provide other adapters or you could write your own. Having an interface like this helps mocking the client for tests.
    - After declaring the interface we ask Retrofit to create an implementation which we can use to make requests against a given base URL. It’s also helpful for integration testing to be able to switch the base URL.


## Journaling

> JournalingCallData

    - If there are multiple methods in our interface which all need an API key it is possible to configure that by adding an HttpInterceptor to the base  OkHttp.client . The custom client can be added to the Retrofit.Builder.

    ![alt JournalCallData.png UML Diagram](https://github.com/aalluinmar/SA_Final_Application/tree/main/UML_Diagrams/JournalCallData.png)

> JournalCallParamDataClass

    - HttpClient accepts a BodyHandler which can convert an HTTP response into a class of your choosing. There are some built-in handlers: String, byte[] for binary data, Stream<String> which splits by lines, and a few others. You can also define your own, which might be helpful as there isn’t a built-in BodyHandler for parsing JSON.The code returns a Supplier for the APOD class, so we call .get() when we need the result.

    ![alt JournalCallParamDataClass.png UML Diagram](https://github.com/aalluinmar/SA_Final_Application/tree/main/UML_Diagrams/JournalCallParamDataClass.png)

> JournalFile

    - We are able to perform both state-based and interaction-based unit tests for it. Again, notice that in addition to improved testability, introducing a seam between the decision-making and action code helped to solve the tight coupling problem, and led to a cleaner, reusable API.


> Journaling.cpp

    - This method reads the current system time and returns a result based on that value. Essentially, a hidden input, that will probably change during program execution or between test runs. Thus, subsequent calls to it will produce different results.

## UI Library

> UI.cpp

    - In order to paint a panel, you have to overload the paint method of empanel. You can call the invalidatepainting() method of empanel1, if you want paint to be called again for whatever reason.

> Dllmain.cpp

    - To process keyboard and mouse input, then you have to overload the input method of empanel1. It gets the current mouse position (mx, my) in the coordinate system of the panel. When you overload the input method, you should not forget to call the base class implementation. Empanel1 itself eats certain keyboard and mouse events in order to change the focus. Therefore you should not eat those events before calling the base .class, but you may use them to do additional things.

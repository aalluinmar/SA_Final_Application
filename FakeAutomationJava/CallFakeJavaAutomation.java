
/* This is a simple Java program.
   FileName : "HelloWorld.java". */
   import java.io.*;

   public class CallFakeJavaAutomation
   {
       // Your program begins with a call to main().
       // Prints "Hello, World" to the terminal window.
       public static void main(String args[])
       {
           System.out.println("Hello, World from CallFakeJavaAutomation");
   
           FakeAutomationJava fakeClass = new FakeAutomationJava();
   
           String ans = fakeClass.DoSomeStuff(42, "What a great number");
   
           System.out.println("We got ans " + ans); 
   }
   
   // Create a neat value object to hold the URL
   URL url = new URL("https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY");
   
   // Open the connection(?) on the URL(??) and cast the response(???)
   HttpURLConnection connection = (HttpURLConnection) url.openConnection();
   
   // Being "open", we can set the request method, headers etc.
   connection.setRequestProperty("accept", "application/json");
   
   //Making  the request
   InputStream responseStream = connection.getInputStream();
   
   // Manually converting the response body InputStream to APOD using Jackson
   ObjectMapper mapper = new ObjectMapper();
   APOD apod = mapper.readValue(responseStream, APOD.class);
   
           
       }
}

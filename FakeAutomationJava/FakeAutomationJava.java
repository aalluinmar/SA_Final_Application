public interface APIClient {
    @GET("/planetary/apod")
    @Headers("accept: application/json")
    CompletableFuture<APOD> getApod(@Query("api_key") String apiKey);
 }
 Retrofit retrofit = new Retrofit.Builder()
    .baseUrl("https://apod.nasa.gov")
    .addConverterFactory(JacksonConverterFactory.create())
    .build();
 
 APODClient apodClient = retrofit.create(APODClient.class);
 
 CompletableFuture<APOD> response = apodClient.getApod("DEMO_KEY");
 
 // do other stuff here while the request is in-flight
 
 API  api = response.get();
 
 System.out.println(api.title);
 public class FakeAutomationJava
 {
 
     static {
         System.out.println("Loading native library");
         System.loadLibrary("jniAutomationLibrary");
     }
 
     FakeAutomationJava()
     {
 
     }
 
     native String DoSomeStuff(int p1, String p2);
}

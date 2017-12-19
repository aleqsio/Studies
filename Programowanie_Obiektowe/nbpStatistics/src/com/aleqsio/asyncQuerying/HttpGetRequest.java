package com.aleqsio.asyncQuerying;

import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Scanner;

public class HttpGetRequest {
    String url;
    public HttpGetRequest(String url) {
        this.url=url;
    }
    public String getDataAsString() throws IOException  {
        HttpURLConnection connection = (HttpURLConnection) new URL(url).openConnection();
        final int responseCode = connection.getResponseCode();
        switch (responseCode) {
            case 404:
                throw new IOException("Invalid time range");
            case 400:
                throw new IOException("Invalid request, possible that 93 days range was exceeded");
            case 200: {
                return new Scanner(connection.getInputStream(), "UTF-8").useDelimiter("\\A").next();
            }
            default:
                return null;
        }
    }
}

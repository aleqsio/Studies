package com.aleqsio.asyncQuerying;

import java.io.IOException;

import com.aleqsio.data.CurrencyData;
import com.aleqsio.data.CurrencyGsonDeserializer;
import com.google.gson.*;

/**
 * Created by Aleksander on 16.12.2017.
 */
public class AsyncSingleQueryServant implements IAsyncSingleQueryServant{
    private CurrencyGsonDeserializer currencyGsonDeserializer;
    private Class<CurrencyGsonDeserializer> currencyGsonDeserializerClass;
    public AsyncSingleQueryServant(Class<CurrencyGsonDeserializer> currencyGsonDeserializerClass) {
        this.currencyGsonDeserializerClass =currencyGsonDeserializerClass;
    }

    public CurrencyData getDataFromUrl(String url) throws IOException {
        HttpGetRequest request = new HttpGetRequest(url);
        String data = request.getDataAsString();

        GsonBuilder gsonBuilder = new GsonBuilder();
        gsonBuilder.registerTypeAdapter(CurrencyData.class, new currencyGsonDeserializerClass);
        Gson gson = gsonBuilder.create();
        return gson.fromJson(data , CurrencyData.class);
    }
}
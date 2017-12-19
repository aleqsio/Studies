package com.aleqsio.data;

import com.google.gson.*;

import java.lang.reflect.Type;
import java.sql.Date;

/**
 * Created by Aleksander on 17.12.2017.
 */
public class CurrencyGsonDeserializer implements JsonDeserializer{
    private final String url;

    public CurrencyGsonDeserializer(String url) {
        this.url=url;
    }
    @Override
        public CurrencyData deserialize(JsonElement json, Type typeOfT, JsonDeserializationContext context) throws JsonParseException {
        CurrencyData currencyData = new CurrencyData();
        System.out.println(url);
        //

            if(url.contains("cenyzlota")){
                for(JsonElement obj: json.getAsJsonArray()){
                    currencyData.data.put(new CurrencyData.CurrencyDateTypeKey(Date.valueOf(obj.getAsJsonObject().get("data").getAsString()),"GOLD", CurrencyData.ExchangeType.AVERAGE),obj.getAsJsonObject().get("cena").getAsDouble());
                }
            }
            // some data is returned in a size 1 array, so we unwrap it
            //if(json.isJsonArray()) json=json.getAsJsonArray().get(0);

        //    Character tableName= json.getAsJsonObject().get("table").getAsCharacter();

            System.out.println(json.toString());
            return currencyData;
        }


}

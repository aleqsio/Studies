package com.aleqsio.asyncQuerying;

import com.aleqsio.data.CurrencyData;

import java.io.IOException;
import java.util.Date;

import static org.junit.jupiter.api.Assertions.assertEquals;


/**
 * Created by Aleksander on 19.12.2017.
 */
class AsyncSingleQueryProxyTest {
    AsyncSingleQueryProxy asyncSingleQueryProxy;
    @org.junit.jupiter.api.BeforeEach
    void setUp() {
        asyncSingleQueryProxy = new AsyncSingleQueryProxy(new IAsyncSingleQueryServant() {
            @Override
            public CurrencyData getDataFromUrl(String url) throws IOException {
                CurrencyData d =new CurrencyData();
                d.data.put(new CurrencyData.CurrencyDateTypeKey(new Date("2016/02/02"),"TEST", CurrencyData.ExchangeType.AVERAGE),0.5);
                return d;
            }
        });
    }


    @org.junit.jupiter.api.Test
    void getAllDataShouldReturnCorrectCurrencyData() {
        asyncSingleQueryProxy.getDataFromUrl("testurl");
        CurrencyData data = asyncSingleQueryProxy.getAllData();
        assertEquals(0.5d,(double)data.data.get(new CurrencyData.CurrencyDateTypeKey(new Date("2016/02/02"),"TEST", CurrencyData.ExchangeType.AVERAGE)));
    }

}
package com.aleqsio.asyncQuerying;

import com.aleqsio.data.CurrencyData;

import java.io.IOException;

/**
 * Created by Aleksander on 19.12.2017.
 */
public interface IAsyncSingleQueryServant {
    CurrencyData getDataFromUrl(String url)  throws IOException;
}

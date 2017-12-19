package com.aleqsio.asyncQuerying;

import com.aleqsio.data.CurrencyData;

import java.io.IOException;
import java.util.concurrent.CompletableFuture;

/**
 * Created by Aleksander on 17.12.2017.
 */
public class AsyncQueryRequest {
    private String url;
    private IAsyncSingleQueryServant iAsyncSingleQueryServant;

    public CompletableFuture<CurrencyData> getFuture() {
        return future;
    }

    private CompletableFuture<CurrencyData> future;

    public AsyncQueryRequest(IAsyncSingleQueryServant iAsyncSingleQueryServant) {
        this.iAsyncSingleQueryServant=iAsyncSingleQueryServant;
        CompletableFuture<CurrencyData> future= CompletableFuture.supplyAsync(() -> {
            try {
                return execute();
            } catch (IOException e) {
                throw new RuntimeException(e.getMessage());
            }
        });
        this.future = future;
    }

    public void setUrl(String url) {
      this.url=url;
    }
    public CurrencyData execute() throws IOException {
        return iAsyncSingleQueryServant.getDataFromUrl(url);
    }


}

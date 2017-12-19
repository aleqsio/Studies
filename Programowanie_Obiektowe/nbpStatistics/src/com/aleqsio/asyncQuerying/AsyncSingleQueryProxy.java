package com.aleqsio.asyncQuerying;


import com.aleqsio.data.CurrencyData;

import java.util.concurrent.CompletableFuture;

/**
 * Created by Aleksander on 17.12.2017.
 */
public class AsyncSingleQueryProxy {
    private AsyncQueriesScheduler asyncQueriesScheduler = AsyncQueriesScheduler.getInstance();
private IAsyncSingleQueryServant iAsyncSingleQueryServant;

    public AsyncSingleQueryProxy(IAsyncSingleQueryServant iAsyncSingleQueryServant) {
        this.iAsyncSingleQueryServant = iAsyncSingleQueryServant;
    }

    public void getDataFromUrl(String url) {
        CompletableFuture<CurrencyData> future = new CompletableFuture<>();
        AsyncQueryRequest asyncQueryRequest = new AsyncQueryRequest(iAsyncSingleQueryServant);
        asyncQueryRequest.setUrl(url);
        asyncQueriesScheduler.enqueue(asyncQueryRequest);
    }
    public CurrencyData getAllData(){
       return asyncQueriesScheduler.dispatch();
    }
}

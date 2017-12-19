package com.aleqsio.asyncQuerying;


import com.aleqsio.data.CurrencyData;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.CompletableFuture;
import java.util.stream.Collectors;

/**
 * Created by Aleksander on 17.12.2017.
 */
public class AsyncQueriesScheduler {
    private static AsyncQueriesScheduler instance = null;

    private AsyncQueriesScheduler() {
    }

    public static AsyncQueriesScheduler getInstance() {
        if (instance == null) {
            instance = new AsyncQueriesScheduler();
        }
        return instance;
    }
    List<AsyncQueryRequest> requests = new ArrayList();

    public void enqueue(AsyncQueryRequest asyncQueryRequest) {
        requests.add(asyncQueryRequest);
    }

    public CurrencyData dispatch() {
        List<CompletableFuture<CurrencyData>> completableFutureList = requests.stream().map(AsyncQueryRequest::<CompletableFuture>getFuture).collect(Collectors.toList());
        return requests.stream().map(k -> k.getFuture()).map(CompletableFuture::join).reduce(
                new CurrencyData(),
                (a, b) -> {
                    a.joinWith(b);
                    return a;
                });
    }
}

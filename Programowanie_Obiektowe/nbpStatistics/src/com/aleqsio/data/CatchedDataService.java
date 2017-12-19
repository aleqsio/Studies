package com.aleqsio.data;

import com.aleqsio.asyncQuerying.AsyncQueriesScheduler;
import com.aleqsio.asyncQuerying.AsyncSingleQueryProxy;
import com.aleqsio.asyncQuerying.IAsyncSingleQueryServant;
import com.aleqsio.data.CurrencyData;
import com.aleqsio.data.IDataService;

import java.text.SimpleDateFormat;
import java.util.*;

/**
 * Created by Aleksander on 16.12.2017.
 */
public class CatchedDataService implements IDataService {
    AsyncSingleQueryProxy asyncSingleQueryProxy;
    List<String> currencies = new ArrayList<>();
    CurrencyData catchedData = new CurrencyData();

    public CatchedDataService(IAsyncSingleQueryServant iAsyncSingleQueryServant) {
        asyncSingleQueryProxy = new AsyncSingleQueryProxy(iAsyncSingleQueryServant);
    }

    @Override
    public void requestValueOfCurrency(CurrencyData.CurrencyDateTypeKey currencyDateTypeKey) {
asyncSingleQueryProxy.getDataFromUrl("http://api.nbp.pl/api/exchangerates/rates/a/"+currencyDateTypeKey.currencyCode.toLowerCase()+"/"+new SimpleDateFormat("yyyy-mm-dd").format(currencyDateTypeKey.date)+"/?format=json");
    }

    @Override
    public void requestValueOfGold(CurrencyData.CurrencyDateTypeKey currencyDateTypeKey) {

    }

    @Override
    public void requestTimeRangeOfCurrency(Date startDate, Date endDate, CurrencyData.ExchangeType exchangeType, String currencyCode) {

    }

    @Override
    public void requestTimeRangeOfAllCurrencies(Date startDate, Date endDate, CurrencyData.ExchangeType exchangeType) {

    }

    @Override
    public void requestTimeRangeOfGold(Date startDate, Date endDate, CurrencyData.ExchangeType exchangeType) {

    }

    @Override
    public CurrencyData get() throws DataMissingException {

        return catchedData.joinWith(asyncSingleQueryProxy.getAllData());
    }
}

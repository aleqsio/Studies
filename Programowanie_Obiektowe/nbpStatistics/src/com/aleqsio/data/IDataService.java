package com.aleqsio.data;

import com.aleqsio.data.CurrencyData;
import javafx.util.Pair;

import java.util.Date;
import java.util.Map;

/**
 * Created by Aleksander on 17.12.2017.
 */
public interface IDataService {

    void requestValueOfCurrency(CurrencyData.CurrencyDateTypeKey currencyDateTypeKey);
    void requestValueOfGold(CurrencyData.CurrencyDateTypeKey currencyDateTypeKey);
    void requestTimeRangeOfCurrency(Date startDate, Date endDate, CurrencyData.ExchangeType exchangeType, String currencyCode);
    void requestTimeRangeOfAllCurrencies(Date startDate, Date endDate,CurrencyData.ExchangeType exchangeType);
    void requestTimeRangeOfGold(Date startDate, Date endDate, CurrencyData.ExchangeType exchangeType);
    /**
     * @return A CurrencyData guaranteed to contain at least all the values requested beforehand. Will hang the thread until values arrive.
     */
   CurrencyData get() throws DataMissingException;
}

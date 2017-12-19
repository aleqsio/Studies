package com.aleqsio.data;

import javafx.util.Pair;

import java.util.Date;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

/**
 * A class used for storing values of different currency trades on different dates
 */
public class CurrencyData{

    public CurrencyData joinWith(CurrencyData b) {
        b.data.keySet().stream().forEach(k-> data.putIfAbsent(k,b.data.get(k)));
        return this;
    }
    public enum ExchangeType {
        AVERAGE,SELL,BUY
    }
    public static class CurrencyDateTypeKey {
        public Date date;
        public String currencyCode; //One of 3 letter currency codes, or 'GOLD'
        public ExchangeType exchangeType;

        public CurrencyDateTypeKey(Date date, String currencyCode, ExchangeType exchangeType) {
            this.date = date;
            this.currencyCode = currencyCode;
            this.exchangeType = exchangeType;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            CurrencyDateTypeKey that = (CurrencyDateTypeKey) o;

            if (date != null ? !date.equals(that.date) : that.date != null) return false;
            if (currencyCode != null ? !currencyCode.equals(that.currencyCode) : that.currencyCode != null)
                return false;
            return exchangeType == that.exchangeType;
        }

        @Override
        public int hashCode() {
            int result = date != null ? date.hashCode() : 0;
            result = 31 * result + (currencyCode != null ? currencyCode.hashCode() : 0);
            result = 31 * result + (exchangeType != null ? exchangeType.hashCode() : 0);
            return result;
        }
    }
    public HashMap<CurrencyDateTypeKey,Double> data = new HashMap<>();
}

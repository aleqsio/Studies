package com.JBibtexParser.reader;

import com.JBibtexParser.util.exceptions.BlockProviderException;

/**
 * Created by Aleksander on 25.11.2017.
 */
public interface IBlocksProvider {
    void openProvider() throws BlockProviderException;
    String nextEntry() throws BlockProviderException;
    boolean hasNextEntry() throws BlockProviderException;
    void closeProvider();
}

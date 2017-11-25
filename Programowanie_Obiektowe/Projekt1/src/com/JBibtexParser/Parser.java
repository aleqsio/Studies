package com.JBibtexParser;

import com.JBibtexParser.bibliography.KeywordBibliographyManager;
import com.JBibtexParser.bibliography.IBibliographyManager;
import com.JBibtexParser.entry.EntriesParser;
import com.JBibtexParser.readers.FileReader;
import com.JBibtexParser.readers.IBlocksProvider;
import com.JBibtexParser.util.ParseErrorException;

import java.io.IOException;

public class Parser {

    private IBlocksProvider blocksProvider;
    private IBibliographyManager bibliographyManager;

    public Parser(String filepath) {
        blocksProvider = FileReader.getInstance();
        FileReader.getInstance().setFilepath(filepath);
        bibliographyManager = (IBibliographyManager) new KeywordBibliographyManager();
    }

    public Parser(IBlocksProvider blocksProvider) {
        this.blocksProvider = blocksProvider;
        bibliographyManager = (IBibliographyManager) new KeywordBibliographyManager();
    }

    public Parser(IBibliographyManager bibliographyManager) {
        blocksProvider = FileReader.getInstance();
        this.bibliographyManager = bibliographyManager;
    }

    public Parser(IBlocksProvider blocksProvider, IBibliographyManager bibliographyManager) {
        this.blocksProvider = blocksProvider;
        this.bibliographyManager = bibliographyManager;
    }

    public IBibliographyManager getBibliograpyManager() {
        return bibliographyManager;
    }

    public IBibliographyManager parse() throws ParseErrorException {
        EntriesParser parser = new EntriesParser(bibliographyManager);
        blocksProvider.openProvider();
        while (blocksProvider.hasNextEntry()) {
            parser.parseBlock(blocksProvider.nextEntry());
        }
        blocksProvider.closeProvider();
        return bibliographyManager;
    }

}
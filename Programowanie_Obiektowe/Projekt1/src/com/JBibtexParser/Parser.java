package com.JBibtexParser;

import com.JBibtexParser.bibliography.KeywordBibliographyManager;
import com.JBibtexParser.bibliography.IBibliographyManager;
import com.JBibtexParser.entry.EntriesParser;
import types.StaticTypes;
import types.IEntryTypes;
import com.JBibtexParser.readers.FileReader;
import com.JBibtexParser.readers.IBlocksProvider;
import com.JBibtexParser.util.ParseErrorException;
import types.Verification;
import types.definition.BibtexDefinition;
import types.definition.IDefinition;

public class Parser {

    private IBlocksProvider blocksProvider;
    private IBibliographyManager bibliographyManager;
    private IEntryTypes publicationEntryTypes;
    private IDefinition verificationDefinition;

    public Verification getVerificationType() {
        return verificationType;
    }

    public void setVerificationType(Verification verificationType) {
        this.verificationType = verificationType;
    }

    private Verification verificationType;
    public Parser(String filepath) {
        blocksProvider = FileReader.getInstance();
        FileReader.getInstance().setFilepath(filepath);
        bibliographyManager =  new KeywordBibliographyManager();
    }

    public Parser(IBlocksProvider blocksProvider) {
        this.blocksProvider = blocksProvider;
        bibliographyManager = new KeywordBibliographyManager();
    }

    public Parser(IBibliographyManager bibliographyManager) {
        blocksProvider = FileReader.getInstance();
        this.bibliographyManager = bibliographyManager;
    }

    public Parser(IBlocksProvider blocksProvider, IBibliographyManager bibliographyManager) {
        this.blocksProvider = blocksProvider;
        this.bibliographyManager = bibliographyManager;
    }
    public void setPublicationEntryTypes(IEntryTypes publicationEntryTypes){
        this.publicationEntryTypes = publicationEntryTypes;
    }
    public IBibliographyManager getBibliograpyManager() {
        return bibliographyManager;
    }

    public IBibliographyManager parse() throws ParseErrorException {
        if(publicationEntryTypes==null) publicationEntryTypes=new StaticTypes(new BibtexDefinition());
        if(verificationType==null) verificationType = Verification.VERIFY_ONLY_REQUIRED;
        if(verificationDefinition==null) verificationDefinition = new BibtexDefinition();
        EntriesParser parser = new EntriesParser(bibliographyManager,publicationEntryTypes,verificationType,verificationDefinition);
        blocksProvider.openProvider();
        while (blocksProvider.hasNextEntry()) {
            parser.parseBlock(blocksProvider.nextEntry());
        }
        blocksProvider.closeProvider();
        return bibliographyManager;
    }

    public void setVerificationDefinition(IDefinition verificationDefinition) {
        this.verificationDefinition = verificationDefinition;
    }
}
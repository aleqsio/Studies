package com.JBibtexParser.entry;

import com.JBibtexParser.bibliography.IBibliographyManager;
import com.JBibtexParser.bibliography.KeywordBibliographyManager;
import com.JBibtexParser.entry.entries.CommentEntry;
import com.JBibtexParser.entry.entries.StringEntry;
import com.JBibtexParser.util.ParseErrorException;

import java.util.ArrayList;
import java.util.List;

public class EntriesParser {

	private List<StringEntry> stringEntries=new ArrayList<>();
	private List<CommentEntry> commmentEntries=new ArrayList<>();
	private IBibliographyManager bibliographyManager;
private EntryFactory entryFactory;
	/**
	 * 
	 * @param BibliographyManager
	 */
	public EntriesParser(int BibliographyManager) {
		// TODO - implement com.JBibtexParser.entry.EntriesParser.com.JBibtexParser.entry.EntriesParser
		throw new UnsupportedOperationException();
	}

	public EntriesParser(IBibliographyManager bibliograpyManager) {
		this.bibliographyManager=bibliograpyManager;
		entryFactory=new EntryFactory(stringEntries,commmentEntries);
	}

	public void parseBlock(String textblock) throws ParseErrorException {
			IEntry newEntry = entryFactory.getEntry(textblock);
			if(newEntry instanceof StringEntry){
				stringEntries.add((StringEntry) newEntry);
			}
	}

}
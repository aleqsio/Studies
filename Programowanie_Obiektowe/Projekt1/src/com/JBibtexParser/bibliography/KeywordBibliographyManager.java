package com.JBibtexParser.bibliography;

import com.JBibtexParser.entry.entries.PublicationEntry;
import java.util.Map;

public class KeywordBibliographyManager implements IBibliographyManager{

	private Map<String, PublicationEntry> keywords;
	private Bibliography mainBibliography;

	/**
	 * 
	 * @param PublicationEntry
	 */
	public void add(int PublicationEntry) {

	}

	public Bibliography filterByField() {
		// TODO - implement com.JBibtexParser.bibliography.KeywordBibliographyManager.filterByAuthor
		throw new UnsupportedOperationException();
	}

	public Bibliography filterByType() {
		return new Bibliography();
	}

	/**
	 * 
	 * @param PublicationEntry
	 */
	private void addKeywords(int PublicationEntry) {
		// TODO - implement com.JBibtexParser.bibliography.KeywordBibliographyManager.addKeywords
		throw new UnsupportedOperationException();
	}

}
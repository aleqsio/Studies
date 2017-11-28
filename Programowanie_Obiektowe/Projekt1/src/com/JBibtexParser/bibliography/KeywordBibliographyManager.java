package com.JBibtexParser.bibliography;

import com.JBibtexParser.entry.IEntry;
import com.JBibtexParser.entry.entries.PublicationEntry;
import java.util.Map;

public class KeywordBibliographyManager implements IBibliographyManager{

	private Map<String, PublicationEntry> keywords;
	private Bibliography mainBibliography = new Bibliography();


	@Override
	public void add(PublicationEntry publicationEntry) {
		mainBibliography.add(publicationEntry);
		addKeywords(publicationEntry);
	}

	public Bibliography filterByField() {
		// TODO - implement com.JBibtexParser.bibliography.KeywordBibliographyManager.filterByAuthor
		throw new UnsupportedOperationException();
	}

	public Bibliography filterByType() {
		return new Bibliography();
	}

	@Override
	public Bibliography getBibliography() {
		return mainBibliography;
	}

	private void addKeywords(PublicationEntry PublicationEntry) {
		// TODO - implement com.JBibtexParser.bibliography.KeywordBibliographyManager.addKeywords

	}

}
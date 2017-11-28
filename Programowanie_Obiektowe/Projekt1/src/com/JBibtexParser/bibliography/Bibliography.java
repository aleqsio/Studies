package com.JBibtexParser.bibliography;

import com.JBibtexParser.entry.entries.PublicationEntry;

import java.util.LinkedList;
import java.util.List;

public class Bibliography {

	public Bibliography(List<PublicationEntry> entries) {
		this.entries = entries;
	}

	public Bibliography() {
	}

	public List<PublicationEntry> getEntries() {
		return entries;
	}

	public void setEntries(List<PublicationEntry> entries) {
		this.entries = entries;
	}

	private List<PublicationEntry> entries =new LinkedList<>();
	public void add(PublicationEntry e){
		entries.add(e);
	}
	public void print() {
		// TODO - implement com.JBibtexParser.bibliography.Bibliography.print
		throw new UnsupportedOperationException();
	}

}
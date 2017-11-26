package com.JBibtexParser.entry.entries;

import com.JBibtexParser.entry.IEntry;
import types.IEntryField;
import types.IEntryType;

import java.util.Map;

public class PublicationEntry implements IEntry {

	private IEntryType entryType;

	public String getEntryName() {
		return entryName;
	}

	public void setEntryName(String entryName) {
		this.entryName = entryName;
	}

	private String entryName;
	private Map<IEntryField, String> fields;

	public PublicationEntry(IEntryType entryType) {
		this.entryType=entryType;
	}

	public boolean verifyCorrect() {
		// TODO - implement com.JBibtexParser.entry.entries.PublicationEntry.verifyCorrect
		throw new UnsupportedOperationException();
	}

	public void print() {
		// TODO - implement com.JBibtexParser.entry.entries.PublicationEntry.print
		throw new UnsupportedOperationException();
	}

	public Map<IEntryField, String> getFields() {
		return fields;
	}

	public void setFields(Map<IEntryField, String> fields) {
		this.fields = fields;
	}

	public IEntryType getEntryType() {
		return entryType;
	}

	public void setEntryType(IEntryType entryType) {
		this.entryType = entryType;
	}
}
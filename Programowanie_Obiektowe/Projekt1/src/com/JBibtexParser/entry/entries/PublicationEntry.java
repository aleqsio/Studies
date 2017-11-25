package com.JBibtexParser.entry.entries;

import com.JBibtexParser.entry.defaultTypes.EntryFieldEnum;
import com.JBibtexParser.entry.defaultTypes.EntryTypeEnum;
import com.JBibtexParser.entry.IEntry;

import java.util.Map;

public class PublicationEntry implements IEntry {

	private EntryTypeEnum entryType;
	private Map<EntryFieldEnum, String> fields;

	public PublicationEntry(EntryTypeEnum entryTypeEnum) {
		this.entryType=entryTypeEnum;
	}

	public boolean verifyCorrect() {
		// TODO - implement com.JBibtexParser.entry.entries.PublicationEntry.verifyCorrect
		throw new UnsupportedOperationException();
	}

	public void print() {
		// TODO - implement com.JBibtexParser.entry.entries.PublicationEntry.print
		throw new UnsupportedOperationException();
	}

	public Map<EntryFieldEnum, String> getFields() {
		return fields;
	}

	public void setFields(Map<EntryFieldEnum, String> fields) {
		this.fields = fields;
	}
}
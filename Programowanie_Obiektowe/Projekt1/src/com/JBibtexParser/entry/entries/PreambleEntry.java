package com.JBibtexParser.entry.entries;

import com.JBibtexParser.entry.IEntry;

public class PreambleEntry implements IEntry {

	private String preambleText;

	public String getPreambleText() {
		return preambleText;
	}

	public void setPreambleText(String preambleText) {
		this.preambleText = preambleText;
	}
}
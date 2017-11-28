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

	@Override
	public String toString() {
		return "preamble: " +preambleText.substring(0,Math.min(preambleText.length(),20)) + (preambleText.length()>20?" ...":"") ;
	}

	@Override
	public String getName() {
		return toString();
	}
}
package com.JBibtexParser.bibliography;

import com.JBibtexParser.entry.entries.PublicationEntry;

import java.util.LinkedList;
import java.util.List;
import java.util.stream.Collectors;

public class Bibliography {

	private List<PublicationEntry> entries =new LinkedList<>();

	public Bibliography(List<PublicationEntry> entries) {
		this.entries = entries;
	}

	public Bibliography() {
	}

	public List<PublicationEntry> getEntries() {
		return entries;
	}

	public int size(){
		return  entries.size();
	}
	public void setEntries(List<PublicationEntry> entries) {
		this.entries = entries;
	}

	public void add(PublicationEntry e){
		entries.add(e);
	}
	public String toString() {
		return entries.stream().map(e->e.toString()).collect(Collectors.joining("\n"));
	}

}
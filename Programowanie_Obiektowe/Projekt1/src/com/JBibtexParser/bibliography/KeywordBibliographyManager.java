package com.JBibtexParser.bibliography;

import com.JBibtexParser.entry.entries.PublicationEntry;
import com.JBibtexParser.typemanager.IEntryTypesManager;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.regex.Pattern;

public class KeywordBibliographyManager implements IBibliographyManager{

	private Map<String, List<PublicationEntry>> keywords=new HashMap<>();
	private Bibliography bibliography = new Bibliography();

	private KeywordBibliographyManager(Map<String,List<PublicationEntry>> keywords,Bibliography bibliography)
	{
		this.keywords=keywords;
		this.bibliography = bibliography;
	}
	public KeywordBibliographyManager(){

	}
	@Override
	public void add(PublicationEntry publicationEntry) {
		bibliography.add(publicationEntry);
		addKeywords(publicationEntry);
	}

	public KeywordBibliographyManager findFieldsOfValue(IEntryTypesManager.IEntryField field, String regex) {
		Pattern pattern = Pattern.compile(regex.toLowerCase());
		Bibliography b=new Bibliography();
		bibliography.getEntries().stream().filter(p->p.getFields().containsKey(field)).filter(p->p.getFields().get(field).stream().anyMatch(r->pattern.matcher(r.toLowerCase()).find())).forEach(b::add);
		return new KeywordBibliographyManager(keywords,b);
	}


	public KeywordBibliographyManager findEntriesContainingWords(String query){
		Bibliography b=new Bibliography();
		if(!keywords.containsKey(query)) return new KeywordBibliographyManager(keywords,b);
		for(PublicationEntry entry:keywords.get(query)){
			if(bibliography.getEntries().contains(entry))
			b.add(entry);
		}
		return new KeywordBibliographyManager(keywords,b);
	}

	public KeywordBibliographyManager filterByType(IEntryTypesManager.IEntryType type) {
		Bibliography b=new Bibliography();
		bibliography.getEntries().stream().filter(p->p.getEntryType().equals(type)).forEach(p->b.add(p));
		return new KeywordBibliographyManager(keywords,b);
	}

	@Override
	public Bibliography getBibliography() {
		return bibliography;
	}

	private void addKeywords(PublicationEntry publicationEntry) {
		if(publicationEntry.getFields().size()==0);
		for(List<String> field:publicationEntry.getFields().values()){
			for(String subField:field){
				for(String word:subField.split(" ")){
					if(keywords.containsKey(word)){
						keywords.get(word).add(publicationEntry);
					}else {
						List<PublicationEntry> list = new ArrayList<>();
						list.add(publicationEntry);
						keywords.put(word,list);
					}

				}
			}
		}

	}

}
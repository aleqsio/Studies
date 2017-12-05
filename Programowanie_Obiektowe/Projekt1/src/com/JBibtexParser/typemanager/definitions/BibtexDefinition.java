package com.JBibtexParser.typemanager.definitions;

import com.JBibtexParser.typemanager.*;
import com.JBibtexParser.typemanager.IEntryTypesManager.IEntryField;
import com.JBibtexParser.typemanager.IEntryTypesManager.IEntryType;

import java.util.*;

/**
 * Created by Aleksander on 25.11.2017.
 */
public class BibtexDefinition implements IDefinition{
    private Map<IEntryType, Map<IEntryField, FieldProperties>> definition = new HashMap<>();

    public Set<EntryType> getTypes() {
        return types;
    }

    private Set<EntryType> types = new HashSet<>();
    private Set<EntryField> fields = new HashSet<>();
    public BibtexDefinition(){

        FieldProperties r = FieldProperties.REQUIRED;
        FieldProperties o = FieldProperties.OPTIONAL;

        IEntryType article = new EntryType("article");
        IEntryType book = new EntryType("book");
        IEntryType booklet = new EntryType("booklet");
        IEntryType conference = new EntryType("conference");
        IEntryType inbook = new EntryType("inbook");
        IEntryType incollection = new EntryType("incollection");
        IEntryType inproceedings = new EntryType("inproceedings");
        IEntryType manual = new EntryType("manual");
        IEntryType mastersthesis = new EntryType("mastersthesis");
        IEntryType misc = new EntryType("misc");
        IEntryType phdthesis = new EntryType("phdthesis");
        IEntryType proceedings = new EntryType("proceedings");
        IEntryType techreport = new EntryType("techreport");
        IEntryType unpublished = new EntryType("unpublished");

        IEntryField address = new EntryField("address");
        IEntryField annote = new EntryField("annote");
        IEntryField author = new EntryField("author");
        IEntryField booktitle = new EntryField("booktitle");
        IEntryField chapter = new EntryField("chapter");
        IEntryField crossref = new EntryField("crossref");
        IEntryField edition = new EntryField("edition");
        IEntryField editor = new EntryField("editor");
        IEntryField howpublished = new EntryField("howpublished");
        IEntryField institution = new EntryField("institution");
        IEntryField journal = new EntryField("journal");
        IEntryField key = new EntryField("key");
        IEntryField month = new EntryField("month");
        IEntryField note = new EntryField("note");
        IEntryField number = new EntryField("number");
        IEntryField organization = new EntryField("organization");
        IEntryField pages = new EntryField("pages");
        IEntryField publisher = new EntryField("publisher");
        IEntryField school = new EntryField("school");
        IEntryField series = new EntryField("series");
        IEntryField title = new EntryField("title");
        IEntryField type = new EntryField("type");
        IEntryField volume = new EntryField("volume");
        IEntryField year = new EntryField("year");
        fields=buildSet(address,annote,author,booktitle,chapter,crossref,edition,editor,howpublished,institution,journal,key,month,note,number,organization,pages,publisher,school,series,title,type,volume,year);
        types = buildSet(article,book,booklet,conference,inbook,incollection,inproceedings,manual,mastersthesis,misc,phdthesis,proceedings,techreport,unpublished);
        //for verification
        definition.put(article,buildMap(author,r,title,r,journal,r,year,r,volume,o,number,o,pages,o,month,o,note,o));
        definition.put(book,buildMap(author,r,title,r,publisher,r,year,r,volume,o,series,o,address,o,edition,o,month,o,note,o));
        definition.put(booklet,buildMap(title,r,author,o,howpublished,o,address,o,month,o,year,o,note,o));
        definition.put(inbook,buildMap(author,r,title,r,chapter,r,publisher,r,year,r,volume,o,series,o,type,o,address,o,edition,o,month,o,note,o));
        definition.put(incollection,buildMap(author,r,title,r,booktitle,r,publisher,r,year,r,volume,o,number,o,series,o,type,o,chapter,o,pages,o,address,o,edition,o,month,o,note,o));
        definition.put(manual,buildMap(title,r,author,o,organization,o,address,o,edition,o,month,o,year,o,note,o));
        definition.put(mastersthesis,buildMap(author,r,title,r,school,r,year,r,type,o,address,o,edition,o,month,o,year,o,note,o));
        /* TODO: uzupełnić brakujące definicje
    Technical documentation. Required field: title. Optional fields: author, organization, address, edition, month, year, note.
mastersthesis
    A Master's thesis. Required fields: author, title, school, year. Optional fields: type, address, month, note.
misc
    Use this type when nothing else fits. Required fields: none. Optional fields: author, title, howpublished, month, year, note.
phdthesis
    A PhD thesis. Required fields: author, title, school, year. Optional fields: type, address, month, note.
proceedings
    The proceedings of a conference. Required fields: title, year. Optional fields: editor, volume or number, series, address, month, organization, publisher, note.
techreport
    A report published by a school or other institution, usually numbered within a series. Required fields: author, title, institution, year. Optional fields: type, number, address, month, note.
unpublished

    A document having an author and title, but not formally published. Required fields: author, title, note. Optional fields: month, year.
 */
    }

    @Override
    public Map<IEntryType, Map<IEntryField, FieldProperties>> getDefinition() {
        return definition;
    }


    public Set<EntryField> getFields() {
        return fields;
    }
}

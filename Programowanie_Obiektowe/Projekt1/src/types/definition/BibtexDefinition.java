package types.definition;

import types.*;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by Aleksander on 25.11.2017.
 */
public class BibtexDefinition implements IDefinition{
    private Map<IEntryType, Map<IEntryField, FieldProperties>> definition = new HashMap<>();

    public Map<String, EntryType> getTypes() {
        return types;
    }

    private Map<String,EntryType> types = new HashMap<>();
    private Map<String,EntryField> fields = new HashMap<>();
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
        fields=build("address",address,"annote",annote,"author",author,"booktitle",booktitle,"chapter",chapter,"crossref",crossref,"edition",edition,"editor",editor,"howpublished",howpublished,"institution",institution,"journal",journal,"key",key,"month",month,"note",note,"number",number,"organization",organization,"pages",pages,"publisher",publisher,"school",school,"series",series,"title",title,"type",type,"volume",volume,"year",year);
        types = build("article",article,"book",book,"booklet",booklet,"conference",conference,"inbook",inbook,"incollection",incollection,"inproceedings",inproceedings,"manual",manual,"mastersthesis",mastersthesis,"misc",misc,"phdthesis",phdthesis,"proceedings",proceedings,"techreport",techreport,"unpublished",unpublished);
        definition.put(article,build(author,r,title,r,journal,r,year,r,volume,o,number,o,pages,o,month,o,note,o));

    }

    @Override
    public Map<IEntryType, Map<IEntryField, FieldProperties>> getDefinition() {
        return definition;
    }


    private static <T1,T2> HashMap<T1, T2> build(Object... data){
        HashMap<T1, T2> result = new HashMap<>();

        if(data.length % 2 != 0)
            throw new IllegalArgumentException("Odd number of arguments");

        T1 key = null;
        Integer step = -1;

        for(Object value : data){
            step++;
            switch(step % 2){
                case 0:
                    key = (T1) value;
                    continue;
                case 1:
                    result.put(key, (T2) value);
                    break;
            }
        }

        return result;
    }

    public Map<String, EntryField> getFields() {
        return fields;
    }
}

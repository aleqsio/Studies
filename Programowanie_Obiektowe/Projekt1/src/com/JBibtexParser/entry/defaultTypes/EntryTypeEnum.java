package com.JBibtexParser.entry.defaultTypes;

import java.util.Arrays;
import java.util.List;

public enum EntryTypeEnum {
    ARTICLE(Arrays.asList(EntryFieldEnum.ANNOTE),Arrays.asList(EntryFieldEnum.AUTHOR)),
    BOOK,
    BOOKLET,
    CONFERENCE,
    INBOOK,
    INCOLLECTION,
    INPROCEEDINGS,
    MANUAL,
    MASTERSTHESIS,
    MISC,
    PHDTHESIS,
    PROCEEDINGS,
    TECHREPORT,
    UNPUBLISHED;

    EntryTypeEnum(List<EntryFieldEnum> required,List<EntryFieldEnum> optional) {
    }
}
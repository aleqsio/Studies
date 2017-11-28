package com.JBibtexParser.bibliography;

import com.JBibtexParser.entry.IEntry;
import com.JBibtexParser.entry.entries.PublicationEntry;
import com.JBibtexParser.verification.IVerificationReport;

import java.util.Iterator;

public interface IBibliographyManager{
    void add(PublicationEntry PublicationEntry);
    Bibliography filterByField();
    Bibliography filterByType();
    Bibliography getBibliography();
}

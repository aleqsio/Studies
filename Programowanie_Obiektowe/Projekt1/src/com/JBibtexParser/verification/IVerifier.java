package com.JBibtexParser.verification;

import com.JBibtexParser.bibliography.Bibliography;
import com.JBibtexParser.entry.IEntry;
import com.JBibtexParser.typemanager.definitions.IDefinition;

/**
 * Created by Aleksander on 27.11.2017.
 */
public interface IVerifier {
    void verifyEntry(IEntry entry);
    void verifyBibliography(Bibliography bibliography);
    IVerificationReport getVerificationReport();
    IDefinition getVerificationDefinition();
}

package com.JBibtexParser.verification;

import com.JBibtexParser.entry.IEntry;
import com.JBibtexParser.entry.entries.PublicationEntry;

import java.util.LinkedList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by Aleksander on 27.11.2017.
 */

public class SimpleVerificationReport implements IVerificationReport {
    List<Issue> issues=new LinkedList<>();
    @Override
    public void addIssue(Issue issue) {
        issues.add(issue);
    }

    @Override
    public String toString() {
        return issues.stream().map(p-> p.getDescription()+p.getField().getName()+" in "+(p.getEntry().getName())).collect(Collectors.joining(",\n"));
    }
    @Override
    public boolean isSuccessful() {
        return issues.size()==0;
    }
}

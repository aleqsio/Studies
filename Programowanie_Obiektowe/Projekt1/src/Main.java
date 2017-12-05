import com.JBibtexParser.Parser;
import com.JBibtexParser.bibliography.Bibliography;
import com.JBibtexParser.bibliography.IBibliographyManager;
import com.JBibtexParser.typemanager.IEntryTypesManager;
import com.JBibtexParser.typemanager.definitions.BibtexDefinition;
import com.JBibtexParser.util.exceptions.ParseErrorException;
import com.JBibtexParser.verification.SimpleVerifier;
import com.JBibtexParser.verification.VerificationMode;
import org.apache.commons.cli.*;

import java.util.Arrays;
import java.util.Collections;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] params) {

        CommandLine cmd = parseCmdLine(params);
        String delimiter = cmd.getOptionValue("delimiter");
        //create new parser
        Parser parser = new Parser(cmd.getOptionValue("path"));

        BibtexDefinition bibtexDefinition = new BibtexDefinition();

        IBibliographyManager bibliographyManager;

        try {
            bibliographyManager = parser.parse();
        } catch (ParseErrorException e) {
            System.out.print(e.getMessage());
            return;
        }
        Bibliography mainBibliography = bibliographyManager.getBibliography();
        SimpleVerifier verifier = new SimpleVerifier(bibtexDefinition, VerificationMode.FULL_VERIFY);
        verifier.verifyBibliography(mainBibliography);

        System.out.println(verifier.getVerificationReport().toString());

        if(cmd.hasOption("categories")){
            for (IEntryTypesManager.IEntryType type : Arrays.stream(cmd.getOptionValue("categories").split(",")).map(p->parser.getEntryTypesManager().getType(p.trim())).collect(Collectors.toList())){
                printLine(delimiter);
                System.out.println("All entries of category "+type.getName());
                printLine(delimiter);
                System.out.println(bibliographyManager.filterByType(type).getBibliography().toString());
                printLine(delimiter);
            }
            ;

        }
        if(cmd.hasOption("authors")){
            for (String author : cmd.getOptionValue("authors").split(","))
            {
                author=author.trim();
                String[] authorSubNames=author.split(" ");
                String regex="";
                for(String authorSubName:authorSubNames){
                    regex+="(?=";
                    regex+=".*"+authorSubName+"";
                    regex+=")";
                }
                printLine(delimiter);
                System.out.println("All entries of author "+author);
                printLine(delimiter);
                System.out.println(bibliographyManager.findFieldsOfValue(parser.getEntryTypesManager().getField("author"),regex).getBibliography());
                printLine(delimiter);
            }
            ;

        }
    }
    private static void printLine(String separator){
       System.out.println(String.join("", Collections.nCopies(20, separator)));
    }
   private static CommandLine parseCmdLine(String[] params) {
        Options options = new Options();

        Option input = new Option("p", "path", true, "input file path");
        input.setRequired(true);
        options.addOption(input);

        Option categories = new Option("c", "categories", true, "print entries in following categories");
        categories.setRequired(false);
        options.addOption(categories);

        Option authors = new Option("a", "authors", true, "print entries by following authors");
        authors.setRequired(false);
        options.addOption(authors);

        Option delimiter = new Option("d", "delimiter", true, "separate entries by following delimiter");
        delimiter.setRequired(false);
        options.addOption(delimiter);

        CommandLineParser parser = new DefaultParser();
        HelpFormatter formatter = new HelpFormatter();
        CommandLine cmd;

        try {
            cmd = parser.parse(options, params);
        } catch (ParseException e) {
            System.out.println(e.getMessage());
            formatter.printHelp("JBibtex Parser", options);
            System.exit(1);
            return null;
        }
        return cmd;

    }

}
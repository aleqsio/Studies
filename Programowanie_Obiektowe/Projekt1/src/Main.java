import com.JBibtexParser.Parser;
import com.JBibtexParser.bibliography.Bibliography;
import com.JBibtexParser.bibliography.IBibliographyManager;
import com.JBibtexParser.entry.IEntry;
import com.JBibtexParser.typemanager.DynamicTypesManager;
import com.JBibtexParser.typemanager.definitions.BibtexDefinition;
import com.JBibtexParser.util.exceptions.ParseErrorException;
import com.JBibtexParser.verification.SimpleVerifier;
import com.JBibtexParser.verification.VerificationMode;

public class Main {
public static void main(String[] params)
{
	Parser parser = new Parser("test.txt");

	parser.setEntryTypesManager(new DynamicTypesManager());
	BibtexDefinition bibtexDefinition = new BibtexDefinition();
//	parser.setEntryTypesManager(new StaticTypesManager(bibtexDefinition));

	IBibliographyManager bibliographyManager;
	try {
		bibliographyManager= parser.parse();
	} catch (ParseErrorException e) {
		System.out.print(e.getMessage());
		return;
	}
	Bibliography b= bibliographyManager.getBibliography();
	SimpleVerifier verifier=new SimpleVerifier(bibtexDefinition, VerificationMode.FULL_VERIFY);
	verifier.verifyBibliography(b);
	System.out.println(verifier.getVerificationReport().toString());
	System.out.print("\n\n");
	for(IEntry entry :parser.getAllEntries()){
System.out.println(entry.toString());
	}
}


}
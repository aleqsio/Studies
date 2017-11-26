import com.JBibtexParser.Parser;
import com.JBibtexParser.util.ParseErrorException;
import types.DynamicTypes;
import types.StaticTypes;
import types.Verification;
import types.definition.BibtexDefinition;

import java.io.IOException;

public class Main {
public static void main(String[] params)
{
	Parser parser = new Parser("test.txt");
//	parser.setPublicationEntryTypes(new DynamicTypes());
	BibtexDefinition bibtexDefinition = new BibtexDefinition();
	parser.setPublicationEntryTypes(new StaticTypes(bibtexDefinition));
	parser.setVerificationType(Verification.FULL_VERIFY);
	parser.setVerificationDefinition(bibtexDefinition);
	try {

		parser.parse();
	} catch (ParseErrorException e) {
		System.out.print(e.getMessage());
	}
}




}
import com.JBibtexParser.Parser;
import com.JBibtexParser.util.ParseErrorException;

import java.io.IOException;

public class Main {
public static void main(String[] params)
{
	Parser parser = new Parser("file.txt");
	try {
		parser.parse();
	} catch (ParseErrorException e) {
		System.out.print(e.getMessage());
	}
}




}
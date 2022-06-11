package DCaronQA;

import java.io.FileNotFoundException;
import java.io.IOException;

public class App {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        if (args.length != 1) {
            System.out.println("Please provide the path for a grammar file.");
            return;
        }

        final String filePath = args[0];

        Grammar grammar = new Grammar();
        grammar.readGrammarFromFile(filePath, true);
        System.out.println(grammar.toString());

        ParserGenerator parserGenerator = new ParserGenerator(grammar);
        parserGenerator.generateTable("test.csv");
    }
}

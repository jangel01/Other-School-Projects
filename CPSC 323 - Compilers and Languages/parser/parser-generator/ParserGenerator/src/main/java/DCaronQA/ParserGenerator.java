package DCaronQA;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

public class ParserGenerator {

    private final Grammar grammar;

    // We assume the grammar is already augmented.
    public ParserGenerator(final Grammar grammar) {
        this.grammar = grammar;
    }

    public void generateTable(final String fileName) throws IOException {

        List<State> transitions = this.buildTransitionSets();
        List<String> tableHeader = generateTableHeader();
        Map<String, Integer> symbolToColumn = new HashMap<String, Integer>();

        for (int i = 0; i < tableHeader.size(); i++) {
            symbolToColumn.put(tableHeader.get(i), i + 1);
        }

        final int rows = transitions.size() + 1;
        final int columns = tableHeader.size() + 1;
        String[][] table = new String[rows][columns];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                table[i][j] = "";
            }
        }

        transitions.stream()
                .filter((state) -> state.getFromLabel() != -1)
                .forEach((state) -> {
                    table[state.getFromLabel() + 1][symbolToColumn.get(state.getDerivedSymbol())] = getShiftOrNot(
                            state.getDerivedSymbol(), state.getLabel());
                    state.getItemSet()
                            .getAllCompletedItems()
                            .stream()
                            .forEach((item) -> {
                                final int reductionNumber = item.getCore().getNumber();
                                for (final String las : item.getLAS()) {
                                    table[state.getLabel() + 1][symbolToColumn.get(las)] = getReductionString(
                                            reductionNumber);
                                }
                            });
                });

        StringBuilder sb = new StringBuilder();

        sb.append(',');
        for (int i = 0; i < tableHeader.size(); i++) {
            final String symbol = tableHeader.get(i);

            sb.append(symbol).append(',');
        }
        sb.setCharAt(sb.length() - 1, '\n');

        for (int i = 1; i < rows; i++) {
            sb.append(i - 1).append(',');
            for (int j = 1; j < columns; j++) {
                sb.append(table[i][j]).append(',');
            }
            sb.setCharAt(sb.length() - 1, '\n');
        }

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
            writer.write(sb.toString());
        }

    }

    private String getReductionString(final int reductionNumber) {
        if (reductionNumber == 0) {
            return "ACCT";
        }
        return "R" + reductionNumber;
    }

    private String getShiftOrNot(final String symbol, final int number) {
        if (grammar.isTerminal(symbol) || symbol == Grammar.END_OF_FILE) {
            return "S" + number;
        }
        return String.valueOf(number);
    }

    private List<String> generateTableHeader() {
        Set<String> distinctSymbols = this.grammar.getDistinctSymbols();
        distinctSymbols.add(Grammar.END_OF_FILE);
        List<String> listOfSymbols = distinctSymbols.stream().collect(Collectors.toList());
        Collections.sort(listOfSymbols, (String arg0, String arg1) -> {
            if (grammar.isTerminal(arg0) && grammar.isTerminal(arg1)) {
                return 0;
            } else if (grammar.isTerminal(arg0)) {
                return -1;
            } else {
                return 1;
            }
        });
        return listOfSymbols;
    }

    private List<State> buildTransitionSets() {

        final Set<String> state0LAS = new HashSet<String>();
        state0LAS.add(Grammar.END_OF_FILE);
        final State state0 = new State(new ItemSet()
                .addItem(this.grammar.getStartingProduction(), state0LAS)
                .closure(this.grammar));

        List<State> states = new ArrayList<State>();
        states.add(state0);
        int i = 0;

        System.out.println("0 = " + state0.getItemSet());

        while (i < states.size()) {
            final State previous = states.get(i);
            states.addAll(this.buildNewStates(previous));
            i++;
        }

        return states;
    }

    private List<State> buildNewStates(final State previous) {
        return previous.getAllMarkedSymbols()
                .stream()
                .map((symbol) -> new State(previous, symbol, this.grammar))
                .collect(Collectors.toList());
    }

}

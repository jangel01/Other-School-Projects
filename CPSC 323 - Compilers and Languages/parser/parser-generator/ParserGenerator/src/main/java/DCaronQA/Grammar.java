package DCaronQA;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

public class Grammar {

    public static final String EPSILON = "epsilon";
    public static final String END_OF_FILE = "$";
    private static final String AUGMENTED_RULE = "S\'";

    private String startingNonterminal;
    private Map<String, ArrayList<Production>> productions;
    private Set<String> terminals;
    private Set<String> distinctSymbols;

    private Map<String, HashSet<String>> firstSets;
    private Map<String, HashSet<String>> followSets;

    private int nextNumber;

    public Grammar() {
        this.startingNonterminal = null;
        this.productions = new HashMap<String, ArrayList<Production>>();
        this.terminals = new HashSet<String>();
        this.distinctSymbols = new HashSet<String>();
        this.firstSets = new HashMap<String, HashSet<String>>();
        this.followSets = new HashMap<String, HashSet<String>>();
        this.nextNumber = 1;
    }

    public void readGrammarFromFile(final String fileName, final boolean augmentGrammar)
            throws FileNotFoundException, IOException {
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while (!(line = br.readLine().trim()).contains("Terminals:")) {
                // Read productions one by one.
                final String[] production = line.split("->");
                final String lhs = production[0].trim();
                final String[] rhs = production[1].trim().split(" ");
                this.addProduction(new Production(nextNumber++, lhs, rhs));

                this.distinctSymbols.add(lhs);
                for (final String symbol : rhs) {
                    this.distinctSymbols.add(symbol);
                }

                if (startingNonterminal == null) {
                    startingNonterminal = lhs;
                }
            }
            // Read the list of terminals.
            this.readTerminals(line);

            if (augmentGrammar) {
                this.doAugmentGrammar();
            }

            this.calculateFirstSets();
            this.calculateFollowSets();
        }
    }

    private void doAugmentGrammar() {
        this.addProduction(new Production(0, AUGMENTED_RULE, new String[] { this.startingNonterminal }));
        this.startingNonterminal = AUGMENTED_RULE;
    }

    private void addProduction(final Production production) {
        this.productions.putIfAbsent(production.getLHS(), new ArrayList<Production>());
        this.productions.get(production.getLHS()).add(production);
    }

    private void readTerminals(final String terminalLine) {
        String[] terminals = terminalLine.split(" ");
        for (int i = 1; i < terminals.length; i++) {
            this.terminals.add(terminals[i]);
        }
    }

    public List<Production> getProductionsWithLHS(final String lhs) {
        return this.productions
                .entrySet()
                .stream()
                .filter((entry) -> entry.getKey().equals(lhs))
                .map(Map.Entry::getValue)
                .flatMap(Collection::stream)
                .collect(Collectors.toList());
    }

    public Set<String> getDistinctSymbols() {
        return this.distinctSymbols;
    }

    public Production getStartingProduction() {
        return this.productions.get(this.startingNonterminal).get(0);
    }

    public HashSet<String> getFirstSet(final String symbol) {
        return this.firstSets.get(symbol);
    }

    public HashSet<String> getFollowSet(final String symbol) {
        return this.followSets.get(symbol);
    }

    private void calculateFirstSets() {
        this.firstSet(Grammar.EPSILON);
        this.firstSets.put(Grammar.END_OF_FILE, this.firstSet(Grammar.END_OF_FILE));
        for (final String symbol : this.distinctSymbols) {
            this.firstSets.put(symbol, this.firstSet(symbol));
        }
    }

    private HashSet<String> firstSet(final String symbol) {
        if (this.firstSets.containsKey(symbol)) {
            return this.firstSets.get(symbol);
        }

        HashSet<String> newFirstSet = new HashSet<String>();

        if (symbol.equals(Grammar.EPSILON)) {
            newFirstSet.add(EPSILON);
            this.firstSets.put(EPSILON, newFirstSet);
            return newFirstSet;
        }

        if (this.isTerminal(symbol)) {
            newFirstSet.add(symbol);
            return newFirstSet;
        }

        this.productions.get(symbol)
                .stream()
                .forEach((production) -> {
                    final String beta = production.getRHS()[0];
                    if (this.isTerminal(beta)) {
                        newFirstSet.add(beta);
                    } else if (!this.isTerminal(beta) && beta != Grammar.EPSILON && beta != symbol) {
                        HashSet<String> firstOfBeta = this.firstSet(beta);
                        firstOfBeta.remove(Grammar.EPSILON);
                        newFirstSet.addAll(firstOfBeta);
                    }
                });

        return newFirstSet;
    }

    private void calculateFollowSets() {
        final HashSet<String> nonterminals = new HashSet<String>(this.distinctSymbols);
        nonterminals.removeAll(this.terminals);
        nonterminals.remove(EPSILON);
        nonterminals.remove(END_OF_FILE);

        this.followSets.put(this.startingNonterminal, this.followSet(this.startingNonterminal));
        for (final String nonterminal : nonterminals) {
            this.followSets.put(nonterminal, this.followSet(nonterminal));
        }
    }

    private HashSet<String> followSet(final String symbol) {
        if (this.followSets.containsKey(symbol)) {
            return this.followSets.get(symbol);
        }

        HashSet<String> newFollowSet = new HashSet<String>();

        if (this.startingNonterminal.equals(symbol)) {
            newFollowSet.add(END_OF_FILE);
            return newFollowSet;
        }

        this.productions
                .entrySet()
                .stream()
                .forEach((productions) -> {
                    productions
                            .getValue()
                            .stream()
                            .forEach((production) -> {
                                final String q = production.getLHS();
                                for (int i = 0; i < production.getRHS().length; i++) {
                                    final String a = production.getRHS()[i];
                                    if (a.equals(symbol)) {
                                        final String beta = this.peekStringArray(production.getRHS(), i + 1);

                                        if (this.isTerminal(beta)) {
                                            newFollowSet.add(beta);
                                        } else if (!this.isTerminal(beta) && beta != EPSILON) {
                                            HashSet<String> firstInclude = this.getFirstSet(beta);
                                            firstInclude.remove(EPSILON);
                                            newFollowSet.addAll(firstInclude);
                                        }
                                        if ((this.getFirstSet(beta).contains(EPSILON) || beta.equals(EPSILON))
                                                && !q.equals(a)) {
                                            newFollowSet.addAll(this.followSet(q));
                                        }
                                    }
                                }
                            });
                });

        return newFollowSet;
    }

    public boolean isTerminal(final String symbol) {
        return this.terminals.contains(symbol) || symbol.equals(END_OF_FILE);
    }

    private String peekStringArray(final String[] array, final int index) {
        if (index < array.length) {
            return array[index];
        }
        return EPSILON;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (final String key : this.productions.keySet()) {
            final List<Production> productions = this.productions.get(key);
            for (final Production production : productions) {
                sb.append(production.toString()).append('\n');
            }
        }
        for (final String key : this.firstSets.keySet()) {
            final HashSet<String> firstSet = this.firstSets.get(key);
            sb.append("FIRST(" + key + ") is " + firstSet).append('\n');
        }
        for (final String key : this.followSets.keySet()) {
            final HashSet<String> followSet = this.followSets.get(key);
            sb.append("FOLLOW(" + key + ") is " + followSet).append('\n');
        }
        return sb.toString().stripTrailing();
    }

}

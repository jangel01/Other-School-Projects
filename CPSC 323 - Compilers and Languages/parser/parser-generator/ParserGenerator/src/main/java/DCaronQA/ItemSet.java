package DCaronQA;

import java.util.HashMap;
import java.util.Map;
import java.util.Optional;
import java.util.Set;
import java.util.stream.Collectors;

public class ItemSet {

    private Map<Production, Item> items;

    public ItemSet() {
        this.items = new HashMap<Production, Item>();
    }

    public ItemSet(final HashMap<Production, Item> items) {
        this.items = new HashMap<Production, Item>(items);
    }

    public ItemSet(final Set<Item> items) {
        this.items = new HashMap<Production, Item>();
        for (final Item item : items) {
            this.items.put(item.getCore(), item);
        }
    }

    public ItemSet(final ItemSet other) {
        this.items = new HashMap<Production, Item>(other.items);
    }

    public Map<Production, Item> getItems() {
        return this.items;
    }

    public ItemSet addItem(final Production production, Set<String> las) {
        final Item newItem = new Item(production, las);
        return this.addItem(newItem);
    }

    public ItemSet addItem(final Production production, String addLAS) {
        final Item newItem = new Item(production, addLAS);
        return this.addItem(newItem);
    }

    public ItemSet addItem(final Item item) {
        if (this.items.containsKey(item.getCore())) {
            this.items.get(item.getCore()).getLAS().addAll(item.getLAS());
        } else {
            this.items.put(item.getCore(), item);
        }
        return this;
    }

    public ItemSet closure(final Grammar grammar) {
        ItemSet newItemSet = new ItemSet(this);
        final int beforeClosureSize = newItemSet.getItems().size();

        for (final Item item : this.getItems().values().stream().filter((item) -> !item.isCompleteItem()).toList()) {

            final String beta = item.getSymbolAheadOfMarked();

            for (final Production production : grammar.getProductionsWithLHS(item.getMarkedSymbol().get())) {

                if (beta.equals("") || beta.equals(Grammar.EPSILON)) {
                    for (final String token : item.getLAS()) {

                        final Set<String> firstSet = grammar.getFirstSet(token);
                        for (final String b : firstSet) {
                            newItemSet.addItem(production, b);
                        }

                    }
                } else {
                    final Set<String> firstSet = grammar.getFirstSet(beta);
                    for (final String b : firstSet) {
                        newItemSet.addItem(production, b);
                    }
                }

            }
        }

        if (newItemSet.getItems().size() != beforeClosureSize)
            newItemSet = newItemSet.closure(grammar);

        return newItemSet;
    }

    public Set<String> getAllMarkedSymbols() {
        return this.items
                .values()
                .stream()
                .map((item) -> item.getMarkedSymbol())
                .flatMap(Optional::stream)
                .collect(Collectors.toSet());
    }

    public Set<Item> getAllCompletedItems() {
        return this.items
                .values()
                .stream()
                .filter((item) -> item.isCompleteItem())
                .collect(Collectors.toSet());
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("{ ");
        this.items.values().stream().forEach((item) -> sb.append(item.toString()).append(" "));
        sb.append("}");
        return sb.toString();
    }

}

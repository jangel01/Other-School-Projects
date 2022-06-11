package DCaronQA;

import java.util.Set;
import java.util.stream.Collectors;

public class State {

    private static int stateCounter = 0;

    private final int stateLabel;
    private final int fromState;
    private final String derivedSymbol;

    private final ItemSet itemset;

    public State(final ItemSet itemset) {
        this.stateLabel = stateCounter++;
        this.itemset = itemset;
        this.fromState = -1;
        this.derivedSymbol = null;
    }

    public State(final State fromState, final String derivedSymbol, final Grammar grammar) {
        this.stateLabel = stateCounter++;
        this.fromState = fromState.getLabel();
        this.derivedSymbol = derivedSymbol;
        this.itemset = transitionSet(fromState.getItemSet(), this.derivedSymbol, grammar);
    }

    public int getLabel() {
        return this.stateLabel;
    }

    public int getFromLabel() {
        return this.fromState;
    }

    public String getDerivedSymbol() {
        return this.derivedSymbol;
    }

    public ItemSet getItemSet() {
        return this.itemset;
    }

    public Set<String> getAllMarkedSymbols() {
        return this.itemset.getAllMarkedSymbols();
    }

    private ItemSet transitionSet(final ItemSet i, final String x, final Grammar grammar) {
        final ItemSet result = new ItemSet(i.getItems()
                .values()
                .stream()
                .filter((item) -> !item.isCompleteItem() && item.getMarkedSymbol().get().equals(x))
                .map((item) -> item.nextItem())
                .collect(Collectors.toSet()))
                .closure(grammar);
        System.out.println(this.stateLabel + " = N(" + this.fromState + ", " + x + ") = " + result);
        return result;
    }

}

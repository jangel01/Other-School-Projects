package DCaronQA;

import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

public class Item {

    public static final String COMPLETE_ITEM = "COMPLETED_ITEM";

    private final Production core;
    private final int marker;
    private final Set<String> las;

    public Item(Production production, Set<String> las) {
        this.core = production;
        this.marker = 0;
        this.las = las;
    }

    public Item(Production production, String las) {
        this.core = production;
        this.marker = 0;
        this.las = new HashSet<String>();
        this.las.add(las);
    }

    private Item(Production production, int marker, Set<String> las) {
        this.core = production;
        this.marker = marker;
        this.las = las;
    }

    public Production getCore() {
        return this.core;
    }

    public Set<String> getLAS() {
        return this.las;
    }

    public Optional<String> getMarkedSymbol() {
        if (this.marker < this.core.getRHS().length) {
            return Optional.of(this.core.getRHS()[this.marker]);
        }
        return Optional.empty();
    }

    public String getSymbolAheadOfMarked() {
        if (this.marker + 1 < this.getCore().getRHS().length) {
            return this.getCore().getRHS()[this.marker + 1];
        }
        return "";
    }

    public boolean isCompleteItem() {
        return this.marker == this.core.getRHS().length;
    }

    public Item nextItem() {
        return new Item(this.getCore(), Math.min(this.marker + 1, this.getCore().getRHS().length),
                new HashSet<String>(this.getLAS()));
    }

    @Override
    public boolean equals(Object o) {
        if (o instanceof Item) {
            final Item other = (Item) o;
            return this.getCore().equals(other.getCore()) && this.marker == other.marker
                    && this.getLAS().equals(other.getLAS());
        }
        return false;
    }

    @Override
    public int hashCode() {
        return this.getCore().hashCode() + this.marker + this.getLAS().hashCode();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[ ");
        sb.append(this.getCore().getLHS()).append(" -> ");
        for (int i = 0; i < this.getCore().getRHS().length; i++) {
            if (i == this.marker) {
                sb.append(".");
            }
            sb.append(this.getCore().getRHS()[i]).append(" ");
        }
        if (this.getCore().getRHS().length == this.marker) {
            sb.setCharAt(sb.length() - 1, '.');
            sb.append(" ");
        }
        sb.append("{ ");
        for (final String symbol : this.getLAS().stream().toList()) {
            sb.append(symbol + " ");
        }
        sb.append("} ]");
        return sb.toString();
    }

}

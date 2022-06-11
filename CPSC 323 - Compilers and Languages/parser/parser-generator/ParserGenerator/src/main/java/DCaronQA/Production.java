package DCaronQA;

import java.util.Arrays;

public class Production {

    private int number;
    private String lhs;
    private String[] rhs;

    public Production(final int number, final String lhs, final String[] rhs) {
        this.number = number;
        this.lhs = lhs;
        this.rhs = rhs;
    }

    public int getNumber() {
        return this.number;
    }

    public String[] getRHS() {
        return this.rhs;
    }

    public String getLHS() {
        return this.lhs;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lhs).append(" -> ").append(Util.arrayStringWithSpaces(this.rhs));
        return sb.toString();
    }

    @Override
    public boolean equals(Object o) {
        if (o instanceof Production) {
            Production other = (Production) o;
            return other.getLHS().equals(this.getLHS()) && Arrays.equals(other.getRHS(), this.getRHS());
        }

        return false;
    }

    @Override
    public int hashCode() {
        return Arrays.hashCode(this.getRHS()) + this.getLHS().hashCode();
    }

}

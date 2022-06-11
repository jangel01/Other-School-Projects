package DCaronQA;

public class Util {

    public static String arrayStringWithSpaces(String[] array) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < array.length - 1; i++) {
            sb.append(array[i]).append(' ');
        }
        sb.append(array[array.length - 1]);
        return sb.toString();
    }

}

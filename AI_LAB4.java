import java.util.*;

class CSP {
    boolean CryptArithmetic(String s1, String s2, String s3, HashMap<Character, Integer> map) {
        if (!map.containsValue(-1)) {
            return isSolutionValid(s1, s2, s3, map);
        }

        char unassignedChar = findUnassignedChar(map, s1, s2, s3);
        for (int i = 0; i <= 9; i++) {
            if (!map.containsValue(i) && !(i == 0 && (s1.charAt(0) == unassignedChar || s2.charAt(0) == unassignedChar || s3.charAt(0) == unassignedChar)))
//            if (!map.containsValue(i))
            {
                map.put(unassignedChar, i);
                if (CryptArithmetic(s1, s2, s3, map)) {
                    return true;
                }
                map.put(unassignedChar, -1);
            }
        }

        return false;
    }

    private char findUnassignedChar(HashMap<Character, Integer> map, String s1, String s2, String s3) {
        for (char key : map.keySet()) {
            if (map.get(key) == -1) {
                return key;
            }
        }
        return ' '; // Return a placeholder if no unassigned character is found (should not happen)
    }

    public static boolean isSolutionValid(String s1, String s2, String s3, HashMap<Character, Integer> map) {
        int num1 = evaluate(s1, map);
        int num2 = evaluate(s2, map);
        int num3 = evaluate(s3, map);

        return num3 == num1 + num2;
    }

    public static int evaluate(String s, HashMap<Character, Integer> map) {
        int value = 0;
        for (int i = 0; i < s.length(); i++) {
            value = value * 10 + map.get(s.charAt(i));
        }

        return value;
    }
}

public class AI_LAB4 {
    public static void main(String[] args) {
        String s1 = "point";
        String s2 = "zero";
        String s3 = "energy";


        HashMap<Character, Integer> varMap = new HashMap<>();

        for (int i = 0; i < s1.length(); i++) {
            varMap.put(s1.charAt(i), -1);
        }

        for (int i = 0; i < s2.length(); i++) {
            varMap.put(s2.charAt(i), -1);
        }

        for (int i = 0; i < s3.length(); i++) {
            varMap.put(s3.charAt(i), -1);
        }

        CSP csp = new CSP();
        if (csp.CryptArithmetic(s1, s2, s3, varMap)) {
            System.out.println("Solution exists:");
            for (Character chr : varMap.keySet()) {
                System.out.print(chr + " = " + varMap.get(chr) + " | ");

            }
        } else {
            System.out.println("No solution.");
        }
    }
}

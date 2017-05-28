import java.util.*;
import java.math.BigInteger;

class Main {
    static int N;
    static String W;
    static TreeMap<String, BigInteger> aMap, dpMap;

    static BigInteger dp(String str) {
        BigInteger count = BigInteger.valueOf(0);
        if (str.equals("")) return BigInteger.valueOf(1);
        for (int i = 1; i <= str.length(); i++) {
            String ss = "";
            String rr = "";
            for (int j = 0; j < i; j++) {
                ss += str.charAt(j);
            }
            for (int j = i; j < str.length(); j++) {
                rr += str.charAt(j);
            }
            if (aMap.containsKey(ss)) {
                if (dpMap.containsKey(rr)) count = count.add(aMap.get(ss).multiply(dpMap.get(rr)));
                else count = count.add(aMap.get(ss).multiply(dp(rr)));
            }
        }
        dpMap.put(str, count);
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        W = sc.next();
        aMap = new TreeMap<String, BigInteger>();
        dpMap = new TreeMap<String, BigInteger>();
        while (N > 0) {
            String str = sc.next();
            int i = sc.nextInt();
            BigInteger bi = BigInteger.valueOf(i);
            aMap.put(str, bi);
            N--;
        }
        System.out.println(dp(W).mod(BigInteger.valueOf(1000000007)));
    }
}
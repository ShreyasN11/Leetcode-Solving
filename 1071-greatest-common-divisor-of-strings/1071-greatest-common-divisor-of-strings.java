import java.math.BigInteger;
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int n=str1.length();
        int m=str2.length();
        if(!(str1+str2).equals(str2+str1))
        return "";
        int gcd = BigInteger.valueOf(n).gcd(BigInteger.valueOf(m)).intValue();
        return str1.substring(0,gcd);
    }
}
class Solution {
    boolean vowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    public int maxVowels(String s, int k) {
        int count = 0;
        int n = s.length();
        for(int i=0; i<k; i++){
            count += (vowel(s.charAt(i))) ? 1 : 0;
        }
        int maxi = count;
        for(int i=k; i<n; i++){
            count += (vowel(s.charAt(i))) ? 1 : 0;
            count -= (vowel(s.charAt(i-k))) ? 1 : 0;
            maxi = Math.max(count, maxi);
        }

        return maxi;
    }
}
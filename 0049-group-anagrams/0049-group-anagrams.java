import java.util.*;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {

        Map<String, List<String>> map = new HashMap<>();

        for (String s : strs) {
            // Convert string to character array
            char[] chars = s.toCharArray();

            // Sort characters
            Arrays.sort(chars);

            // Use sorted string as key
            String key = new String(chars);

            // Add original string to its group
            map.putIfAbsent(key, new ArrayList<>());
            map.get(key).add(s);
        }

        return new ArrayList<>(map.values());
    }
}
class Solution {
    public String getPermutation(int n, int k) {

        // Store numbers 1 to n
        List<Integer> numbers = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            numbers.add(i);
        }

        // Convert k to 0-based index
        k--;

        // Factorials
        int factorial = 1;
        for (int i = 1; i < n; i++) {
            factorial *= i;
        }

        StringBuilder result = new StringBuilder();

        for (int i = n; i > 0; i--) {

            // Find which number should be selected
            int index = k / factorial;

            result.append(numbers.get(index));
            numbers.remove(index);

            // Update k
            k %= factorial;

            // Update factorial for next position
            if (i > 1) {
                factorial /= (i - 1);
            }
        }

        return result.toString();
    }
}
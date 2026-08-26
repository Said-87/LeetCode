class Solution {

    private List<List<Integer>> result = new ArrayList<>();

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {

        Arrays.sort(candidates);

        backtrack(candidates, target, 0, new ArrayList<>());

        return result;
    }

    private void backtrack(int[] candidates, int target,
                            int start, List<Integer> current) {

        // Target reached
        if (target == 0) {
            result.add(new ArrayList<>(current));
            return;
        }

        for (int i = start; i < candidates.length; i++) {

            // Skip duplicate values at the same level
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Since array is sorted, no later value will work
            if (candidates[i] > target) {
                break;
            }

            // Choose current number
            current.add(candidates[i]);

            // i + 1 because each number can only be used once
            backtrack(candidates, target - candidates[i],
                      i + 1, current);

            // Backtrack
            current.remove(current.size() - 1);
        }
    }
}
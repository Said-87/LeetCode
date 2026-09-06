import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public String simplifyPath(String path) {
        Deque<String> stack = new ArrayDeque<>();
        
        // Split the path by slashes. 
        // Multiple slashes will result in empty string elements.
        String[] components = path.split("/");
        
        for (String dir : components) {
            if (dir.equals("..")) {
                // Go up one level if we aren't already at the root
                if (!stack.isEmpty()) {
                    stack.removeLast();
                }
            } else if (!dir.equals(".") && !dir.isEmpty()) {
                // A valid directory name (including "...", "....", etc.)
                stack.addLast(dir);
            }
        }
        
        // Reconstruct the path from the stack
        return "/" + String.join("/", stack);
    }
}
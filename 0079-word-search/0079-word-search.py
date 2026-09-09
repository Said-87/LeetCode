from collections import Counter

class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        L = len(word)
        
        # Quick length check
        if L > m * n:
            return False
        
        # Character count frequency check
        board_counts = Counter(char for row in board for char in row)
        word_counts = Counter(word)
        
        for char, count in word_counts.items():
            if board_counts[char] < count:
                return False
        
        # Optimization: Start from the rarer end of the word
        if board_counts[word[0]] > board_counts[word[-1]]:
            word = word[::-1]
            
        def dfs(r: int, c: int, k: int) -> bool:
            if k == L:
                return True
            
            # Boundary check and character match
            if not (0 <= r < m and 0 <= c < n) or board[r][c] != word[k]:
                return False
            
            # Mark current cell as visited
            temp = board[r][c]
            board[r][c] = '#'
            
            # Explore all 4 orthogonal directions
            found = (
                dfs(r + 1, c, k + 1) or
                dfs(r - 1, c, k + 1) or
                dfs(r, c + 1, k + 1) or
                dfs(r, c - 1, k + 1)
            )
            
            # Backtrack
            board[r][c] = temp
            return found

        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0] and dfs(i, j, 0):
                    return True

        return False
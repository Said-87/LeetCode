class Solution:
    def solveSudoku(self, board):

        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]

        for r in range(9):
            for c in range(9):
                num = board[r][c]

                if num != ".":
                    rows[r].add(num)
                    cols[c].add(num)
                    boxes[(r // 3) * 3 + (c // 3)].add(num)

        def backtrack():

            best_cell = None
            best_candidates = None

            # Find the empty cell with the fewest candidates
            for r in range(9):
                for c in range(9):

                    if board[r][c] != ".":
                        continue

                    box = (r // 3) * 3 + (c // 3)

                    candidates = []

                    for num in "123456789":
                        if (num not in rows[r] and
                            num not in cols[c] and
                            num not in boxes[box]):
                            candidates.append(num)

                    # No possible number
                    if not candidates:
                        return False

                    # Most constrained cell
                    if best_candidates is None or len(candidates) < len(best_candidates):
                        best_cell = (r, c, box)
                        best_candidates = candidates

                        # Can't get better than one candidate
                        if len(candidates) == 1:
                            break

                if best_candidates is not None and len(best_candidates) == 1:
                    break

            # No empty cells = solved
            if best_cell is None:
                return True

            r, c, box = best_cell

            for num in best_candidates:

                board[r][c] = num
                rows[r].add(num)
                cols[c].add(num)
                boxes[box].add(num)

                if backtrack():
                    return True

                # Backtrack
                board[r][c] = "."
                rows[r].remove(num)
                cols[c].remove(num)
                boxes[box].remove(num)

            return False

        backtrack()
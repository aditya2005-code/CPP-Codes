from collections import deque

def in_bounds(r, c, M, N):
    return 0 <= r < M and 0 <= c < N

def can_place(cells, grid, M, N):
    for r, c in cells:
        if not in_bounds(r, c, M, N) or grid[r][c] == 'B':
            return False
    return True

def bounding_square_ok(old_cells, new_cells, grid, M, N):
    all_cells = list(old_cells) + list(new_cells)
    rs = [r for r, _ in all_cells]
    cs = [c for _, c in all_cells]
    k = len(old_cells)
    rmin, rmax = min(rs), max(rs)
    cmin, cmax = min(cs), max(cs)
    if (rmax - rmin != k - 1) or (cmax - cmin != k - 1):
        return False
    return True

def generate_rotations(cells, grid, M, N):
    k = len(cells)
    rows = [r for r, _ in cells]
    horizontal = all(r == rows[0] for r in rows)
    rotations = []
    if horizontal:
        for r in range(M - k + 1):
            new = tuple(sorted((r + i, cells[0][1]) for i in range(k)))
            if can_place(new, grid, M, N) and bounding_square_ok(cells, new, grid, M, N):
                rotations.append(new)
    else:
        for c in range(N - k + 1):
            new = tuple(sorted((cells[0][0], c + i) for i in range(k)))
            if can_place(new, grid, M, N) and bounding_square_ok(cells, new, grid, M, N):
                rotations.append(new)
    return rotations

def neighbors_translate(cells, M, N):
    for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        nxt = tuple(sorted((r + dr, c + dc) for r, c in cells))
        if all(in_bounds(r, c, M, N) for r, c in nxt):
            yield nxt

def min_steps(grid, M, N, start_cells, target_cells):
    start = tuple(sorted(start_cells))
    target = tuple(sorted(target_cells))
    if start == target:
        return 0
    q = deque([(start, 0)])
    visited = {start}
    while q:
        cur, dist = q.popleft()
        for nxt in neighbors_translate(cur, M, N):
            if nxt not in visited and can_place(nxt, grid, M, N):
                if nxt == target:
                    return dist + 1
                visited.add(nxt)
                q.append((nxt, dist + 1))
        for rot in generate_rotations(cur, grid, M, N):
            if rot not in visited:
                if rot == target:
                    return dist + 1
                visited.add(rot)
                q.append((rot, dist + 1))
    return None

def find_cells(grid, ch):
    return [(i, j) for i in range(len(grid)) for j in range(len(grid[0])) if grid[i][j] == ch]

if __name__ == "__main__":
    M, N = map(int, input().split())
    grid = [list(input().strip()) for _ in range(M)]
    start = find_cells(grid, 'L')
    target = find_cells(grid, 'T')
    res = min_steps(grid, M, N, start, target)
    print(res if res is not None else "Impossible", end="")

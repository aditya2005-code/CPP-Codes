"""
Task 3 (Hard): Find All Keys in Cycles

Write a function `keys_in_cycles(d)` that takes a dictionary where each key and value are strings.
Return a set of all keys that are part of any cycle in the dictionary.

A cycle is a sequence of keys k1, k2, ..., kn such that d[k1]=k2, d[k2]=k3, ..., d[kn]=k1.

Example:
    keys_in_cycles({'a': 'b', 'b': 'c', 'c': 'a', 'd': 'e'}) -> {'a', 'b', 'c'}
    keys_in_cycles({'x': 'y', 'y': 'z', 'z': 'x', 'a': 'b'}) -> {'x', 'y', 'z'}
    keys_in_cycles({'a': 'b', 'b': 'c', 'c': 'd'}) -> set()
"""

def keys_in_cycles(d):
    """
    Returns a set of all keys that are part of any cycle in the dictionary.

    Args:
        d (dict): Dictionary with string keys and values.

    Returns:
        set: Set of keys in cycles.
    """
    result = set()

    for start in d:
        current = start
        path = {}
        
        while current in d:
            if current in path:
                # A cycle has been found.
                cycle_start = current

                while True:
                    result.add(current)
                    current = d[current]

                    if current == cycle_start:
                        break

                break

            if current in result:
                break

            path[current] = True
            current = d[current]

    return result
